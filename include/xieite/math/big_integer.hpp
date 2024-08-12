#ifndef XIEITE_HEADER_MATH_BIG_INTEGER
#	define XIEITE_HEADER_MATH_BIG_INTEGER

#	include <algorithm>
#	include <climits>
#	include <compare>
#	include <concepts>
#	include <cstddef>
#	include <cstdint>
#	include <iterator>
#	include <limits>
#	include <optional>
#	include <ranges>
#	include <string>
#	include <string_view>
#	include <vector>
#	include "../bits/size.hpp"
#	include "../concepts/arithmetic.hpp"
#	include "../macros/forward.hpp"
#	include "../math/digits.hpp"
#	include "../math/is_negative.hpp"
#	include "../math/multiply.hpp"
#	include "../math/product.hpp"
#	include "../math/signed_size.hpp"
#	include "../math/split_boolean.hpp"
#	include "../strings/number_components.hpp"
#	include "../types/try_unsigned.hpp"

namespace xieite::math {
	template<std::unsigned_integral Limb_ = std::uint64_t>
	struct BigInteger {
	public:
		using Limb = Limb_;

		template<std::integral Integral_ = int>
		constexpr BigInteger(const Integral_ value = 0) noexcept
		: negative(xieite::math::isNegative(value)) {
			xieite::types::TryUnsigned<Integral_> absoluteValue = xieite::math::absolute(value);
			do {
				this->data.push_back(static_cast<Limb_>(absoluteValue));
				if constexpr (sizeof(Integral_) > sizeof(Limb_)) {
					absoluteValue >>= xieite::bits::size<Limb_>;
				} else {
					break;
				}
			} while (absoluteValue);
		}

		template<typename OtherLimb_>
		constexpr BigInteger(const xieite::math::BigInteger<OtherLimb_>& value) noexcept
		: negative(value.negative) {
			if constexpr (sizeof(Limb_) == sizeof(OtherLimb_)) {
				this->data = value.data;
				return;
			}
			if constexpr (sizeof(Limb_) > sizeof(OtherLimb_)) {
				std::size_t shiftBytes = sizeof(Limb_);
				for (const OtherLimb_ otherLimb_ : value.data) {
					if (shiftBytes >= sizeof(Limb_)) {
						shiftBytes = 0;
						this->data.push_back(0);
					}
					this->data.back() |= otherLimb_ << (shiftBytes * CHAR_BIT);
					shiftBytes += sizeof(OtherLimb_);
				}
				return;
			}
			for (const OtherLimb_ otherLimb_ : value.data) {
				std::size_t shiftBytes = 0;
				do {
					this->data.push_back(static_cast<Limb_>(otherLimb_ >> (shiftBytes * CHAR_BIT)));
					shiftBytes += sizeof(Limb_);
				} while (shiftBytes < sizeof(OtherLimb_));
			}
			this->trim();
		}

		template<std::ranges::range Range>
		requires(std::same_as<std::ranges::range_value_t<Range>, Limb_>)
		constexpr BigInteger(Range&& range, const bool negative = false) noexcept
		: data(std::ranges::begin(XIEITE_FORWARD(range)), std::ranges::end(XIEITE_FORWARD(range))), negative(negative) {
			this->trim();
		}

		constexpr BigInteger(const std::string_view value, const xieite::math::SignedSize radix = 10, const xieite::strings::NumberComponents components = xieite::strings::NumberComponents()) noexcept
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

		template<std::integral Integral_>
		[[nodiscard]] explicit constexpr operator Integral_() const noexcept {
			Integral_ result = 0;
			std::size_t i = 0;
			std::size_t j = 0;
			while (j < xieite::bits::size<Integral_>) {
				result |= static_cast<Integral_>(this->data[i]) << j;
				++i;
				j += xieite::bits::size<Limb_>;
			}
			return this->negative ? -result : result;
		}

		[[nodiscard]] explicit constexpr operator bool() const noexcept {
			return (this->data.size() > 1) || this->data[0];
		}

		[[nodiscard]] friend constexpr std::strong_ordering operator<=>(const xieite::math::BigInteger<Limb_>& leftComparand, const xieite::math::BigInteger<Limb_>& rightComparand) noexcept {
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

		template<std::integral Integral_>
		[[nodiscard]] friend constexpr std::strong_ordering operator<=>(const xieite::math::BigInteger<Limb_>& leftComparand, const Integral_ rightComparand) noexcept {
			return leftComparand <=> xieite::math::BigInteger<Limb_>(rightComparand);
		}

		[[nodiscard]] friend constexpr bool operator==(const xieite::math::BigInteger<Limb_>& leftComparand, const xieite::math::BigInteger<Limb_>& rightComparand) noexcept {
			return std::is_eq(leftComparand <=> rightComparand);
		}

		template<std::integral Integral_>
		[[nodiscard]] friend constexpr bool operator==(const xieite::math::BigInteger<Limb_>& leftComparand, const Integral_ rightComparand) noexcept {
			return leftComparand == xieite::math::BigInteger<Limb_>(rightComparand);
		}

		[[nodiscard]] constexpr xieite::math::BigInteger<Limb_> operator+() const noexcept {
			return *this;
		}

		[[nodiscard]] friend constexpr xieite::math::BigInteger<Limb_> operator+(const xieite::math::BigInteger<Limb_>& augend, const xieite::math::BigInteger<Limb_>& addend) noexcept {
			if (!augend) {
				return addend;
			}
			if (!addend) {
				return augend;
			}
			if (augend.negative != addend.negative) {
				return augend - (-addend);
			}
			std::vector<Limb_> resultData;
			bool carry = false;
			const std::size_t augendDataSize = augend.data.size();
			const std::size_t addendDataSize = addend.data.size();
			for (std::size_t i = 0; (i < augendDataSize) || (i < addendDataSize) || carry; ++i) {
				const Limb_ augendLimb_ = (i < augendDataSize) ? augend.data[i] : 0;
				const Limb_ addendLimb_ = (i < addendDataSize) ? addend.data[i] : 0;
				resultData.push_back(augendLimb_ + addendLimb_ + carry);
				carry = ((std::numeric_limits<Limb_>::max() - augendLimb_) < carry) || ((std::numeric_limits<Limb_>::max() - augendLimb_) < addendLimb_) || ((std::numeric_limits<Limb_>::max() - augendLimb_ - carry) < addendLimb_);
			}
			return xieite::math::BigInteger<Limb_>(resultData, augend.negative);
		}

		template<std::integral Integral_>
		[[nodiscard]] friend constexpr xieite::math::BigInteger<Limb_> operator+(const xieite::math::BigInteger<Limb_>& augend, const Integral_ addend) noexcept {
			return augend + xieite::math::BigInteger<Limb_>(addend);
		}

		constexpr xieite::math::BigInteger<Limb_>& operator+=(const xieite::math::BigInteger<Limb_>& addend) noexcept {
			return *this = *this + addend;
		}

		template<std::integral Integral_>
		constexpr xieite::math::BigInteger<Limb_>& operator+=(const Integral_ addend) noexcept {
			return *this += xieite::math::BigInteger<Limb_>(addend);
		}

		constexpr xieite::math::BigInteger<Limb_>& operator++() noexcept {
			return *this += 1;
		}

		constexpr xieite::math::BigInteger<Limb_> operator++(int) noexcept {
			xieite::math::BigInteger<Limb_> copy = *this;
			++*this;
			return copy;
		}

		[[nodiscard]] constexpr xieite::math::BigInteger<Limb_> operator-() const noexcept {
			xieite::math::BigInteger<Limb_> copy = *this;
			if (copy) {
				copy.negative = !copy.negative;
			}
			return copy;
		}

		[[nodiscard]] friend constexpr xieite::math::BigInteger<Limb_> operator-(const xieite::math::BigInteger<Limb_>& minuend, const xieite::math::BigInteger<Limb_>& subtrahend) noexcept {
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
			std::vector<Limb_> resultData;
			bool borrow = false;
			const std::size_t minuendDataSize = minuend.data.size();
			const std::size_t subtrahendDataSize = subtrahend.data.size();
			for (std::size_t i = 0; (i < subtrahendDataSize) || borrow; ++i) {
				const Limb_ subtrahendLimb_ = (i < subtrahendDataSize) ? subtrahend.data[i] : 0;
				resultData.push_back(minuend.data[i] - subtrahendLimb_ - borrow);
				borrow = (i < (minuendDataSize - 1)) && ((minuend.data[i] < borrow) || (minuend.data[i] < subtrahendLimb_) || ((minuend.data[i] - borrow) < subtrahendLimb_));
			}
			return xieite::math::BigInteger<Limb_>(resultData, minuend.negative);
		}

		template<std::integral Integral_>
		[[nodiscard]] friend constexpr xieite::math::BigInteger<Limb_> operator-(const xieite::math::BigInteger<Limb_>& minuend, const Integral_ subtrahend) noexcept {
			return minuend - xieite::math::BigInteger<Limb_>(subtrahend);
		}

		constexpr xieite::math::BigInteger<Limb_>& operator-=(const xieite::math::BigInteger<Limb_>& subtrahend) noexcept {
			return *this = *this - subtrahend;
		}

		template<std::integral Integral_>
		constexpr xieite::math::BigInteger<Limb_>& operator-=(const Integral_ subtrahend) noexcept {
			return *this -= xieite::math::BigInteger<Limb_>(subtrahend);
		}

		constexpr xieite::math::BigInteger<Limb_>& operator--() noexcept {
			return *this -= 1;
		}

		constexpr xieite::math::BigInteger<Limb_>& operator--(int) noexcept {
			xieite::math::BigInteger<Limb_> copy = *this;
			--*this;
			return copy;
		}

		[[nodiscard]] friend constexpr xieite::math::BigInteger<Limb_> operator*(const xieite::math::BigInteger<Limb_>& multiplier, const xieite::math::BigInteger<Limb_>& multiplicand) noexcept {
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
			xieite::math::BigInteger<Limb_> result;
			for (std::size_t i = multiplier.data.size(); i--;) {
				if (!multiplier.data[i]) {
					continue;
				}
				for (std::size_t j = multiplicand.data.size(); j--;) {
					if (!multiplicand.data[j]) {
						continue;
					}
					const xieite::math::Product<Limb_> product = xieite::math::multiply<Limb_>(multiplier.data[i], multiplicand.data[j]);
					result += ((xieite::math::BigInteger<Limb_>(product.upper) << xieite::bits::size<Limb_>) | product.lower) << (xieite::math::BigInteger<Limb_>(i) << xieite::math::digits<std::size_t>(xieite::bits::size<Limb_> - 1, 2)) << (xieite::math::BigInteger<Limb_>(j) << xieite::math::digits<std::size_t>(xieite::bits::size<Limb_> - 1, 2));
				}
			}
			result.negative = !sameSign;
			return result;
		}

		template<std::integral Integral_>
		[[nodiscard]] friend constexpr xieite::math::BigInteger<Limb_> operator*(const xieite::math::BigInteger<Limb_>& multiplier, const Integral_ multiplicand) noexcept {
			return multiplier * xieite::math::BigInteger<Limb_>(multiplicand);
		}

		constexpr xieite::math::BigInteger<Limb_>& operator*=(const xieite::math::BigInteger<Limb_>& multiplicand) noexcept {
			return *this = *this * multiplicand;
		}

		template<std::integral Integral_>
		constexpr xieite::math::BigInteger<Limb_>& operator*=(const Integral_ multiplicand) noexcept {
			return *this *= xieite::math::BigInteger<Limb_>(multiplicand);
		}

		[[nodiscard]] friend constexpr std::optional<xieite::math::BigInteger<Limb_>> operator/(const xieite::math::BigInteger<Limb_>& dividend, const xieite::math::BigInteger<Limb_>& divisor) noexcept {
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
			const xieite::math::BigInteger<Limb_> absoluteDividend = dividend.absolute();
			const xieite::math::BigInteger<Limb_> absoluteDivisor = divisor.absolute();
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
			xieite::math::BigInteger<Limb_> remainder;
			xieite::math::BigInteger<Limb_> result;
			remainder.data.resize(dividend.data.size(), 0);
			result.data.resize(dividend.data.size(), 0);
			for (std::size_t i = dividend.data.size(); i--;) {
				for (std::size_t j = xieite::bits::size<Limb_>; j--;) {
					remainder <<= 1;
					remainder.data[0] |= (dividend.data[i] >> j) & 1;
					const bool quotient = remainder >= absoluteDivisor;
					remainder -= absoluteDivisor * quotient;
					result.data[i] |= static_cast<Limb_>(quotient) << j;
				}
			}
			result.negative = !sameSign;
			result.trim();
			return result;
		}

		template<std::integral Integral_>
		[[nodiscard]] friend constexpr std::optional<xieite::math::BigInteger<Limb_>> operator/(const xieite::math::BigInteger<Limb_>& dividend, const Integral_ divisor) noexcept {
			return dividend / xieite::math::BigInteger<Limb_>(divisor);
		}

		constexpr xieite::math::BigInteger<Limb_> operator/=(const xieite::math::BigInteger<Limb_>& divisor) noexcept {
			return *this = (*this / divisor).value();
		}

		template<std::integral Integral_>
		constexpr xieite::math::BigInteger<Limb_> operator/=(const Integral_ divisor) noexcept {
			return *this /= xieite::math::BigInteger<Limb_>(divisor);
		}

		[[nodiscard]] friend constexpr std::optional<xieite::math::BigInteger<Limb_>> operator%(const xieite::math::BigInteger<Limb_>& dividend, const xieite::math::BigInteger<Limb_>& divisor) noexcept {
			if (!divisor) {
				return std::nullopt;
			}
			const xieite::math::BigInteger<Limb_> absoluteDividend = dividend.absolute();
			const xieite::math::BigInteger<Limb_> absoluteDivisor = divisor.absolute();
			if (!dividend || (absoluteDivisor == 1) || (absoluteDividend == absoluteDivisor)) {
				return 0;
			}
			if (absoluteDivisor.isPowerOf2()) {
				return (absoluteDividend & (absoluteDivisor - 1)) * xieite::math::splitBoolean(!dividend.negative);
			}
			if (absoluteDividend < absoluteDivisor) {
				return dividend;
			}
			xieite::math::BigInteger<Limb_> remainder;
			for (const Limb_ dividendLimb_ : std::views::reverse(dividend.data)) {
				for (std::size_t j = xieite::bits::size<Limb_>; j--;) {
					remainder <<= 1;
					remainder.data[0] |= (dividendLimb_ >> j) & 1;
					remainder -= absoluteDivisor * (remainder >= absoluteDivisor);
				}
			}
			remainder.negative = dividend.negative;
			return remainder;
		}

		template<std::integral Integral_>
		[[nodiscard]] friend constexpr std::optional<xieite::math::BigInteger<Limb_>> operator%(const xieite::math::BigInteger<Limb_>& dividend, const Integral_ divisor) {
			return dividend % xieite::math::BigInteger<Limb_>(divisor);
		}

		constexpr xieite::math::BigInteger<Limb_> operator%=(const xieite::math::BigInteger<Limb_>& divisor) {
			return *this = (*this % divisor).value();
		}

		template<std::integral Integral_>
		constexpr xieite::math::BigInteger<Limb_> operator%=(const Integral_ divisor) {
			return *this %= xieite::math::BigInteger<Limb_>(divisor);
		}

		[[nodiscard]] constexpr xieite::math::BigInteger<Limb_> operator~() const noexcept {
			return -(*this + 1);
		}

		[[nodiscard]] friend constexpr xieite::math::BigInteger<Limb_> operator&(const xieite::math::BigInteger<Limb_>& leftOperand, const xieite::math::BigInteger<Limb_>& rightOperand) noexcept {
			return xieite::math::BigInteger<Limb_>::bitwiseOperation(leftOperand, rightOperand, [](const Limb_ left, const Limb_ right) {
				return left & right;
			});
		}

		template<std::integral Integral_>
		[[nodiscard]] friend constexpr xieite::math::BigInteger<Limb_> operator&(const xieite::math::BigInteger<Limb_>& leftOperand, const Integral_ rightOperand) noexcept {
			return leftOperand & xieite::math::BigInteger<Limb_>(rightOperand);
		}

		constexpr xieite::math::BigInteger<Limb_>& operator&=(const xieite::math::BigInteger<Limb_>& operand) noexcept {
			return *this = *this & operand;
		}

		template<std::integral Integral_>
		constexpr xieite::math::BigInteger<Limb_>& operator&=(const Integral_ operand) noexcept {
			return *this &= xieite::math::BigInteger<Limb_>(operand);
		}

		[[nodiscard]] friend constexpr xieite::math::BigInteger<Limb_> operator|(const xieite::math::BigInteger<Limb_>& leftOperand, const xieite::math::BigInteger<Limb_>& rightOperand) noexcept {
			return xieite::math::BigInteger<Limb_>::bitwiseOperation(leftOperand, rightOperand, [](const Limb_ left, const Limb_ right) {
				return left | right;
			});
		}

		template<std::integral Integral_>
		[[nodiscard]] friend constexpr xieite::math::BigInteger<Limb_> operator|(const xieite::math::BigInteger<Limb_>& leftOperand, const Integral_ rightOperand) noexcept {
			return leftOperand | xieite::math::BigInteger<Limb_>(rightOperand);
		}

		constexpr xieite::math::BigInteger<Limb_>& operator|=(const xieite::math::BigInteger<Limb_>& operand) noexcept {
			return *this = *this | operand;
		}

		template<std::integral Integral_>
		constexpr xieite::math::BigInteger<Limb_>& operator|=(const Integral_ operand) noexcept {
			return *this |= xieite::math::BigInteger<Limb_>(operand);
		}

		[[nodiscard]] friend constexpr xieite::math::BigInteger<Limb_> operator^(const xieite::math::BigInteger<Limb_>& leftOperand, const xieite::math::BigInteger<Limb_>& rightOperand) noexcept {
			return xieite::math::BigInteger<Limb_>::bitwiseOperation(leftOperand, rightOperand, [](const Limb_ left, const Limb_ right) {
				return left ^ right;
			});
		}

		template<std::integral Integral_>
		[[nodiscard]] friend constexpr xieite::math::BigInteger<Limb_> operator^(const xieite::math::BigInteger<Limb_>& leftOperand, const Integral_ rightOperand) noexcept {
			return leftOperand ^ xieite::math::BigInteger<Limb_>(rightOperand);
		}

		constexpr xieite::math::BigInteger<Limb_>& operator^=(const xieite::math::BigInteger<Limb_>& operand) noexcept {
			return *this = *this ^ operand;
		}

		template<std::integral Integral_>
		constexpr xieite::math::BigInteger<Limb_>& operator^=(const Integral_ operand) noexcept {
			return *this ^= xieite::math::BigInteger<Limb_>(operand);
		}

		[[nodiscard]] friend constexpr xieite::math::BigInteger<Limb_> operator<<(const xieite::math::BigInteger<Limb_>& leftOperand, const xieite::math::BigInteger<Limb_>& rightOperand) noexcept {
			if (!leftOperand || !rightOperand) {
				return leftOperand;
			}
			if (rightOperand.negative) {
				return leftOperand >> -rightOperand;
			}
			const std::size_t dataShift = static_cast<std::size_t>(rightOperand) >> static_cast<std::size_t>(std::log2(xieite::bits::size<Limb_>));
			const std::size_t bitsShift = static_cast<std::size_t>(rightOperand) & (xieite::bits::size<Limb_> - 1);
			auto resultData = std::vector<Limb_>(dataShift, 0);
			resultData.insert(resultData.end(), leftOperand.data.begin(), leftOperand.data.end());
			if (bitsShift) {
				Limb_ carry = 0;
				const std::size_t leftDataSize = leftOperand.data.size();
				for (std::size_t i = 0; i < leftDataSize; ++i) {
					resultData[i + dataShift] = (leftOperand.data[i] << bitsShift) | carry;
					carry = leftOperand.data[i] >> (xieite::bits::size<Limb_> - bitsShift);
				}
				if (carry) {
					resultData.push_back(carry);
				}
			}
			return xieite::math::BigInteger<Limb_>(resultData, leftOperand.negative);
		}

		template<std::integral Integral_>
		[[nodiscard]] friend constexpr xieite::math::BigInteger<Limb_> operator<<(const xieite::math::BigInteger<Limb_>& leftOperand, const Integral_ rightOperand) noexcept {
			return leftOperand << xieite::math::BigInteger<Limb_>(rightOperand);
		}

		constexpr xieite::math::BigInteger<Limb_>& operator<<=(const xieite::math::BigInteger<Limb_>& operand) noexcept {
			return *this = *this << operand;
		}

		template<std::integral Integral_>
		constexpr xieite::math::BigInteger<Limb_>& operator<<=(const Integral_ operand) noexcept {
			return *this <<= xieite::math::BigInteger<Limb_>(operand);
		}

		[[nodiscard]] friend constexpr xieite::math::BigInteger<Limb_> operator>>(const xieite::math::BigInteger<Limb_>& leftOperand, const xieite::math::BigInteger<Limb_>& rightOperand) noexcept {
			if (!leftOperand || !rightOperand) {
				return leftOperand;
			}
			if (rightOperand.negative) {
				return leftOperand >> -rightOperand;
			}
			const std::size_t dataShift = static_cast<std::size_t>(rightOperand) >> static_cast<std::size_t>(std::log2(xieite::bits::size<Limb_>));
			const std::size_t bitsShift = static_cast<std::size_t>(rightOperand) & (xieite::bits::size<Limb_> - 1);
			const std::size_t leftDataSize = leftOperand.data.size();
			if (dataShift >= leftDataSize) {
				return 0;
			}
			auto resultData = std::vector<Limb_>(std::ranges::next(leftOperand.data.begin(), static_cast<xieite::math::SignedSize>(dataShift), leftOperand.data.end()), leftOperand.data.end());
			if (bitsShift) {
				Limb_ carry = 0;
				for (Limb_& resultLimb_ : std::views::reverse(resultData)) {
					const Limb_ copy = resultLimb_;
					resultLimb_ = (copy >> bitsShift) | carry;
					carry = copy << (xieite::bits::size<Limb_> - bitsShift);
				}
			}
			return xieite::math::BigInteger<Limb_>(resultData, leftOperand.negative) - leftOperand.negative;
		}

		template<std::integral Integral_>
		[[nodiscard]] friend constexpr xieite::math::BigInteger<Limb_> operator>>(const xieite::math::BigInteger<Limb_>& leftOperand, const Integral_ rightOperand) noexcept {
			return leftOperand >> xieite::math::BigInteger<Limb_>(rightOperand);
		}

		constexpr xieite::math::BigInteger<Limb_>& operator>>=(const xieite::math::BigInteger<Limb_>& operand) noexcept {
			return *this = *this >> operand;
		}

		template<std::integral Integral_>
		constexpr xieite::math::BigInteger<Limb_>& operator>>=(const Integral_ operand) noexcept {
			return *this >>= xieite::math::BigInteger<Limb_>(operand);
		}

		[[nodiscard]] constexpr xieite::math::BigInteger<Limb_> absolute() const noexcept {
			xieite::math::BigInteger<Limb_> copy = *this;
			copy.negative = false;
			return copy;
		}

		[[nodiscard]] constexpr std::optional<xieite::math::BigInteger<Limb_>> power(const xieite::math::BigInteger<Limb_>& exponent) const noexcept {
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
					return std::nullopt;
				}
				return !exponent;
			}
			xieite::math::BigInteger<Limb_> foo = *this;
			xieite::math::BigInteger<Limb_> bar = 1;
			xieite::math::BigInteger<Limb_> baz = exponent;
			while (baz > 1) {
				if (baz & 1) {
					bar *= foo;
					baz = (baz - 1) >> 1;
				} else {
					baz >>= 1;
				}
				foo *= foo;
			}
			return foo * bar;
		}

		template<std::integral Integral_>
		[[nodiscard]] constexpr std::optional<xieite::math::BigInteger<Limb_>> power(const Integral_ exponent) const {
			return this->power(xieite::math::BigInteger<Limb_>(exponent));
		}

		[[nodiscard]] constexpr std::optional<xieite::math::BigInteger<Limb_>> root(const xieite::math::BigInteger<Limb_>& degree) const noexcept {
			if (this->negative) {
				return std::nullopt;
			}
			if (*this == 1) {
				return *this;
			}
			if (degree.negative) {
				return 0;
			}
			xieite::math::BigInteger<Limb_> foo = degree - 1;
			xieite::math::BigInteger<Limb_> bar = *this;
			xieite::math::BigInteger<Limb_> baz = bar + 1;
			while (bar < baz) {
				baz = bar;
				bar = (foo * bar + *this / bar.power(foo)) / degree;
			}
			return baz;
		}

		template<std::integral Integral_>
		[[nodiscard]] constexpr std::optional<xieite::math::BigInteger<Limb_>> root(const Integral_ degree) const {
			return this->root(xieite::math::BigInteger<Limb_>(degree));
		}

		[[nodiscard]] constexpr std::optional<xieite::math::BigInteger<Limb_>> logarithm(const xieite::math::BigInteger<Limb_>& base) const noexcept {
			if (!base) {
				return 0;
			}
			if (this->negative || (base == 1) || base.negative) {
				return std::nullopt;
			}
			return this->logarithm2() / base.logarithm2();
		}

		template<std::integral Integral_>
		[[nodiscard]] constexpr std::optional<xieite::math::BigInteger<Limb_>> logarithm(const Integral_ base) const {
			return this->logarithm(xieite::math::BigInteger<Limb_>(base));
		}

		[[nodiscard]] constexpr std::string string(const xieite::math::SignedSize radix = 10, const xieite::strings::NumberComponents components = xieite::strings::NumberComponents()) const noexcept {
			if (!*this || !radix) {
				return std::string(1, components.digits[0]);
			}
			std::string result;
			xieite::math::BigInteger<Limb_> value = this->absolute();
			if (radix == 1) {
				result = std::string(static_cast<std::size_t>(value), components.digits[1]);
			} else if (radix == -1) {
				result = components.digits[1];
				std::size_t length = static_cast<std::size_t>(value);
				while (--length) {
					result += std::string(1, components.digits[0]) + components.digits[1];
				}
			} else {
				do {
					xieite::math::SignedSize index = static_cast<xieite::math::SignedSize>((value % radix).value());
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
		std::vector<Limb_> data;
		bool negative;

		template<typename Functor>
		[[nodiscard]] static constexpr xieite::math::BigInteger<Limb_> bitwiseOperation(xieite::math::BigInteger<Limb_> leftOperand, xieite::math::BigInteger<Limb_> rightOperand, Functor&& callback) noexcept {
			const bool leftNegative = leftOperand.negative;
			const bool rightNegative = rightOperand.negative;
			leftOperand += leftNegative;
			rightOperand += rightNegative;
			xieite::math::BigInteger<Limb_> result;
			result.data.clear();
			result.negative = callback(leftNegative, rightNegative);
			const std::size_t leftDataSize = leftOperand.data.size();
			const std::size_t rightDataSize = rightOperand.data.size();
			for (std::size_t i = 0; (i < leftDataSize) || (i < rightDataSize); ++i) {
				const Limb_ word = callback((i < leftDataSize) ? (leftNegative ? ~leftOperand.data[i] : leftOperand.data[i]) : (std::numeric_limits<Limb_>::max() * leftNegative), (i < rightDataSize) ? (rightNegative ? ~rightOperand.data[i] : rightOperand.data[i]) : (std::numeric_limits<Limb_>::max() * rightNegative));
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
			const xieite::math::BigInteger<Limb_> absolute = this->absolute();
			return absolute && !(absolute & (absolute - 1));
		}

		[[nodiscard]] constexpr xieite::math::BigInteger<Limb_> logarithm2() const noexcept {
			return xieite::math::BigInteger<Limb_>(xieite::bits::size<Limb_>) * (this->data.size() - 1) + xieite::math::digits<Limb_>(this->data.back(), 2) - 1;
		}
	};
}

#endif

// Thanks to sam_dev (https://github.com/Sam-programs) for fixing the new division algorithm
