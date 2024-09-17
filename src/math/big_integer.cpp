module;

#include <xieite/forward.hpp>

export module xieite:math.BigInteger;

import std;
import :bits.size;
import :concepts.Arithmetic;
import :concepts.Invocable;
import :math.absolute;
import :math.additionOverflows;
import :math.isNegative;
import :math.multiply;
import :math.Product;
import :math.SignedSize;
import :math.splitBoolean;
import :math.subtractionOverflows;
import :strings.NumberComponents;
import :types.TryUnsigned;

export namespace xieite::math {
	template<std::unsigned_integral Limb = std::uint64_t>
	struct BigInteger
	: std::type_identity<Limb> {
	public:
		template<std::integral Integral = int>
		explicit(false) constexpr BigInteger(const Integral value = 0) noexcept
		: negative(xieite::math::isNegative(value)) {
			xieite::types::TryUnsigned<Integral> absoluteValue = xieite::math::absolute(value);
			do {
				this->data.push_back(static_cast<Limb>(absoluteValue));
				if constexpr (sizeof(Integral) > sizeof(Limb)) {
					absoluteValue >>= xieite::bits::size<Limb>;
				} else {
					break;
				}
			} while (absoluteValue);
		}

		template<typename OtherLimb>
		explicit constexpr BigInteger(const xieite::math::BigInteger<OtherLimb>& value) noexcept
		: negative(value.negative) {
			if constexpr (sizeof(Limb) == sizeof(OtherLimb)) {
				this->data = value.data;
				return;
			}
			if constexpr (sizeof(Limb) > sizeof(OtherLimb)) {
				std::size_t shiftBytes = sizeof(Limb);
				for (const OtherLimb otherLimb : value.data) {
					if (shiftBytes >= sizeof(Limb)) {
						shiftBytes = 0;
						this->data.push_back(0);
					}
					this->data.back() |= otherLimb << (shiftBytes * std::numeric_limits<unsigned char>::digits);
					shiftBytes += sizeof(OtherLimb);
				}
				return;
			}
			for (const OtherLimb otherLimb : value.data) {
				std::size_t shiftBytes = 0;
				do {
					this->data.push_back(static_cast<Limb>(otherLimb >> (shiftBytes * std::numeric_limits<unsigned char>::digits)));
					shiftBytes += sizeof(Limb);
				} while (shiftBytes < sizeof(OtherLimb));
			}
			this->trim();
		}

		template<std::ranges::input_range Range>
		requires(std::same_as<std::ranges::range_value_t<Range>, Limb>)
		explicit constexpr BigInteger(Range&& range, const bool negative = false) noexcept
		: data(std::ranges::begin(range), std::ranges::end(range)), negative(negative) {
			this->trim();
		}

		explicit(false) constexpr BigInteger(const std::string_view value, const xieite::math::SignedSize radix = 10, const xieite::strings::NumberComponents components = xieite::strings::NumberComponents()) noexcept
		: negative(false) {
			*this = 0;
			if (!radix) {
				return;
			}
			const bool negative = components.negatives.contains(value[0]);
			const std::size_t valueSize = value.size();
			for (std::size_t i = negative || components.positives.contains(value[0]); i < valueSize; ++i) {
				const std::size_t index = components.digits.find(value[i]);
				if (index == std::string_view::npos) {
					break;
				}
				*this = *this * radix + index;
			}
			this->negative = negative;
		}

		template<std::integral Integral>
		[[nodiscard]] explicit constexpr operator Integral() const noexcept {
			if constexpr (std::same_as<Integral, bool>) {
				return (this->data.size() > 1) || this->data[0];
			} else {
				Integral result = 0;
				std::size_t i = 0;
				std::size_t j = 0;
				while (j < xieite::bits::size<Integral>) {
					result |= static_cast<Integral>(this->data[i]) << j;
					++i;
					j += xieite::bits::size<Limb>;
				}
				return this->negative ? -result : result;
			}
		}

		[[nodiscard]] friend constexpr std::strong_ordering operator<=>(const xieite::math::BigInteger<Limb>& leftComparand, const xieite::math::BigInteger<Limb>& rightComparand) noexcept {
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
		[[nodiscard]] friend constexpr std::strong_ordering operator<=>(const xieite::math::BigInteger<Limb>& leftComparand, const Integral rightComparand) noexcept {
			return leftComparand <=> xieite::math::BigInteger<Limb>(rightComparand);
		}

		[[nodiscard]] friend constexpr bool operator==(const xieite::math::BigInteger<Limb>& leftComparand, const xieite::math::BigInteger<Limb>& rightComparand) noexcept {
			return std::is_eq(leftComparand <=> rightComparand);
		}

		template<std::integral Integral>
		[[nodiscard]] friend constexpr bool operator==(const xieite::math::BigInteger<Limb>& leftComparand, const Integral rightComparand) noexcept {
			return leftComparand == xieite::math::BigInteger<Limb>(rightComparand);
		}

		[[nodiscard]] constexpr xieite::math::BigInteger<Limb> operator+() const noexcept {
			return *this;
		}

		[[nodiscard]] friend constexpr xieite::math::BigInteger<Limb> operator+(const xieite::math::BigInteger<Limb>& augend, const xieite::math::BigInteger<Limb>& addend) noexcept {
			if (!augend) {
				return addend;
			}
			if (!addend) {
				return augend;
			}
			if (augend.negative != addend.negative) {
				return augend - (-addend);
			}
			std::vector<Limb> resultData;
			bool carry = false;
			const std::size_t augendDataSize = augend.data.size();
			const std::size_t addendDataSize = addend.data.size();
			for (std::size_t i = 0; (i < augendDataSize) || (i < addendDataSize) || carry; ++i) {
				const Limb augendLimb = (i < augendDataSize) ? augend.data[i] : 0;
				const Limb addendLimb = (i < addendDataSize) ? addend.data[i] : 0;
				resultData.push_back(augendLimb + addendLimb + carry);
				carry = xieite::math::additionOverflows(augendLimb, addendLimb, carry);
			}
			return xieite::math::BigInteger<Limb>(resultData, augend.negative);
		}

		template<std::integral Integral>
		[[nodiscard]] friend constexpr xieite::math::BigInteger<Limb> operator+(const xieite::math::BigInteger<Limb>& augend, const Integral addend) noexcept {
			return augend + xieite::math::BigInteger<Limb>(addend);
		}

		constexpr xieite::math::BigInteger<Limb>& operator+=(const xieite::math::BigInteger<Limb>& addend) noexcept {
			return *this = *this + addend;
		}

		template<std::integral Integral>
		constexpr xieite::math::BigInteger<Limb>& operator+=(const Integral addend) noexcept {
			return *this += xieite::math::BigInteger<Limb>(addend);
		}

		constexpr xieite::math::BigInteger<Limb>& operator++() noexcept {
			return *this += 1;
		}

		constexpr xieite::math::BigInteger<Limb> operator++(int) noexcept {
			xieite::math::BigInteger<Limb> copy = *this;
			++*this;
			return copy;
		}

		[[nodiscard]] constexpr xieite::math::BigInteger<Limb> operator-() const noexcept {
			xieite::math::BigInteger<Limb> copy = *this;
			if (copy) {
				copy.negative = !copy.negative;
			}
			return copy;
		}

		[[nodiscard]] friend constexpr xieite::math::BigInteger<Limb> operator-(const xieite::math::BigInteger<Limb>& minuend, const xieite::math::BigInteger<Limb>& subtrahend) noexcept {
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
			std::vector<Limb> resultData;
			bool borrow = false;
			const std::size_t minuendDataSize = minuend.data.size();
			const std::size_t subtrahendDataSize = subtrahend.data.size();
			for (std::size_t i = 0; (i < subtrahendDataSize) || borrow; ++i) {
				const Limb subtrahendLimb = (i < subtrahendDataSize) ? subtrahend.data[i] : 0;
				resultData.push_back(minuend.data[i] - subtrahendLimb - borrow);
				borrow = (i < (minuendDataSize - 1)) && xieite::math::subtractionOverflows(minuend.data[i], subtrahendLimb, borrow);
			}
			return xieite::math::BigInteger<Limb>(resultData, minuend.negative);
		}

		template<std::integral Integral>
		[[nodiscard]] friend constexpr xieite::math::BigInteger<Limb> operator-(const xieite::math::BigInteger<Limb>& minuend, const Integral subtrahend) noexcept {
			return minuend - xieite::math::BigInteger<Limb>(subtrahend);
		}

		constexpr xieite::math::BigInteger<Limb>& operator-=(const xieite::math::BigInteger<Limb>& subtrahend) noexcept {
			return *this = *this - subtrahend;
		}

		template<std::integral Integral>
		constexpr xieite::math::BigInteger<Limb>& operator-=(const Integral subtrahend) noexcept {
			return *this -= xieite::math::BigInteger<Limb>(subtrahend);
		}

		constexpr xieite::math::BigInteger<Limb>& operator--() noexcept {
			return *this -= 1;
		}

		constexpr xieite::math::BigInteger<Limb>& operator--(int) noexcept {
			xieite::math::BigInteger<Limb> copy = *this;
			--*this;
			return copy;
		}

		[[nodiscard]] friend constexpr xieite::math::BigInteger<Limb> operator*(const xieite::math::BigInteger<Limb>& multiplier, const xieite::math::BigInteger<Limb>& multiplicand) noexcept {
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
			xieite::math::BigInteger<Limb> result;
			for (std::size_t i = multiplier.data.size(); i--;) {
				if (!multiplier.data[i]) {
					continue;
				}
				for (std::size_t j = multiplicand.data.size(); j--;) {
					if (!multiplicand.data[j]) {
						continue;
					}
					const xieite::math::Product<Limb> product = xieite::math::multiply(multiplier.data[i], multiplicand.data[j]);
					result += ((xieite::math::BigInteger<Limb>(product.upper) << xieite::bits::size<Limb>) | product.lower) << (xieite::math::BigInteger<Limb>(i) << std::bit_width(xieite::bits::size<Limb> - 1)) << (xieite::math::BigInteger<Limb>(j) << std::bit_width(xieite::bits::size<Limb> - 1));
				}
			}
			result.negative = !sameSign;
			return result;
		}

		template<std::integral Integral>
		[[nodiscard]] friend constexpr xieite::math::BigInteger<Limb> operator*(const xieite::math::BigInteger<Limb>& multiplier, const Integral multiplicand) noexcept {
			return multiplier * xieite::math::BigInteger<Limb>(multiplicand);
		}

		constexpr xieite::math::BigInteger<Limb>& operator*=(const xieite::math::BigInteger<Limb>& multiplicand) noexcept {
			return *this = *this * multiplicand;
		}

		template<std::integral Integral>
		constexpr xieite::math::BigInteger<Limb>& operator*=(const Integral multiplicand) noexcept {
			return *this *= xieite::math::BigInteger<Limb>(multiplicand);
		}

		[[nodiscard]] friend constexpr xieite::math::BigInteger<Limb> operator/(const xieite::math::BigInteger<Limb>& dividend, const xieite::math::BigInteger<Limb>& divisor) {
			if (!divisor) {
				throw std::out_of_range("must not divide by zero");
			}
			if ((dividend.data.size() < 2) && (divisor.data.size() < 2)) {
				return dividend.data[0] / divisor.data[0];
			}
			const bool sameSign = dividend.negative == divisor.negative;
			if ((divisor == 1) || (divisor == -1)) {
				return sameSign ? dividend : -dividend;
			}
			const xieite::math::BigInteger<Limb> absoluteDividend = dividend.absolute();
			const xieite::math::BigInteger<Limb> absoluteDivisor = divisor.absolute();
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
			xieite::math::BigInteger<Limb> remainder;
			xieite::math::BigInteger<Limb> result;
			remainder.data.resize(dividend.data.size(), 0);
			result.data.resize(dividend.data.size(), 0);
			for (std::size_t i = dividend.data.size(); i--;) {
				for (std::size_t j = xieite::bits::size<Limb>; j--;) {
					remainder <<= 1;
					remainder.data[0] |= (dividend.data[i] >> j) & 1;
					const bool quotient = remainder >= absoluteDivisor;
					remainder -= absoluteDivisor * quotient;
					result.data[i] |= static_cast<Limb>(quotient) << j;
				}
			}
			result.negative = !sameSign;
			result.trim();
			return result;
		}

		template<std::integral Integral>
		[[nodiscard]] friend constexpr xieite::math::BigInteger<Limb> operator/(const xieite::math::BigInteger<Limb>& dividend, const Integral divisor) {
			return dividend / xieite::math::BigInteger<Limb>(divisor);
		}

		constexpr xieite::math::BigInteger<Limb> operator/=(const xieite::math::BigInteger<Limb>& divisor) {
			return *this = *this / divisor;
		}

		template<std::integral Integral>
		constexpr xieite::math::BigInteger<Limb> operator/=(const Integral divisor) {
			return *this /= xieite::math::BigInteger<Limb>(divisor);
		}

		[[nodiscard]] friend constexpr xieite::math::BigInteger<Limb> operator%(const xieite::math::BigInteger<Limb>& dividend, const xieite::math::BigInteger<Limb>& divisor) {
			if (!divisor) {
				throw std::out_of_range("must not take remainder by zero");
			}
			const xieite::math::BigInteger<Limb> absoluteDividend = dividend.absolute();
			const xieite::math::BigInteger<Limb> absoluteDivisor = divisor.absolute();
			if (!dividend || (absoluteDivisor == 1) || (absoluteDividend == absoluteDivisor)) {
				return 0;
			}
			if (absoluteDivisor.isPowerOf2()) {
				return (absoluteDividend & (absoluteDivisor - 1)) * xieite::math::splitBoolean(!dividend.negative);
			}
			if (absoluteDividend < absoluteDivisor) {
				return dividend;
			}
			xieite::math::BigInteger<Limb> remainder;
			for (const Limb dividendLimb : std::views::reverse(dividend.data)) {
				for (std::size_t j = xieite::bits::size<Limb>; j--;) {
					remainder <<= 1;
					remainder.data[0] |= (dividendLimb >> j) & 1;
					remainder -= absoluteDivisor * (remainder >= absoluteDivisor);
				}
			}
			remainder.negative = dividend.negative;
			return remainder;
		}

		template<std::integral Integral>
		[[nodiscard]] friend constexpr xieite::math::BigInteger<Limb> operator%(const xieite::math::BigInteger<Limb>& dividend, const Integral divisor) {
			return dividend % xieite::math::BigInteger<Limb>(divisor);
		}

		constexpr xieite::math::BigInteger<Limb> operator%=(const xieite::math::BigInteger<Limb>& divisor) {
			return *this = *this % divisor;
		}

		template<std::integral Integral>
		constexpr xieite::math::BigInteger<Limb> operator%=(const Integral divisor) {
			return *this %= xieite::math::BigInteger<Limb>(divisor);
		}

		[[nodiscard]] constexpr xieite::math::BigInteger<Limb> operator~() const noexcept {
			return -(*this + 1);
		}

		[[nodiscard]] friend constexpr xieite::math::BigInteger<Limb> operator&(const xieite::math::BigInteger<Limb>& leftOperand, const xieite::math::BigInteger<Limb>& rightOperand) noexcept {
			return xieite::math::BigInteger<Limb>::bitwiseOperation(leftOperand, rightOperand, [](const Limb left, const Limb right) {
				return left & right;
			});
		}

		template<std::integral Integral>
		[[nodiscard]] friend constexpr xieite::math::BigInteger<Limb> operator&(const xieite::math::BigInteger<Limb>& leftOperand, const Integral rightOperand) noexcept {
			return leftOperand & xieite::math::BigInteger<Limb>(rightOperand);
		}

		constexpr xieite::math::BigInteger<Limb>& operator&=(const xieite::math::BigInteger<Limb>& operand) noexcept {
			return *this = *this & operand;
		}

		template<std::integral Integral>
		constexpr xieite::math::BigInteger<Limb>& operator&=(const Integral operand) noexcept {
			return *this &= xieite::math::BigInteger<Limb>(operand);
		}

		[[nodiscard]] friend constexpr xieite::math::BigInteger<Limb> operator|(const xieite::math::BigInteger<Limb>& leftOperand, const xieite::math::BigInteger<Limb>& rightOperand) noexcept {
			return xieite::math::BigInteger<Limb>::bitwiseOperation(leftOperand, rightOperand, [](const Limb left, const Limb right) {
				return left | right;
			});
		}

		template<std::integral Integral>
		[[nodiscard]] friend constexpr xieite::math::BigInteger<Limb> operator|(const xieite::math::BigInteger<Limb>& leftOperand, const Integral rightOperand) noexcept {
			return leftOperand | xieite::math::BigInteger<Limb>(rightOperand);
		}

		constexpr xieite::math::BigInteger<Limb>& operator|=(const xieite::math::BigInteger<Limb>& operand) noexcept {
			return *this = *this | operand;
		}

		template<std::integral Integral>
		constexpr xieite::math::BigInteger<Limb>& operator|=(const Integral operand) noexcept {
			return *this |= xieite::math::BigInteger<Limb>(operand);
		}

		[[nodiscard]] friend constexpr xieite::math::BigInteger<Limb> operator^(const xieite::math::BigInteger<Limb>& leftOperand, const xieite::math::BigInteger<Limb>& rightOperand) noexcept {
			return xieite::math::BigInteger<Limb>::bitwiseOperation(leftOperand, rightOperand, [](const Limb left, const Limb right) {
				return left ^ right;
			});
		}

		template<std::integral Integral>
		[[nodiscard]] friend constexpr xieite::math::BigInteger<Limb> operator^(const xieite::math::BigInteger<Limb>& leftOperand, const Integral rightOperand) noexcept {
			return leftOperand ^ xieite::math::BigInteger<Limb>(rightOperand);
		}

		constexpr xieite::math::BigInteger<Limb>& operator^=(const xieite::math::BigInteger<Limb>& operand) noexcept {
			return *this = *this ^ operand;
		}

		template<std::integral Integral>
		constexpr xieite::math::BigInteger<Limb>& operator^=(const Integral operand) noexcept {
			return *this ^= xieite::math::BigInteger<Limb>(operand);
		}

		[[nodiscard]] friend constexpr xieite::math::BigInteger<Limb> operator<<(const xieite::math::BigInteger<Limb>& leftOperand, const xieite::math::BigInteger<Limb>& rightOperand) noexcept {
			if (!leftOperand || !rightOperand) {
				return leftOperand;
			}
			if (rightOperand.negative) {
				return leftOperand >> -rightOperand;
			}
			const std::size_t dataShift = static_cast<std::size_t>(rightOperand) >> static_cast<std::size_t>(std::bit_width(xieite::bits::size<Limb>) - 1);
			const std::size_t bitsShift = static_cast<std::size_t>(rightOperand) & (xieite::bits::size<Limb> - 1);
			auto resultData = std::vector<Limb>(dataShift, 0);
			resultData.insert(resultData.end(), leftOperand.data.begin(), leftOperand.data.end());
			if (bitsShift) {
				Limb carry = 0;
				const std::size_t leftDataSize = leftOperand.data.size();
				for (std::size_t i = 0; i < leftDataSize; ++i) {
					resultData[i + dataShift] = (leftOperand.data[i] << bitsShift) | carry;
					carry = leftOperand.data[i] >> (xieite::bits::size<Limb> - bitsShift);
				}
				if (carry) {
					resultData.push_back(carry);
				}
			}
			return xieite::math::BigInteger<Limb>(resultData, leftOperand.negative);
		}

		template<std::integral Integral>
		[[nodiscard]] friend constexpr xieite::math::BigInteger<Limb> operator<<(const xieite::math::BigInteger<Limb>& leftOperand, const Integral rightOperand) noexcept {
			return leftOperand << xieite::math::BigInteger<Limb>(rightOperand);
		}

		constexpr xieite::math::BigInteger<Limb>& operator<<=(const xieite::math::BigInteger<Limb>& operand) noexcept {
			return *this = *this << operand;
		}

		template<std::integral Integral>
		constexpr xieite::math::BigInteger<Limb>& operator<<=(const Integral operand) noexcept {
			return *this <<= xieite::math::BigInteger<Limb>(operand);
		}

		[[nodiscard]] friend constexpr xieite::math::BigInteger<Limb> operator>>(const xieite::math::BigInteger<Limb>& leftOperand, const xieite::math::BigInteger<Limb>& rightOperand) noexcept {
			if (!leftOperand || !rightOperand) {
				return leftOperand;
			}
			if (rightOperand.negative) {
				return leftOperand >> -rightOperand;
			}
			const std::size_t dataShift = static_cast<std::size_t>(rightOperand) >> static_cast<std::size_t>(std::bit_width(xieite::bits::size<Limb>) - 1);
			const std::size_t bitsShift = static_cast<std::size_t>(rightOperand) & (xieite::bits::size<Limb> - 1);
			const std::size_t leftDataSize = leftOperand.data.size();
			if (dataShift >= leftDataSize) {
				return 0;
			}
			auto resultData = std::vector<Limb>(std::ranges::next(leftOperand.data.begin(), static_cast<xieite::math::SignedSize>(dataShift), leftOperand.data.end()), leftOperand.data.end());
			if (bitsShift) {
				Limb carry = 0;
				for (Limb& resultLimb : std::views::reverse(resultData)) {
					const Limb copy = resultLimb;
					resultLimb = (copy >> bitsShift) | carry;
					carry = copy << (xieite::bits::size<Limb> - bitsShift);
				}
			}
			return xieite::math::BigInteger<Limb>(resultData, leftOperand.negative) - leftOperand.negative;
		}

		template<std::integral Integral>
		[[nodiscard]] friend constexpr xieite::math::BigInteger<Limb> operator>>(const xieite::math::BigInteger<Limb>& leftOperand, const Integral rightOperand) noexcept {
			return leftOperand >> xieite::math::BigInteger<Limb>(rightOperand);
		}

		constexpr xieite::math::BigInteger<Limb>& operator>>=(const xieite::math::BigInteger<Limb>& operand) noexcept {
			return *this = *this >> operand;
		}

		template<std::integral Integral>
		constexpr xieite::math::BigInteger<Limb>& operator>>=(const Integral operand) noexcept {
			return *this >>= xieite::math::BigInteger<Limb>(operand);
		}

		[[nodiscard]] constexpr xieite::math::BigInteger<Limb> absolute() const noexcept {
			xieite::math::BigInteger<Limb> copy = *this;
			copy.negative = false;
			return copy;
		}

		[[nodiscard]] constexpr xieite::math::BigInteger<Limb> power(xieite::math::BigInteger<Limb> exponent) const {
			if ((*this == 1) || (exponent == 1)) {
				return *this;
			}
			if (*this == -1) {
				return *this * xieite::math::splitBoolean(!!(exponent & 1));
			}
			if (!exponent) {
				return 1;
			}
			if (!*this) {
				if (exponent.negative) {
					throw std::out_of_range("must not take power of zero to negative exponent");
				}
				return !exponent;
			}
			xieite::math::BigInteger<Limb> base = *this;
			xieite::math::BigInteger<Limb> result = 1;
			while (exponent > 1) {
				if (exponent & 1) {
					result *= base;
					exponent = (exponent - 1) >> 1;
				} else {
					exponent >>= 1;
				}
				base *= base;
			}
			return result * base;
		}

		template<std::integral Integral>
		[[nodiscard]] constexpr xieite::math::BigInteger<Limb> power(const Integral exponent) const {
			return this->power(xieite::math::BigInteger<Limb>(exponent));
		}

		[[nodiscard]] constexpr xieite::math::BigInteger<Limb> root(const xieite::math::BigInteger<Limb>& degree) const {
			if (this->negative) {
				throw std::out_of_range("must not take root of negative radicand");
			}
			if (!degree) {
				throw std::out_of_range("must not take root to zeroth degree");
			}
			if (*this == 1) {
				return *this;
			}
			if (degree.negative) {
				return 0;
			}
			xieite::math::BigInteger<Limb> foo = degree - 1;
			xieite::math::BigInteger<Limb> bar = *this;
			xieite::math::BigInteger<Limb> baz = bar + 1;
			while (bar < baz) {
				baz = bar;
				bar = (foo * bar + *this / bar.power(foo)) / degree;
			}
			return baz;
		}

		template<std::integral Integral>
		[[nodiscard]] constexpr xieite::math::BigInteger<Limb> root(const Integral degree) const {
			return this->root(xieite::math::BigInteger<Limb>(degree));
		}

		[[nodiscard]] constexpr xieite::math::BigInteger<Limb> logarithm(const xieite::math::BigInteger<Limb>& base) const {
			if (!base) {
				return 0;
			}
			if (this->negative) {
				throw std::out_of_range("must not take logarithm of negative anti-logarithm");
			}
			if (base == 1) {
				throw std::out_of_range("must not take logarithm to unary base");
			}
			if (base.negative) {
				throw std::out_of_range("must not take logarithm to negative base");
			}
			return this->logarithm2() / base.logarithm2();
		}

		template<std::integral Integral>
		[[nodiscard]] constexpr xieite::math::BigInteger<Limb> logarithm(const Integral base) const {
			return this->logarithm(xieite::math::BigInteger<Limb>(base));
		}

		[[nodiscard]] constexpr std::string string(const xieite::math::SignedSize radix = 10, const xieite::strings::NumberComponents components = xieite::strings::NumberComponents()) const noexcept {
			if (!*this || !radix) {
				return std::string(1, components.digits[0]);
			}
			std::string result;
			xieite::math::BigInteger<Limb> value = this->absolute();
			if (radix == 1) {
				result = std::string(static_cast<std::size_t>(value), components.digits[1]);
			} else if (radix == -1) {
				result = components.digits[1];
				std::size_t length = static_cast<std::size_t>(value);
				while (--length) {
					result += components.digits[0];
					result += components.digits[1];
				}
			} else {
				do {
					xieite::math::SignedSize index = static_cast<xieite::math::SignedSize>(value % radix);
					value /= radix;
					if (index < 0) {
						index += radix;
						++value;
					}
					result.insert(0, 1, components.digits[static_cast<std::size_t>(index) * (static_cast<std::size_t>(index) < components.digits.size())]);
				} while (value);
			}
			if (*this < 0) {
				result.insert(0, 1, components.negatives[0]);
			}
			return result;
		}

	private:
		std::vector<Limb> data;
		bool negative;

		template<xieite::concepts::Invocable<bool(Limb, Limb)> Functor>
		[[nodiscard]] static constexpr xieite::math::BigInteger<Limb> bitwiseOperation(xieite::math::BigInteger<Limb> leftOperand, xieite::math::BigInteger<Limb> rightOperand, Functor&& callback) noexcept {
			const bool leftNegative = leftOperand.negative;
			const bool rightNegative = rightOperand.negative;
			leftOperand += leftNegative;
			rightOperand += rightNegative;
			xieite::math::BigInteger<Limb> result;
			result.data.clear();
			result.negative = std::invoke_r<bool>(callback, leftNegative, rightNegative);
			const std::size_t leftDataSize = leftOperand.data.size();
			const std::size_t rightDataSize = rightOperand.data.size();
			for (std::size_t i = 0; (i < leftDataSize) || (i < rightDataSize); ++i) {
				const Limb word = std::invoke_r<Limb>(callback, (i < leftDataSize) ? (leftNegative ? ~leftOperand.data[i] : leftOperand.data[i]) : (std::numeric_limits<Limb>::max() * leftNegative), (i < rightDataSize) ? (rightNegative ? ~rightOperand.data[i] : rightOperand.data[i]) : (std::numeric_limits<Limb>::max() * rightNegative));
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
			const xieite::math::BigInteger<Limb> absolute = this->absolute();
			return absolute && !(absolute & (absolute - 1));
		}

		[[nodiscard]] constexpr xieite::math::BigInteger<Limb> logarithm2() const noexcept {
			return xieite::math::BigInteger<Limb>(xieite::bits::size<Limb>) * (this->data.size() - 1) + std::bit_width(this->data.back()) - 1;
		}

		[[nodiscard]] constexpr xieite::math::BigInteger<Limb> bitFloor() const noexcept {
			return xieite::math::BigInteger<Limb>(1) << this->logarithm2();
		}
	};
}
