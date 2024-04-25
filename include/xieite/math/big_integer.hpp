#ifndef XIEITE_HEADER_MATH_BIG_INTEGER
#	define XIEITE_HEADER_MATH_BIG_INTEGER

#	include <algorithm>
#	include <compare>
#	include <concepts>
#	include <cstddef>
#	include <cstdint>
#	include <functional>
#	include <iterator>
#	include <limits>
#	include <optional>
#	include <ranges>
#	include <string>
#	include <string_view>
#	include <vector>
#	include "../concepts/arithmetic.hpp"
#	include "../macros/forward.hpp"
#	include "../math/digits.hpp"
#	include "../math/is_negative.hpp"
#	include "../math/multiply.hpp"
#	include "../math/parse.hpp"
#	include "../math/product.hpp"
#	include "../math/signed_size.hpp"
#	include "../math/split_boolean.hpp"
#	include "../math/stringify.hpp"
#	include "../strings/number_components.hpp"
#	include "../system/byte_bits.hpp"
#	include "../types/size_bits.hpp"
#	include "../types/try_unsigned.hpp"

namespace xieite::math {
	template<std::unsigned_integral Word_ = std::uint64_t>
	struct BigInteger {
	public:
		using Word = Word_;

		template<std::integral Integral = int>
		constexpr BigInteger(const Integral value = 0) noexcept
		: negative(xieite::math::isNegative(value)) {
			xieite::types::TryUnsigned<Integral> absoluteValue = xieite::math::absolute(value);
			do {
				this->data.push_back(static_cast<Word_>(absoluteValue));
				if constexpr (sizeof(Integral) > sizeof(Word_)) {
					absoluteValue >>= xieite::types::sizeBits<Word_>;
				} else {
					break;
				}
			} while (absoluteValue);
		}

		template<typename OtherWord_>
		constexpr BigInteger(const xieite::math::BigInteger<OtherWord_>& value) noexcept
		: negative(value.negative) {
			if constexpr (sizeof(Word_) == sizeof(OtherWord_)) {
				this->data = value.data;
				return;
			}
			if constexpr (sizeof(Word_) > sizeof(OtherWord_)) {
				std::size_t shiftBytes = sizeof(Word_);
				for (const OtherWord_ otherWord_ : value.data) {
					if (shiftBytes >= sizeof(Word_)) {
						shiftBytes = 0;
						this->data.push_back(0);
					}
					this->data.back() |= otherWord_ << (shiftBytes * xieite::system::byteBits);
					shiftBytes += sizeof(OtherWord_);
				}
				return;
			}
			for (const OtherWord_ otherWord_ : value.data) {
				std::size_t shiftBytes = 0;
				do {
					this->data.push_back(static_cast<Word_>(otherWord_ >> (shiftBytes * xieite::system::byteBits)));
					shiftBytes += sizeof(Word_);
				} while (shiftBytes < sizeof(OtherWord_));
			}
			this->trim();
		}

		template<std::ranges::range Range>
		requires(std::same_as<std::ranges::range_value_t<Range>, Word_>)
		constexpr BigInteger(Range&& range, const bool negative = false) noexcept
		: data(std::ranges::begin(XIEITE_FORWARD(range)), std::ranges::end(XIEITE_FORWARD(range))), negative(negative) {
			this->trim();
		}

		constexpr BigInteger(const std::string_view value, const xieite::math::SignedSize radix = 10, const xieite::strings::NumberComponents components = xieite::strings::NumberComponents()) noexcept {
			*this = xieite::math::parse<xieite::math::BigInteger<Word_>>(value, radix, components);
		}

		constexpr xieite::math::BigInteger<Word_>& operator=(const xieite::math::BigInteger<Word_>& value) noexcept {
			this->data = value.data;
			this->negative = value.negative;
			return *this;
		}

		template<std::integral Integral>
		constexpr xieite::math::BigInteger<Word_>& operator=(const Integral value) noexcept {
			return *this = xieite::math::BigInteger<Word_>(value);
		}

		template<std::integral Integral>
		[[nodiscard]] explicit constexpr operator Integral() const noexcept {
			Integral result = 0;
			const std::size_t dataSize = this->data.size();
			for (std::size_t i = 0; i < dataSize; ++i) {
				result |= static_cast<Integral>(this->data[i]) << (static_cast<Integral>(i) * xieite::types::sizeBits<Word_>);
			}
			if (this->negative) {
				return -result;
			}
			return result;
		}

		[[nodiscard]] explicit constexpr operator bool() const noexcept {
			return (this->data.size() > 1) || this->data[0];
		}

		[[nodiscard]] friend constexpr std::strong_ordering operator<=>(const xieite::math::BigInteger<Word_>& leftComparand, const xieite::math::BigInteger<Word_>& rightComparand) noexcept {
			if (leftComparand.negative != rightComparand.negative) {
				return rightComparand.negative <=> leftComparand.negative;
			}
			if (leftComparand.negative) {
				if (leftComparand.data.size() != rightComparand.data.size()) {
					return rightComparand.data.size() <=> leftComparand.data.size();
				} else {
					return std::lexicographical_compare_three_way(rightComparand.data.rbegin(), rightComparand.data.rend(), leftComparand.data.rbegin(), leftComparand.data.rend());
				}
			}
			if (leftComparand.data.size() != rightComparand.data.size()) {
				return leftComparand.data.size() <=> rightComparand.data.size();
			} else {
				return std::lexicographical_compare_three_way(leftComparand.data.rbegin(), leftComparand.data.rend(), rightComparand.data.rbegin(), rightComparand.data.rend());
			}
		}

		template<std::integral Integral>
		[[nodiscard]] friend constexpr std::strong_ordering operator<=>(const xieite::math::BigInteger<Word_>& leftComparand, const Integral rightComparand) noexcept {
			return leftComparand <=> xieite::math::BigInteger<Word_>(rightComparand);
		}

		[[nodiscard]] friend constexpr bool operator==(const xieite::math::BigInteger<Word_>& leftComparand, const xieite::math::BigInteger<Word_>& rightComparand) noexcept {
			return std::is_eq(leftComparand <=> rightComparand);
		}

		template<std::integral Integral>
		[[nodiscard]] friend constexpr bool operator==(const xieite::math::BigInteger<Word_>& leftComparand, const Integral rightComparand) noexcept {
			return leftComparand == xieite::math::BigInteger<Word_>(rightComparand);
		}

		[[nodiscard]] constexpr xieite::math::BigInteger<Word_> operator+() const noexcept {
			return *this;
		}

		[[nodiscard]] friend constexpr xieite::math::BigInteger<Word_> operator+(const xieite::math::BigInteger<Word_>& augend, const xieite::math::BigInteger<Word_>& addend) noexcept {
			if (!augend) {
				return addend;
			}
			if (!addend) {
				return augend;
			}
			if (augend.negative != addend.negative) {
				return augend - (-addend);
			}
			std::vector<Word_> resultData;
			bool carry = false;
			const std::size_t augendDataSize = augend.data.size();
			const std::size_t addendDataSize = addend.data.size();
			for (std::size_t i = 0; (i < augendDataSize) || (i < addendDataSize) || carry; ++i) {
				const Word_ augendWord_ = (i < augendDataSize) ? augend.data[i] : 0;
				const Word_ addendWord_ = (i < addendDataSize) ? addend.data[i] : 0;
				resultData.push_back(augendWord_ + addendWord_ + carry);
				carry = (std::numeric_limits<Word_>::max() - augendWord_ < carry) || (std::numeric_limits<Word_>::max() - augendWord_ < addendWord_) || (std::numeric_limits<Word_>::max() - augendWord_ - carry < addendWord_);
			}
			return xieite::math::BigInteger<Word_>(resultData, augend.negative);
		}

		template<std::integral Integral>
		[[nodiscard]] friend constexpr xieite::math::BigInteger<Word_> operator+(const xieite::math::BigInteger<Word_>& augend, const Integral addend) noexcept {
			return augend + xieite::math::BigInteger<Word_>(addend);
		}

		constexpr xieite::math::BigInteger<Word_>& operator+=(const xieite::math::BigInteger<Word_>& addend) noexcept {
			return *this = *this + addend;
		}

		template<std::integral Integral>
		constexpr xieite::math::BigInteger<Word_>& operator+=(const Integral addend) noexcept {
			return *this += xieite::math::BigInteger<Word_>(addend);
		}

		constexpr xieite::math::BigInteger<Word_>& operator++() noexcept {
			return *this += 1;
		}

		constexpr xieite::math::BigInteger<Word_> operator++(int) noexcept {
			xieite::math::BigInteger<Word_> copy = *this;
			++*this;
			return copy;
		}

		[[nodiscard]] constexpr xieite::math::BigInteger<Word_> operator-() const noexcept {
			xieite::math::BigInteger<Word_> copy = *this;
			if (copy) {
				copy.negative = !copy.negative;
			}
			return copy;
		}

		[[nodiscard]] friend constexpr xieite::math::BigInteger<Word_> operator-(const xieite::math::BigInteger<Word_>& minuend, const xieite::math::BigInteger<Word_>& subtrahend) noexcept {
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
			std::vector<Word_> resultData;
			bool borrow = false;
			const std::size_t minuendDataSize = minuend.data.size();
			const std::size_t subtrahendDataSize = subtrahend.data.size();
			for (std::size_t i = 0; (i < subtrahendDataSize) || borrow; ++i) {
				const Word_ subtrahendWord_ = (i < subtrahendDataSize) ? subtrahend.data[i] : 0;
				resultData.push_back(minuend.data[i] - subtrahendWord_ - borrow);
				borrow = (i < minuendDataSize - 1) && ((minuend.data[i] < borrow) || (minuend.data[i] < subtrahendWord_) || ((minuend.data[i] - borrow) < subtrahendWord_));
			}
			return xieite::math::BigInteger<Word_>(resultData, minuend.negative);
		}

		template<std::integral Integral>
		[[nodiscard]] friend constexpr xieite::math::BigInteger<Word_> operator-(const xieite::math::BigInteger<Word_>& minuend, const Integral subtrahend) noexcept {
			return minuend - xieite::math::BigInteger<Word_>(subtrahend);
		}

		constexpr xieite::math::BigInteger<Word_>& operator-=(const xieite::math::BigInteger<Word_>& subtrahend) noexcept {
			return *this = *this - subtrahend;
		}

		template<std::integral Integral>
		constexpr xieite::math::BigInteger<Word_>& operator-=(const Integral subtrahend) noexcept {
			return *this -= xieite::math::BigInteger<Word_>(subtrahend);
		}

		constexpr xieite::math::BigInteger<Word_>& operator--() noexcept {
			return *this -= 1;
		}

		constexpr xieite::math::BigInteger<Word_>& operator--(int) noexcept {
			xieite::math::BigInteger<Word_> copy = *this;
			--*this;
			return copy;
		}

		[[nodiscard]] friend constexpr xieite::math::BigInteger<Word_> operator*(const xieite::math::BigInteger<Word_>& multiplier, const xieite::math::BigInteger<Word_>& multiplicand) noexcept {
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
			if (multiplier.isPowerOf2()) {
				if (sameSign) {
					return multiplicand.absolute() << multiplier.logarithm2();
				}
				return -(multiplicand.absolute() << multiplier.logarithm2());
			}
			if (multiplicand.isPowerOf2()) {
				if (sameSign) {
					return multiplier.absolute() << multiplicand.logarithm2();
				}
				return -(multiplier.absolute() << multiplicand.logarithm2());
			}
			xieite::math::BigInteger<Word_> result;
			for (std::size_t i = multiplier.data.size(); i--;) {
				if (!multiplier.data[i]) {
					continue;
				}
				for (std::size_t j = multiplicand.data.size(); j--;) {
					if (!multiplicand.data[j]) {
						continue;
					}
					const xieite::math::Product<Word_> product = xieite::math::multiply<Word_>(multiplier.data[i], multiplicand.data[j]);
					result += ((xieite::math::BigInteger<Word_>(product.upper) << xieite::types::sizeBits<Word_>) | product.lower) << (xieite::math::BigInteger<Word_>(i) << xieite::math::digits<std::size_t>(xieite::types::sizeBits<Word_> - 1, 2)) << (xieite::math::BigInteger<Word_>(j) << xieite::math::digits<std::size_t>(xieite::types::sizeBits<Word_> - 1, 2));
				}
			}
			result.negative = !sameSign;
			return result;
		}

		template<std::integral Integral>
		[[nodiscard]] friend constexpr xieite::math::BigInteger<Word_> operator*(const xieite::math::BigInteger<Word_>& multiplier, const Integral multiplicand) noexcept {
			return multiplier * xieite::math::BigInteger<Word_>(multiplicand);
		}

		constexpr xieite::math::BigInteger<Word_>& operator*=(const xieite::math::BigInteger<Word_>& multiplicand) noexcept {
			return *this = *this * multiplicand;
		}

		template<std::integral Integral>
		constexpr xieite::math::BigInteger<Word_>& operator*=(const Integral multiplicand) noexcept {
			return *this *= xieite::math::BigInteger<Word_>(multiplicand);
		}

		[[nodiscard]] friend constexpr std::optional<xieite::math::BigInteger<Word_>> operator/(const xieite::math::BigInteger<Word_>& dividend, const xieite::math::BigInteger<Word_>& divisor) noexcept {
			if (!divisor) {
				return std::nullopt;
			}
			if ((dividend.data.size() < 2) && (divisor.data.size() < 2)) {
				return dividend.data[0] / divisor.data[0];
			}
			const bool sameSign = dividend.negative == divisor.negative;
			if ((divisor == 1) || (divisor == -1)) {
				return sameSign ? dividend : -dividend;
			}
			const xieite::math::BigInteger<Word_> absoluteDividend = dividend.absolute();
			const xieite::math::BigInteger<Word_> absoluteDivisor = divisor.absolute();
			if (!dividend || (absoluteDividend < absoluteDivisor)) {
				return 0;
			}
			if (absoluteDividend == absoluteDivisor) {
				return xieite::math::splitBoolean(sameSign);
			}
			if (divisor.isPowerOf2()) {
				if (sameSign) {
					return absoluteDividend >> divisor.logarithm2();
				}
				return -(absoluteDividend >> divisor.logarithm2());
			}
			xieite::math::BigInteger<Word_> remainder;
			xieite::math::BigInteger<Word_> result;
			remainder.data.resize(dividend.data.size(), 0);
			result.data.resize(dividend.data.size(), 0);
			for (std::size_t i = dividend.data.size(); i--;) {
				for (std::size_t j = xieite::types::sizeBits<Word_>; j--;) {
					remainder <<= 1;
					remainder.data[0] |= (dividend.data[i] >> j) & 1;
					const bool quotient = remainder >= absoluteDivisor;
					remainder -= absoluteDivisor * quotient;
					result.data[i] |= static_cast<Word_>(quotient) << j;
				}
			}
			result.negative = !sameSign;
			result.trim();
			return result;
		}

		template<std::integral Integral>
		[[nodiscard]] friend constexpr std::optional<xieite::math::BigInteger<Word_>> operator/(const xieite::math::BigInteger<Word_>& dividend, const Integral divisor) noexcept {
			return dividend / xieite::math::BigInteger<Word_>(divisor);
		}

		constexpr std::optional<std::reference_wrapper<xieite::math::BigInteger<Word_>>> operator/=(const xieite::math::BigInteger<Word_>& divisor) noexcept {
			return *this = *this / divisor;
		}

		template<std::integral Integral>
		constexpr std::optional<std::reference_wrapper<xieite::math::BigInteger<Word_>>> operator/=(const Integral divisor) noexcept {
			return *this /= xieite::math::BigInteger<Word_>(divisor);
		}

		[[nodiscard]] friend constexpr std::optional<xieite::math::BigInteger<Word_>> operator%(const xieite::math::BigInteger<Word_>& dividend, const xieite::math::BigInteger<Word_>& divisor) noexcept {
			if (!divisor) {
				return std::nullopt;
			}
			const xieite::math::BigInteger<Word_> absoluteDividend = dividend.absolute();
			const xieite::math::BigInteger<Word_> absoluteDivisor = divisor.absolute();
			if (!dividend || (absoluteDivisor == 1) || (absoluteDividend == absoluteDivisor)) {
				return 0;
			}
			if (absoluteDivisor.isPowerOf2()) {
				return (absoluteDividend & (absoluteDivisor - 1)) * xieite::math::splitBoolean(!dividend.negative);
			}
			if (absoluteDividend < absoluteDivisor) {
				return dividend;
			}
			xieite::math::BigInteger<Word_> remainder;
			for (const Word_ dividendWord_ : std::views::reverse(dividend.data)) {
				for (std::size_t j = xieite::types::sizeBits<Word_>; j--;) {
					remainder <<= 1;
					remainder.data[0] |= (dividendWord_ >> j) & 1;
					remainder -= absoluteDivisor * (remainder >= absoluteDivisor);
				}
			}
			remainder.negative = dividend.negative;
			return remainder;
		}

		template<std::integral Integral>
		[[nodiscard]] friend constexpr std::optional<xieite::math::BigInteger<Word_>> operator%(const xieite::math::BigInteger<Word_>& dividend, const Integral divisor) {
			return dividend % xieite::math::BigInteger<Word_>(divisor);
		}

		constexpr std::optional<std::reference_wrapper<xieite::math::BigInteger<Word_>>> operator%=(const xieite::math::BigInteger<Word_>& divisor) {
			return *this = *this % divisor;
		}

		template<std::integral Integral>
		constexpr std::optional<std::reference_wrapper<xieite::math::BigInteger<Word_>>> operator%=(const Integral divisor) {
			return *this %= xieite::math::BigInteger<Word_>(divisor);
		}

		[[nodiscard]] constexpr xieite::math::BigInteger<Word_> operator~() const noexcept {
			return -(*this + 1);
		}

		[[nodiscard]] friend constexpr xieite::math::BigInteger<Word_> operator&(const xieite::math::BigInteger<Word_>& leftOperand, const xieite::math::BigInteger<Word_>& rightOperand) noexcept {
			return xieite::math::BigInteger<Word_>::bitwiseOperation(leftOperand, rightOperand, [](const Word_ left, const Word_ right) {
				return left & right;
			});
		}

		template<std::integral Integral>
		[[nodiscard]] friend constexpr xieite::math::BigInteger<Word_> operator&(const xieite::math::BigInteger<Word_>& leftOperand, const Integral rightOperand) noexcept {
			return leftOperand & xieite::math::BigInteger<Word_>(rightOperand);
		}

		constexpr xieite::math::BigInteger<Word_>& operator&=(const xieite::math::BigInteger<Word_>& operand) noexcept {
			return *this = *this & operand;
		}

		template<std::integral Integral>
		constexpr xieite::math::BigInteger<Word_>& operator&=(const Integral operand) noexcept {
			return *this &= xieite::math::BigInteger<Word_>(operand);
		}

		[[nodiscard]] friend constexpr xieite::math::BigInteger<Word_> operator|(const xieite::math::BigInteger<Word_>& leftOperand, const xieite::math::BigInteger<Word_>& rightOperand) noexcept {
			return xieite::math::BigInteger<Word_>::bitwiseOperation(leftOperand, rightOperand, [](const Word_ left, const Word_ right) {
				return left | right;
			});
		}

		template<std::integral Integral>
		[[nodiscard]] friend constexpr xieite::math::BigInteger<Word_> operator|(const xieite::math::BigInteger<Word_>& leftOperand, const Integral rightOperand) noexcept {
			return leftOperand | xieite::math::BigInteger<Word_>(rightOperand);
		}

		constexpr xieite::math::BigInteger<Word_>& operator|=(const xieite::math::BigInteger<Word_>& operand) noexcept {
			return *this = *this | operand;
		}

		template<std::integral Integral>
		constexpr xieite::math::BigInteger<Word_>& operator|=(const Integral operand) noexcept {
			return *this |= xieite::math::BigInteger<Word_>(operand);
		}

		[[nodiscard]] friend constexpr xieite::math::BigInteger<Word_> operator^(const xieite::math::BigInteger<Word_>& leftOperand, const xieite::math::BigInteger<Word_>& rightOperand) noexcept {
			return xieite::math::BigInteger<Word_>::bitwiseOperation(leftOperand, rightOperand, [](const Word_ left, const Word_ right) {
				return left ^ right;
			});
		}

		template<std::integral Integral>
		[[nodiscard]] friend constexpr xieite::math::BigInteger<Word_> operator^(const xieite::math::BigInteger<Word_>& leftOperand, const Integral rightOperand) noexcept {
			return leftOperand ^ xieite::math::BigInteger<Word_>(rightOperand);
		}

		constexpr xieite::math::BigInteger<Word_>& operator^=(const xieite::math::BigInteger<Word_>& operand) noexcept {
			return *this = *this ^ operand;
		}

		template<std::integral Integral>
		constexpr xieite::math::BigInteger<Word_>& operator^=(const Integral operand) noexcept {
			return *this ^= xieite::math::BigInteger<Word_>(operand);
		}

		[[nodiscard]] friend constexpr xieite::math::BigInteger<Word_> operator<<(const xieite::math::BigInteger<Word_>& leftOperand, const xieite::math::BigInteger<Word_>& rightOperand) noexcept {
			if (!leftOperand || !rightOperand) {
				return leftOperand;
			}
			if (rightOperand.negative) {
				return leftOperand >> -rightOperand;
			}
			const std::size_t dataShift = static_cast<std::size_t>(rightOperand) >> static_cast<std::size_t>(std::log2(xieite::types::sizeBits<Word_>));
			const std::size_t bitsShift = static_cast<std::size_t>(rightOperand) & (xieite::types::sizeBits<Word_> - 1);
			auto resultData = std::vector<Word_>(dataShift, 0);
			resultData.insert(resultData.end(), leftOperand.data.begin(), leftOperand.data.end());
			if (bitsShift) {
				Word_ carry = 0;
				const std::size_t leftDataSize = leftOperand.data.size();
				for (std::size_t i = 0; i < leftDataSize; ++i) {
					resultData[i + dataShift] = (leftOperand.data[i] << bitsShift) | carry;
					carry = leftOperand.data[i] >> (xieite::types::sizeBits<Word_> - bitsShift);
				}
				if (carry) {
					resultData.push_back(carry);
				}
			}
			return xieite::math::BigInteger<Word_>(resultData, leftOperand.negative);
		}

		template<std::integral Integral>
		[[nodiscard]] friend constexpr xieite::math::BigInteger<Word_> operator<<(const xieite::math::BigInteger<Word_>& leftOperand, const Integral rightOperand) noexcept {
			return leftOperand << xieite::math::BigInteger<Word_>(rightOperand);
		}

		constexpr xieite::math::BigInteger<Word_>& operator<<=(const xieite::math::BigInteger<Word_>& operand) noexcept {
			return *this = *this << operand;
		}

		template<std::integral Integral>
		constexpr xieite::math::BigInteger<Word_>& operator<<=(const Integral operand) noexcept {
			return *this <<= xieite::math::BigInteger<Word_>(operand);
		}

		[[nodiscard]] friend constexpr xieite::math::BigInteger<Word_> operator>>(const xieite::math::BigInteger<Word_>& leftOperand, const xieite::math::BigInteger<Word_>& rightOperand) noexcept {
			if (!leftOperand || !rightOperand) {
				return leftOperand;
			}
			if (rightOperand.negative) {
				return leftOperand >> -rightOperand;
			}
			const std::size_t dataShift = static_cast<std::size_t>(rightOperand) >> static_cast<std::size_t>(std::log2(xieite::types::sizeBits<Word_>));
			const std::size_t bitsShift = static_cast<std::size_t>(rightOperand) & (xieite::types::sizeBits<Word_> - 1);
			const std::size_t leftDataSize = leftOperand.data.size();
			if (dataShift >= leftDataSize) {
				return 0;
			}
			auto resultData = std::vector<Word_>(std::ranges::next(leftOperand.data.begin(), dataShift, leftOperand.data.end()), leftOperand.data.end());
			if (bitsShift) {
				Word_ carry = 0;
				for (Word_& resultWord_ : std::views::reverse(resultData)) {
					const Word_ copy = resultWord_;
					resultWord_ = (copy >> bitsShift) | carry;
					carry = copy << (xieite::types::sizeBits<Word_> - bitsShift);
				}
			}
			return xieite::math::BigInteger<Word_>(resultData, leftOperand.negative) - leftOperand.negative;
		}

		template<std::integral Integral>
		[[nodiscard]] friend constexpr xieite::math::BigInteger<Word_> operator>>(const xieite::math::BigInteger<Word_>& leftOperand, const Integral rightOperand) noexcept {
			return leftOperand >> xieite::math::BigInteger<Word_>(rightOperand);
		}

		constexpr xieite::math::BigInteger<Word_>& operator>>=(const xieite::math::BigInteger<Word_>& operand) noexcept {
			return *this = *this >> operand;
		}

		template<std::integral Integral>
		constexpr xieite::math::BigInteger<Word_>& operator>>=(const Integral operand) noexcept {
			return *this >>= xieite::math::BigInteger<Word_>(operand);
		}

		[[nodiscard]] constexpr xieite::math::BigInteger<Word_> absolute() const noexcept {
			xieite::math::BigInteger<Word_> copy = *this;
			copy.negative = false;
			return copy;
		}

		[[nodiscard]] constexpr std::optional<xieite::math::BigInteger<Word_>> power(const xieite::math::BigInteger<Word_>& exponent) const noexcept {
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
					return std::nullopt;
				}
				return !exponent;
			}
			xieite::math::BigInteger<Word_> foo = *this;
			xieite::math::BigInteger<Word_> bar = 1;
			xieite::math::BigInteger<Word_> baz = exponent;
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

		template<std::integral Integral>
		[[nodiscard]] constexpr std::optional<xieite::math::BigInteger<Word_>> power(const Integral exponent) const {
			return this->power(xieite::math::BigInteger<Word_>(exponent));
		}

		[[nodiscard]] constexpr std::optional<xieite::math::BigInteger<Word_>> root(const xieite::math::BigInteger<Word_>& degree) const noexcept {
			if (this->negative) {
				return std::nullopt;
			}
			if (*this == 1) {
				return *this;
			}
			if (degree.negative) {
				return 0;
			}
			xieite::math::BigInteger<Word_> foo = degree - 1;
			xieite::math::BigInteger<Word_> bar = *this;
			xieite::math::BigInteger<Word_> baz = bar + 1;
			while (bar < baz) {
				baz = bar;
				bar = (foo * bar + *this / bar.power(foo)) / degree;
			}
			return baz;
		}

		template<std::integral Integral>
		[[nodiscard]] constexpr std::optional<xieite::math::BigInteger<Word_>> root(const Integral degree) const {
			return this->root(xieite::math::BigInteger<Word_>(degree));
		}

		[[nodiscard]] constexpr std::optional<xieite::math::BigInteger<Word_>> logarithm(const xieite::math::BigInteger<Word_>& base) const noexcept {
			if (!base) {
				return 0;
			}
			if (this->negative || (base == 1) || base.negative) {
				return std::nullopt;
			}
			return this->logarithm2() / base.logarithm2();
		}

		template<std::integral Integral>
		[[nodiscard]] constexpr std::optional<xieite::math::BigInteger<Word_>> logarithm(const Integral base) const {
			return this->logarithm(xieite::math::BigInteger<Word_>(base));
		}

		[[nodiscard]] constexpr std::string string(const xieite::math::SignedSize radix = 10, const xieite::strings::NumberComponents components = xieite::strings::NumberComponents()) const noexcept {
			return xieite::math::stringify(*this, radix, components);
		}

	private:
		std::vector<Word_> data;
		bool negative;

		template<typename Functor>
		[[nodiscard]] static constexpr xieite::math::BigInteger<Word_> bitwiseOperation(xieite::math::BigInteger<Word_> leftOperand, xieite::math::BigInteger<Word_> rightOperand, Functor&& callback) noexcept {
			const bool leftNegative = leftOperand.negative;
			const bool rightNegative = rightOperand.negative;
			leftOperand += leftNegative;
			rightOperand += rightNegative;
			xieite::math::BigInteger<Word_> result;
			result.data.clear();
			result.negative = callback(leftNegative, rightNegative);
			const std::size_t leftDataSize = leftOperand.data.size();
			const std::size_t rightDataSize = rightOperand.data.size();
			for (std::size_t i = 0; (i < leftDataSize) || (i < rightDataSize); ++i) {
				const Word_ word = callback((i < leftDataSize) ? (leftNegative ? ~leftOperand.data[i] : leftOperand.data[i]) : (std::numeric_limits<Word_>::max() * leftNegative), (i < rightDataSize) ? (rightNegative ? ~rightOperand.data[i] : rightOperand.data[i]) : (std::numeric_limits<Word_>::max() * rightNegative));
				result.data.push_back(result.negative ? ~word : word);
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

		[[nodiscard]] constexpr bool isPowerOf2() const noexcept {
			const xieite::math::BigInteger<Word_> absolute = this->absolute();
			return absolute && !(absolute & (absolute - 1));
		}

		[[nodiscard]] constexpr xieite::math::BigInteger<Word_> logarithm2() const noexcept {
			return xieite::math::BigInteger<Word_>(xieite::types::sizeBits<Word_>) * (this->data.size() - 1) + xieite::math::digits<Word_>(this->data.back(), 2) - 1;
		}
	};
}

#endif

// Thanks to sam_dev (https://github.com/Sam-programs) for fixing the new division algorithm
