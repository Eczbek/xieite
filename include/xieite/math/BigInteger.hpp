#ifndef XIEITE_HEADER__MATH__BIG_INTEGER
#	define XIEITE_HEADER__MATH__BIG_INTEGER

#	include <algorithm>
#	include <compare>
#	include <concepts>
#	include <cstddef>
#	include <cstdint>
#	include <iterator>
#	include <limits>
#	include <ranges>
#	include <stdexcept>
#	include <string>
#	include <string_view>
#	include <vector>
#	include "../concepts/Arithmetic.hpp"
#	include "../math/AttemptUnsign.hpp"
#	include "../math/Product.hpp"
#	include "../math/digits.hpp"
#	include "../math/multiply.hpp"
#	include "../math/negative.hpp"
#	include "../math/splitBoolean.hpp"
#	include "../strings/lowercase.hpp"
#	include "../system/byteBits.hpp"

namespace xieite::math {
	template<std::unsigned_integral Datum = std::uint64_t>
	class BigInteger {
	public:
		template<std::integral Integer = int>
		constexpr BigInteger(const Integer value = 0) noexcept
		: negative(xieite::math::negative(value)) {
			xieite::math::AttemptUnsign<Integer> absoluteValue = xieite::math::absolute(value);
			do {
				this->data.push_back(static_cast<Datum>(absoluteValue));
				if constexpr (sizeof(Integer) > sizeof(Datum)) {
					absoluteValue >>= std::numeric_limits<Datum>::digits;
				} else {
					break;
				}
			} while (absoluteValue);
		}

		template<typename OtherDatum>
		constexpr BigInteger(const xieite::math::BigInteger<OtherDatum> value) noexcept
		: negative(value.negative) {
			if constexpr (sizeof(Datum) == sizeof(OtherDatum)) {
				this->data = value.data;
				return;
			}
			if (sizeof(Datum) > sizeof(OtherDatum)) {
				std::size_t shiftBytes = sizeof(Datum);
				for (const OtherDatum otherDatum : value.data) {
					if (shiftBytes >= sizeof(Datum)) {
						shiftBytes = 0;
						this->data.push_back(0);
					}
					this->data.back() |= otherDatum << (shiftBytes * xieite::system::byteBits);
					shiftBytes += sizeof(OtherDatum);
				}
				return;
			}
			for (const OtherDatum otherDatum : value.data) {
				std::size_t shiftBytes = 0;
				do {
					this->data.push_back(static_cast<Datum>(otherDatum >> (shiftBytes * xieite::system::byteBits)));
					shiftBytes += sizeof(Datum);
				} while (shiftBytes < sizeof(OtherDatum));
			}
			this->trim();
		}

		template<std::ranges::range Range>
		requires(std::same_as<Datum, std::ranges::range_value_t<Range>>)
		constexpr BigInteger(const Range& range, const bool negative = false) noexcept
		: data(range.begin(), range.end()), negative(negative) {
			this->trim();
		}

		constexpr BigInteger(const std::string_view value, const int radix = 10, const std::string_view digits = "0123456789abcdefghijklmnopqrstuvwxyz", const char negativeSign = '-', const bool caseSensitive = false) noexcept
		: data({ 0 }), negative(false) {
			const std::size_t valueSize = value.size();
			if (!valueSize || !radix) {
				return;
			}
			const bool valueNegative = value[0] == negativeSign;
			const std::string usedDigits = caseSensitive ? std::string(digits) : xieite::strings::lowercase(digits);
			xieite::math::BigInteger<Datum> power = 1;
			for (std::size_t i = valueSize; i-- > valueNegative;) {
				const std::size_t index = usedDigits.find(caseSensitive ? value[i] : xieite::strings::lowercase(value[i]));
				*this += power * index * (index != std::string::npos);
				power *= radix;
			}
			if (*this) {
				this->negative = valueNegative;
			}
		}

		constexpr xieite::math::BigInteger<Datum>& operator=(const xieite::math::BigInteger<Datum>& value) noexcept {
			this->data = value.data;
			this->negative = value.negative;
			return *this;
		}

		template<std::integral Integer>
		constexpr xieite::math::BigInteger<Datum>& operator=(const Integer value) noexcept {
			return *this = xieite::math::BigInteger<Datum>(value);
		}

		template<std::integral Integer>
		[[nodiscard]] constexpr operator Integer() const noexcept {
			Integer result = 0;
			const std::size_t dataSize = this->data.size();
			for (std::size_t i = 0; i < dataSize; ++i) {
				result |= static_cast<Integer>(this->data[i]) << (static_cast<Integer>(i) * std::numeric_limits<Datum>::digits);
			}
			return this->negative ? -result : result;
		}

		[[nodiscard]] constexpr operator bool() const noexcept {
			return (this->data.size() > 1) || this->data[0];
		}

		[[nodiscard]] friend constexpr std::strong_ordering operator<=>(const xieite::math::BigInteger<Datum>& leftComparand, const xieite::math::BigInteger<Datum>& rightComparand) noexcept {
			return (leftComparand.negative != rightComparand.negative) ? (rightComparand.negative <=> leftComparand.negative) : (leftComparand.negative ? ((leftComparand.data.size() != rightComparand.data.size()) ? (rightComparand.data.size() <=> leftComparand.data.size()) : std::lexicographical_compare_three_way(rightComparand.data.rbegin(), rightComparand.data.rend(), leftComparand.data.rbegin(), leftComparand.data.rend())) : ((leftComparand.data.size() != rightComparand.data.size()) ? (leftComparand.data.size() <=> rightComparand.data.size()) : std::lexicographical_compare_three_way(leftComparand.data.rbegin(), leftComparand.data.rend(), rightComparand.data.rbegin(), rightComparand.data.rend())));
		};

		template<std::integral Integer>
		[[nodiscard]] friend constexpr std::strong_ordering operator<=>(const xieite::math::BigInteger<Datum>& leftComparand, const Integer rightComparand) noexcept {
			return leftComparand <=> xieite::math::BigInteger<Datum>(rightComparand);
		}

		[[nodiscard]] friend constexpr bool operator==(const xieite::math::BigInteger<Datum>& leftComparand, const xieite::math::BigInteger<Datum>& rightComparand) noexcept {
			return std::is_eq(leftComparand <=> rightComparand);
		}

		template<std::integral Integer>
		[[nodiscard]] friend constexpr bool operator==(const xieite::math::BigInteger<Datum>& leftComparand, const Integer rightComparand) noexcept {
			return leftComparand == xieite::math::BigInteger<Datum>(rightComparand);
		}

		[[nodiscard]] constexpr xieite::math::BigInteger<Datum> operator+() const noexcept {
			return *this;
		}

		[[nodiscard]] friend constexpr xieite::math::BigInteger<Datum> operator+(const xieite::math::BigInteger<Datum>& augend, const xieite::math::BigInteger<Datum>& addend) noexcept {
			if (!augend) {
				return addend;
			}
			if (!addend) {
				return augend;
			}
			if (augend.negative != addend.negative) {
				return augend - (-addend);
			}
			std::vector<Datum> resultData;
			bool carry = false;
			const std::size_t augendDataSize = augend.data.size();
			const std::size_t addendDataSize = addend.data.size();
			for (std::size_t i = 0; (i < augendDataSize) || (i < addendDataSize) || carry; ++i) {
				const Datum augendDatum = (i < augendDataSize) ? augend.data[i] : 0;
				const Datum addendDatum = (i < addendDataSize) ? addend.data[i] : 0;
				resultData.push_back(augendDatum + addendDatum + carry);
				carry = (std::numeric_limits<Datum>::max() - augendDatum < carry) || (std::numeric_limits<Datum>::max() - augendDatum < addendDatum) || (std::numeric_limits<Datum>::max() - augendDatum - carry < addendDatum);
			}
			return xieite::math::BigInteger<Datum>(resultData, augend.negative);
		}

		template<std::integral Integer>
		[[nodiscard]] friend constexpr xieite::math::BigInteger<Datum> operator+(const xieite::math::BigInteger<Datum>& augend, const Integer addend) noexcept {
			return augend + xieite::math::BigInteger<Datum>(addend);
		}

		constexpr xieite::math::BigInteger<Datum>& operator+=(const xieite::math::BigInteger<Datum>& addend) noexcept {
			return *this = *this + addend;
		}

		template<std::integral Integer>
		constexpr xieite::math::BigInteger<Datum>& operator+=(const Integer addend) noexcept {
			return *this += xieite::math::BigInteger<Datum>(addend);
		}

		constexpr xieite::math::BigInteger<Datum>& operator++() noexcept {
			return *this += 1;
		}

		constexpr xieite::math::BigInteger<Datum> operator++(int) noexcept {
			xieite::math::BigInteger<Datum> copy = *this;
			++*this;
			return copy;
		}

		[[nodiscard]] constexpr xieite::math::BigInteger<Datum> operator-() const noexcept {
			xieite::math::BigInteger<Datum> copy = *this;
			if (copy) {
				copy.negative = !copy.negative;
			}
			return copy;
		}

		[[nodiscard]] friend constexpr xieite::math::BigInteger<Datum> operator-(const xieite::math::BigInteger<Datum>& minuend, const xieite::math::BigInteger<Datum>& subtrahend) noexcept {
			if (!subtrahend) {
				return minuend;
			}
			if (!minuend) {
				return -subtrahend;
			}
			if (minuend.negative != subtrahend.negative) {
				return minuend + (-subtrahend);
			}
			if (minuend.negative ? (minuend > subtrahend) : (minuend < subtrahend)) {
				return -(subtrahend - minuend);
			}
			if (minuend == subtrahend) {
				return 0;
			}
			std::vector<Datum> resultData;
			bool borrow = false;
			const std::size_t minuendDataSize = minuend.data.size();
			const std::size_t subtrahendDataSize = subtrahend.data.size();
			for (std::size_t i = 0; (i < subtrahendDataSize) || borrow; ++i) {
				const Datum subtrahendDatum = (i < subtrahendDataSize) ? subtrahend.data[i] : 0;
				resultData.push_back(minuend.data[i] - subtrahendDatum - borrow);
				borrow = (i < minuendDataSize - 1) && ((minuend.data[i] < borrow) || (minuend.data[i] < subtrahendDatum) || ((minuend.data[i] - borrow) < subtrahendDatum));
			}
			return xieite::math::BigInteger<Datum>(resultData, minuend.negative);
		}

		template<std::integral Integer>
		[[nodiscard]] friend constexpr xieite::math::BigInteger<Datum> operator-(const xieite::math::BigInteger<Datum>& minuend, const Integer subtrahend) noexcept {
			return minuend - xieite::math::BigInteger<Datum>(subtrahend);
		}

		constexpr xieite::math::BigInteger<Datum>& operator-=(const xieite::math::BigInteger<Datum>& subtrahend) noexcept {
			return *this = *this - subtrahend;
		}

		template<std::integral Integer>
		constexpr xieite::math::BigInteger<Datum>& operator-=(const Integer subtrahend) noexcept {
			return *this -= xieite::math::BigInteger<Datum>(subtrahend);
		}

		constexpr xieite::math::BigInteger<Datum>& operator--() noexcept {
			return *this -= 1;
		}

		constexpr xieite::math::BigInteger<Datum>& operator--(int) noexcept {
			xieite::math::BigInteger<Datum> copy = *this;
			--*this;
			return copy;
		}

		[[nodiscard]] friend constexpr xieite::math::BigInteger<Datum> operator*(const xieite::math::BigInteger<Datum>& multiplier, const xieite::math::BigInteger<Datum>& multiplicand) noexcept {
			if (!multiplier || !multiplicand) {
				return 0;
			}
			const bool sameSign = multiplier.negative == multiplicand.negative;
			if ((multiplier == 1) || (multiplier == -1)) {
				return sameSign ? multiplicand : -multiplicand;
			}
			if ((multiplicand == 1) || (multiplicand == -1)) {
				return sameSign ? multiplier : -multiplier;
			}
			if ((multiplier == 2) || (multiplier == -2)) {
				return sameSign ? (multiplicand << 1) : -(multiplicand << 1);
			}
			if ((multiplicand == 2) || (multiplicand == -2)) {
				return sameSign ? (multiplier << 1) : -(multiplier << 1);
			}
			xieite::math::BigInteger<Datum> result;
			for (std::size_t i = multiplier.data.size(); i--;) {
				if (!multiplier.data[i]) {
					continue;
				}
				for (std::size_t j = multiplicand.data.size(); j--;) {
					if (!multiplicand.data[j]) {
						continue;
					}
					const xieite::math::Product<Datum> product = xieite::math::multiply<Datum>(multiplier.data[i], multiplicand.data[j]);
					result += ((xieite::math::BigInteger<Datum>(product.upper) << std::numeric_limits<Datum>::digits) | product.lower) << (xieite::math::BigInteger<Datum>(i) << xieite::math::digits(std::numeric_limits<Datum>::digits - 1, 2)) << (xieite::math::BigInteger<Datum>(j) << xieite::math::digits(std::numeric_limits<Datum>::digits - 1, 2));
				}
			}
			result.negative = !sameSign;
			return result;
		}

		template<std::integral Integer>
		[[nodiscard]] friend constexpr xieite::math::BigInteger<Datum> operator*(const xieite::math::BigInteger<Datum>& multiplier, const Integer multiplicand) noexcept {
			return multiplier * xieite::math::BigInteger<Datum>(multiplicand);
		}

		constexpr xieite::math::BigInteger<Datum>& operator*=(const xieite::math::BigInteger<Datum>& multiplicand) noexcept {
			return *this = *this * multiplicand;
		}

		template<std::integral Integer>
		constexpr xieite::math::BigInteger<Datum>& operator*=(const Integer multiplicand) noexcept {
			return *this *= xieite::math::BigInteger<Datum>(multiplicand);
		}

		[[nodiscard]] friend constexpr xieite::math::BigInteger<Datum> operator/(const xieite::math::BigInteger<Datum>& dividend, const xieite::math::BigInteger<Datum>& divisor) {
			if (!divisor) {
				throw std::domain_error("Cannot divide by zero");
			}
			const bool sameSign = dividend.negative == divisor.negative;
			if ((divisor == 1) || (divisor == -1)) {
				return sameSign ? dividend : -dividend;
			}
			if ((divisor == 2) || (divisor == -2)) {
				return sameSign ? (dividend >> 1) : -(dividend >> 1);
			}
			const xieite::math::BigInteger<Datum> absoluteDividend = dividend.absolute();
			const xieite::math::BigInteger<Datum> absoluteDivisor = divisor.absolute();
			if (!dividend || (absoluteDividend < absoluteDivisor)) {
				return 0;
			}
			if (absoluteDividend == absoluteDivisor) {
				return xieite::math::splitBoolean(sameSign);
			}
			xieite::math::BigInteger<Datum> remainder;
			xieite::math::BigInteger<Datum> result;
			remainder.data.resize(dividend.data.size(), 0);
			result.data.resize(dividend.data.size(), 0);
			for (std::size_t i = dividend.data.size(); i--;) {
				for (std::size_t j = std::numeric_limits<Datum>::digits; j--;) {
					remainder <<= 1;
					remainder.data[0] |= (dividend.data[i] >> j) & 1;
					const bool quotient = remainder >= absoluteDivisor;
					remainder -= absoluteDivisor * quotient;
					result.data[i] |= static_cast<Datum>(quotient) << j;
				}
			}
			result.negative = !sameSign;
			result.trim();
			return result;
		}

		template<std::integral Integer>
		[[nodiscard]] friend constexpr xieite::math::BigInteger<Datum> operator/(const xieite::math::BigInteger<Datum>& dividend, const Integer divisor) {
			return dividend / xieite::math::BigInteger<Datum>(divisor);
		}

		constexpr xieite::math::BigInteger<Datum>& operator/=(const xieite::math::BigInteger<Datum>& divisor) {
			return *this = *this / divisor;
		}

		template<std::integral Integer>
		constexpr xieite::math::BigInteger<Datum>& operator/=(const Integer divisor) {
			return *this /= xieite::math::BigInteger<Datum>(divisor);
		}

		[[nodiscard]] friend constexpr xieite::math::BigInteger<Datum> operator%(const xieite::math::BigInteger<Datum>& dividend, const xieite::math::BigInteger<Datum>& divisor) {
			if (!divisor) {
				throw std::domain_error("Cannot take modulus of division by zero");
			}
			const xieite::math::BigInteger<Datum> absoluteDividend = dividend.absolute();
			const xieite::math::BigInteger<Datum> absoluteDivisor = divisor.absolute();
			if (!dividend || (absoluteDivisor == 1) || (absoluteDividend == absoluteDivisor)) {
				return 0;
			}
			if (absoluteDivisor == 2) {
				return (dividend.data[0] & 1) * xieite::math::splitBoolean(!dividend.negative);
			}
			if (absoluteDividend < absoluteDivisor) {
				return dividend;
			}
			xieite::math::BigInteger<Datum> remainder;
			for (const Datum dividendDatum : std::views::reverse(dividend.data)) {
				for (std::size_t j = std::numeric_limits<Datum>::digits; j--;) {
					remainder <<= 1;
					remainder.data[0] |= (dividendDatum >> j) & 1;
					remainder -= absoluteDivisor * (remainder >= absoluteDivisor);
				}
			}
			remainder.negative = dividend.negative;
			return remainder;
		}

		template<std::integral Integer>
		[[nodiscard]] friend constexpr xieite::math::BigInteger<Datum> operator%(const xieite::math::BigInteger<Datum>& dividend, const Integer divisor) {
			return dividend % xieite::math::BigInteger<Datum>(divisor);
		}

		constexpr xieite::math::BigInteger<Datum>& operator%=(const xieite::math::BigInteger<Datum>& divisor) {
			return *this = *this % divisor;
		}

		template<std::integral Integer>
		constexpr xieite::math::BigInteger<Datum>& operator%=(const Integer divisor) {
			return *this %= xieite::math::BigInteger<Datum>(divisor);
		}

		[[nodiscard]] constexpr xieite::math::BigInteger<Datum> operator~() const noexcept {
			return -(*this + 1);
		}

		[[nodiscard]] friend constexpr xieite::math::BigInteger<Datum> operator&(const xieite::math::BigInteger<Datum>& leftOperand, const xieite::math::BigInteger<Datum>& rightOperand) noexcept {
			return xieite::math::BigInteger<Datum>::bitwiseOperation(leftOperand, rightOperand, [](const Datum left, const Datum right) -> Datum {
				return left & right;
			});
		}

		template<std::integral Integer>
		[[nodiscard]] friend constexpr xieite::math::BigInteger<Datum> operator&(const xieite::math::BigInteger<Datum>& leftOperand, const Integer rightOperand) noexcept {
			return leftOperand & xieite::math::BigInteger<Datum>(rightOperand);
		}

		constexpr xieite::math::BigInteger<Datum>& operator&=(const xieite::math::BigInteger<Datum>& operand) noexcept {
			return *this = *this & operand;
		}

		template<std::integral Integer>
		constexpr xieite::math::BigInteger<Datum>& operator&=(const Integer operand) noexcept {
			return *this &= xieite::math::BigInteger<Datum>(operand);
		}

		[[nodiscard]] friend constexpr xieite::math::BigInteger<Datum> operator|(const xieite::math::BigInteger<Datum>& leftOperand, const xieite::math::BigInteger<Datum>& rightOperand) noexcept {
			return xieite::math::BigInteger<Datum>::bitwiseOperation(leftOperand, rightOperand, [](const Datum left, const Datum right) -> Datum {
				return left | right;
			});
		}

		template<std::integral Integer>
		[[nodiscard]] friend constexpr xieite::math::BigInteger<Datum> operator|(const xieite::math::BigInteger<Datum>& leftOperand, const Integer rightOperand) noexcept {
			return leftOperand | xieite::math::BigInteger<Datum>(rightOperand);
		}

		constexpr xieite::math::BigInteger<Datum>& operator|=(const xieite::math::BigInteger<Datum>& operand) noexcept {
			return *this = *this | operand;
		}

		template<std::integral Integer>
		constexpr xieite::math::BigInteger<Datum>& operator|=(const Integer operand) noexcept {
			return *this |= xieite::math::BigInteger<Datum>(operand);
		}

		[[nodiscard]] friend constexpr xieite::math::BigInteger<Datum> operator^(const xieite::math::BigInteger<Datum>& leftOperand, const xieite::math::BigInteger<Datum>& rightOperand) noexcept {
			return xieite::math::BigInteger<Datum>::bitwiseOperation(leftOperand, rightOperand, [](const Datum left, const Datum right) -> Datum {
				return left ^ right;
			});
		}

		template<std::integral Integer>
		[[nodiscard]] friend constexpr xieite::math::BigInteger<Datum> operator^(const xieite::math::BigInteger<Datum>& leftOperand, const Integer rightOperand) noexcept {
			return leftOperand ^ xieite::math::BigInteger<Datum>(rightOperand);
		}

		constexpr xieite::math::BigInteger<Datum>& operator^=(const xieite::math::BigInteger<Datum>& operand) noexcept {
			return *this = *this ^ operand;
		}

		template<std::integral Integer>
		constexpr xieite::math::BigInteger<Datum>& operator^=(const Integer operand) noexcept {
			return *this ^= xieite::math::BigInteger<Datum>(operand);
		}

		[[nodiscard]] friend constexpr xieite::math::BigInteger<Datum> operator<<(const xieite::math::BigInteger<Datum>& leftOperand, const xieite::math::BigInteger<Datum>& rightOperand) noexcept {
			if (!leftOperand || !rightOperand) {
				return leftOperand;
			}
			if (rightOperand.negative) {
				return leftOperand >> -rightOperand;
			}
			const std::size_t dataShift = rightOperand / std::numeric_limits<Datum>::digits;
			const std::size_t bitsShift = rightOperand % std::numeric_limits<Datum>::digits;
			std::vector<Datum> resultData = std::vector<Datum>(dataShift, 0);
			resultData.insert(resultData.end(), leftOperand.data.begin(), leftOperand.data.end());
			if (bitsShift) {
				Datum carry = 0;
				const std::size_t leftDataSize = leftOperand.data.size();
				for (std::size_t i = 0; i < leftDataSize; ++i) {
					resultData[i + dataShift] = (leftOperand.data[i] << bitsShift) | carry;
					carry = leftOperand.data[i] >> (std::numeric_limits<Datum>::digits - bitsShift);
				}
				if (carry) {
					resultData.push_back(carry);
				}
			}
			return xieite::math::BigInteger<Datum>(resultData, leftOperand.negative);
		}

		template<std::integral Integer>
		[[nodiscard]] friend constexpr xieite::math::BigInteger<Datum> operator<<(const xieite::math::BigInteger<Datum>& leftOperand, const Integer rightOperand) noexcept {
			return leftOperand << xieite::math::BigInteger<Datum>(rightOperand);
		}

		constexpr xieite::math::BigInteger<Datum>& operator<<=(const xieite::math::BigInteger<Datum>& operand) noexcept {
			return *this = *this << operand;
		}

		template<std::integral Integer>
		constexpr xieite::math::BigInteger<Datum>& operator<<=(const Integer operand) noexcept {
			return *this <<= xieite::math::BigInteger<Datum>(operand);
		}

		[[nodiscard]] friend constexpr xieite::math::BigInteger<Datum> operator>>(const xieite::math::BigInteger<Datum>& leftOperand, const xieite::math::BigInteger<Datum>& rightOperand) noexcept {
			if (!leftOperand || !rightOperand) {
				return leftOperand;
			}
			if (rightOperand.negative) {
				return leftOperand >> -rightOperand;
			}
			const std::size_t dataShift = rightOperand / std::numeric_limits<Datum>::digits;
			const std::size_t bitsShift = rightOperand % std::numeric_limits<Datum>::digits;
			const std::size_t leftDataSize = leftOperand.data.size();
			if (dataShift >= leftDataSize) {
				return 0;
			}
			std::vector<Datum> resultData = std::vector<Datum>(std::ranges::next(leftOperand.data.begin(), dataShift, leftOperand.data.end()), leftOperand.data.end());
			if (bitsShift) {
				Datum carry = 0;
				for (Datum& resultDatum : std::views::reverse(resultData)) {
					const Datum copy = resultDatum;
					resultDatum = (copy >> bitsShift) | carry;
					carry = copy << (std::numeric_limits<Datum>::digits - bitsShift);
				}
			}
			return xieite::math::BigInteger<Datum>(resultData, leftOperand.negative);
		}

		template<std::integral Integer>
		[[nodiscard]] friend constexpr xieite::math::BigInteger<Datum> operator>>(const xieite::math::BigInteger<Datum>& leftOperand, const Integer rightOperand) noexcept {
			return leftOperand >> xieite::math::BigInteger<Datum>(rightOperand);
		}

		constexpr xieite::math::BigInteger<Datum>& operator>>=(const xieite::math::BigInteger<Datum>& operand) noexcept {
			return *this = *this >> operand;
		}

		template<std::integral Integer>
		constexpr xieite::math::BigInteger<Datum>& operator>>=(const Integer operand) noexcept {
			return *this >>= xieite::math::BigInteger<Datum>(operand);
		}

		[[nodiscard]] constexpr xieite::math::BigInteger<Datum> absolute() const noexcept {
			xieite::math::BigInteger<Datum> copy = *this;
			copy.negative = false;
			return copy;
		}

		[[nodiscard]] constexpr xieite::math::BigInteger<Datum> power(const xieite::math::BigInteger<Datum>& exponent) const {
			if ((*this == 1) || (exponent == 1)) {
				return *this;
			}
			if (*this == -1) {
				return *this * xieite::math::splitBoolean(exponent % 2);
			}
			if (!exponent) {
				return 1;
			}
			if (!*this) {
				if (exponent.negative) {
					throw std::domain_error("Cannot take power of zero to negative exponent");
				}
				return !exponent;
			}
			xieite::math::BigInteger<Datum> foo = *this;
			xieite::math::BigInteger<Datum> bar = 1;
			xieite::math::BigInteger<Datum> baz = exponent;
			while (baz > 1) {
				if (baz % 2) {
					bar *= foo;
					baz = (baz - 1) / 2;
				} else {
					baz /= 2;
				}
				foo *= foo;
			}
			return foo * bar;
		}

		template<std::integral Integer>
		[[nodiscard]] constexpr xieite::math::BigInteger<Datum> power(const Integer exponent) const {
			return this->power(xieite::math::BigInteger<Datum>(exponent));
		}

		[[nodiscard]] constexpr xieite::math::BigInteger<Datum> root(const xieite::math::BigInteger<Datum>& degree) const {
			if (this->negative) {
				throw std::domain_error("Cannot take root of negative radicand");
			}
			if (*this == 1) {
				return *this;
			}
			if (degree.negative) {
				return 0;
			}
			xieite::math::BigInteger<Datum> foo = degree - 1;
			xieite::math::BigInteger<Datum> bar = *this;
			xieite::math::BigInteger<Datum> baz = bar + 1;
			while (bar < baz) {
				baz = bar;
				bar = (foo * bar + *this / bar.power(foo)) / degree;
			}
			return baz;
		}

		template<std::integral Integer>
		[[nodiscard]] constexpr xieite::math::BigInteger<Datum> root(const Integer degree) const {
			return this->root(xieite::math::BigInteger<Datum>(degree));
		}

		[[nodiscard]] constexpr xieite::math::BigInteger<Datum> logarithm(const xieite::math::BigInteger<Datum>& base) const {
			if (!base) {
				return base;
			}
			if (this->negative) {
				throw std::domain_error("Cannot take logarithm of negative anti-logarithm");
			}
			if (base == 1) {
				throw std::domain_error("Cannot take logarithm of first base");
			}
			if (base.negative) {
				throw std::domain_error("Cannot take logarithm of negative base");
			}
			return (xieite::math::BigInteger<Datum>(std::numeric_limits<Datum>::digits) * (this->data.size() - 1) + xieite::math::digits(this->data.back(), 2) - 1) / (xieite::math::BigInteger<Datum>(std::numeric_limits<Datum>::digits) * (base.data.size() - 1) + xieite::math::digits(base.data.back(), 2) - 1);
		}

		template<std::integral Integer>
		[[nodiscard]] constexpr xieite::math::BigInteger<Datum> logarithm(const Integer base) const {
			return this->logarithm(xieite::math::BigInteger<Datum>(base));
		}

		[[nodiscard]] constexpr std::string string(const int radix = 10, const std::string_view digits = "0123456789abcdefghijklmnopqrstuvwxyz", const char negativeSign = '-', const bool caseSensitive = false) const noexcept {
			if (!radix || !*this) {
				return std::string(1, digits[0]);
			}
			std::string result;
			xieite::math::BigInteger<Datum> absolute = this->absolute();
			std::size_t absoluteValue = absolute;
			if (radix == 1) {
				result = std::string(absoluteValue, digits[1]);
			} else if (radix == -1) {
				result = digits[1];
				while (absoluteValue-- > 1) {
					result += std::string(1, digits[0]) + digits[1];
				}
			} else {
				while (absolute) {
					const std::size_t index = absolute % radix;
					result = digits[index * (index < digits.size())] + result;
					absolute /= radix;
				}
			}
			if (this->negative) {
				result = negativeSign + result;
			}
			return result;
		}

	private:
		std::vector<Datum> data;
		bool negative;

		template<typename Functor>
		[[nodiscard]] static constexpr xieite::math::BigInteger<Datum> bitwiseOperation(xieite::math::BigInteger<Datum> leftOperand, xieite::math::BigInteger<Datum> rightOperand, const Functor& callback) {
			const bool leftNegative = leftOperand.negative;
			const bool rightNegative = rightOperand.negative;
			leftOperand += leftNegative;
			rightOperand += rightNegative;
			const std::size_t leftDataSize = leftOperand.data.size();
			const std::size_t rightDataSize = rightOperand.data.size();
			xieite::math::BigInteger<Datum> result;
			result.data.clear();
			result.negative = leftNegative && rightNegative;
			for (std::size_t i = 0; (i < leftDataSize) || (i < rightDataSize); ++i) {
				const Datum datum = callback(((i < leftDataSize) ? (leftNegative ? ~leftOperand.data[i] : leftOperand.data[i]) : (std::numeric_limits<Datum>::max() * leftOperand.negative)), ((i < rightDataSize) ? (rightNegative ? ~rightOperand.data[i] : rightOperand.data[i]) : (std::numeric_limits<Datum>::max() * rightNegative)));
				result.data.push_back(result.negative ? ~datum : datum);
			}
			return result - result.negative;
		}

		constexpr void trim() noexcept {
			std::size_t dataSize = this->data.size();
			while ((dataSize > 1) && !this->data.back()) {
				this->data.pop_back();
				--dataSize;
			}
			if (!dataSize) {
				this->data.push_back(0);
			}
			if (!*this) {
				this->negative = false;
			}
		}
	};
}

// Thanks to sam_dev for help with division

#endif
