export module xieite:math.BigInteger;

import std;
import :bits.size;
import :concepts.Arithmetic;
import :math.absolute;
import :math.additionOverflows;
import :math.DoubleInteger;
import :math.isNegative;
import :math.multiply;
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
		explicit constexpr BigInteger(const BigInteger<OtherLimb>& value) noexcept
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

		[[nodiscard]] friend constexpr std::strong_ordering operator<=>(const BigInteger& left, const BigInteger& right) noexcept {
			if (left.negative != right.negative) {
				return right.negative <=> left.negative;
			}
			if (left.negative) {
				if (left.data.size() != right.data.size()) {
					return right.data.size() <=> left.data.size();
				} else {
					return std::lexicographical_compare_three_way(right.data.rbegin(), right.data.rend(), left.data.rbegin(), left.data.rend());
				}
			}
			if (left.data.size() != right.data.size()) {
				return left.data.size() <=> right.data.size();
			} else {
				return std::lexicographical_compare_three_way(left.data.rbegin(), left.data.rend(), right.data.rbegin(), right.data.rend());
			}
		}

		template<std::integral Integral>
		[[nodiscard]] friend constexpr std::strong_ordering operator<=>(const BigInteger& left, const Integral right) noexcept {
			return left <=> BigInteger(right);
		}

		[[nodiscard]] friend constexpr bool operator==(const BigInteger& left, const BigInteger& right) noexcept {
			return std::is_eq(left <=> right);
		}

		template<std::integral Integral>
		[[nodiscard]] friend constexpr bool operator==(const BigInteger& left, const Integral right) noexcept {
			return left == BigInteger(right);
		}

		[[nodiscard]] constexpr BigInteger operator+() const noexcept {
			return *this;
		}

		[[nodiscard]] friend constexpr BigInteger operator+(const BigInteger& augend, const BigInteger& addend) noexcept {
			if (!augend) {
				return addend;
			}
			if (!addend) {
				return augend;
			}
			if (augend.negative != addend.negative) {
				return augend - (-addend);
			}
			std::vector<Limb> sumData;
			bool carry = false;
			const std::size_t augendDataSize = augend.data.size();
			const std::size_t addendDataSize = addend.data.size();
			for (std::size_t i = 0; (i < augendDataSize) || (i < addendDataSize) || carry; ++i) {
				const Limb augendLimb = (i < augendDataSize) ? augend.data[i] : 0;
				const Limb addendLimb = (i < addendDataSize) ? addend.data[i] : 0;
				sumData.push_back(augendLimb + addendLimb + carry);
				carry = xieite::math::additionOverflows(augendLimb, addendLimb, carry);
			}
			return BigInteger(sumData, augend.negative);
		}

		template<std::integral Integral>
		[[nodiscard]] friend constexpr BigInteger operator+(const BigInteger& augend, const Integral addend) noexcept {
			return augend + BigInteger(addend);
		}

		constexpr BigInteger& operator+=(const BigInteger& addend) noexcept {
			return *this = *this + addend;
		}

		template<std::integral Integral>
		constexpr BigInteger& operator+=(const Integral addend) noexcept {
			return *this += BigInteger(addend);
		}

		constexpr BigInteger& operator++() noexcept {
			return *this += 1;
		}

		constexpr BigInteger operator++(int) noexcept {
			return std::exchange(*this, *this + 1);
		}

		[[nodiscard]] constexpr BigInteger operator-() const noexcept {
			return BigInteger(this->data, !this->negative);
		}

		[[nodiscard]] friend constexpr BigInteger operator-(const BigInteger& minuend, const BigInteger& subtrahend) noexcept {
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
			std::vector<Limb> differenceData;
			bool borrow = false;
			const std::size_t minuendDataSize = minuend.data.size();
			const std::size_t subtrahendDataSize = subtrahend.data.size();
			for (std::size_t i = 0; (i < subtrahendDataSize) || borrow; ++i) {
				const Limb subtrahendLimb = (i < subtrahendDataSize) ? subtrahend.data[i] : 0;
				differenceData.push_back(minuend.data[i] - subtrahendLimb - borrow);
				borrow = (i < (minuendDataSize - 1)) && xieite::math::subtractionOverflows(minuend.data[i], subtrahendLimb, borrow);
			}
			return BigInteger(differenceData, minuend.negative);
		}

		template<std::integral Integral>
		[[nodiscard]] friend constexpr BigInteger operator-(const BigInteger& minuend, const Integral subtrahend) noexcept {
			return minuend - BigInteger(subtrahend);
		}

		constexpr BigInteger& operator-=(const BigInteger& subtrahend) noexcept {
			return *this = *this - subtrahend;
		}

		template<std::integral Integral>
		constexpr BigInteger& operator-=(const Integral subtrahend) noexcept {
			return *this -= BigInteger(subtrahend);
		}

		constexpr BigInteger& operator--() noexcept {
			return *this -= 1;
		}

		constexpr BigInteger& operator--(int) noexcept {
			return std::exchange(*this, *this - 1);
		}

		[[nodiscard]] friend constexpr BigInteger operator*(const BigInteger& multiplier, const BigInteger& multiplicand) noexcept {
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
			BigInteger product;
			for (std::size_t i = multiplier.data.size(); i--;) {
				if (!multiplier.data[i]) {
					continue;
				}
				for (std::size_t j = multiplicand.data.size(); j--;) {
					if (!multiplicand.data[j]) {
						continue;
					}
					const xieite::math::DoubleInteger<Limb> product = xieite::math::multiply(multiplier.data[i], multiplicand.data[j]);
					product += ((BigInteger(product.upper) << xieite::bits::size<Limb>) | product.lower) << (BigInteger(i) << std::bit_width(xieite::bits::size<Limb> - 1)) << (BigInteger(j) << std::bit_width(xieite::bits::size<Limb> - 1));
				}
			}
			product.negative = multiplier.negative != multiplicand.negative;
			return product;
		}

		template<std::integral Integral>
		[[nodiscard]] friend constexpr BigInteger operator*(const BigInteger& multiplier, const Integral multiplicand) noexcept {
			return multiplier * BigInteger(multiplicand);
		}

		constexpr BigInteger& operator*=(const BigInteger& multiplicand) noexcept {
			return *this = *this * multiplicand;
		}

		template<std::integral Integral>
		constexpr BigInteger& operator*=(const Integral multiplicand) noexcept {
			return *this *= BigInteger(multiplicand);
		}

		[[nodiscard]] friend constexpr BigInteger operator/(const BigInteger& dividend, const BigInteger& divisor) {
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
			const BigInteger absoluteDividend = dividend.absolute();
			const BigInteger absoluteDivisor = divisor.absolute();
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
			BigInteger remainder;
			BigInteger quotient;
			remainder.data.resize(dividend.data.size(), 0);
			quotient.data.resize(dividend.data.size(), 0);
			for (std::size_t i = dividend.data.size(); i--;) {
				for (std::size_t j = xieite::bits::size<Limb>; j--;) {
					remainder <<= 1;
					remainder.data[0] |= (dividend.data[i] >> j) & 1;
					const bool bit = remainder >= absoluteDivisor;
					remainder -= absoluteDivisor * bit;
					quotient.data[i] |= static_cast<Limb>(bit) << j;
				}
			}
			quotient.negative = !sameSign;
			quotient.trim();
			return quotient;
		}

		template<std::integral Integral>
		[[nodiscard]] friend constexpr BigInteger operator/(const BigInteger& dividend, const Integral divisor) {
			return dividend / BigInteger(divisor);
		}

		constexpr BigInteger operator/=(const BigInteger& divisor) {
			return *this = *this / divisor;
		}

		template<std::integral Integral>
		constexpr BigInteger operator/=(const Integral divisor) {
			return *this /= BigInteger(divisor);
		}

		[[nodiscard]] friend constexpr BigInteger operator%(const BigInteger& dividend, const BigInteger& divisor) {
			if (!divisor) {
				throw std::out_of_range("must not take remainder of division by zero");
			}
			const BigInteger absoluteDividend = dividend.absolute();
			const BigInteger absoluteDivisor = divisor.absolute();
			if (!dividend || (absoluteDivisor == 1) || (absoluteDividend == absoluteDivisor)) {
				return 0;
			}
			if (absoluteDivisor.isPowerOf2()) {
				return (absoluteDividend & (absoluteDivisor - 1)) * xieite::math::splitBoolean(!dividend.negative);
			}
			if (absoluteDividend < absoluteDivisor) {
				return dividend;
			}
			BigInteger remainder;
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
		[[nodiscard]] friend constexpr BigInteger operator%(const BigInteger& dividend, const Integral divisor) {
			return dividend % BigInteger(divisor);
		}

		constexpr BigInteger operator%=(const BigInteger& divisor) {
			return *this = *this % divisor;
		}

		template<std::integral Integral>
		constexpr BigInteger operator%=(const Integral divisor) {
			return *this %= BigInteger(divisor);
		}

		[[nodiscard]] constexpr BigInteger operator~() const noexcept {
			return -(*this + 1);
		}

		[[nodiscard]] friend constexpr BigInteger operator&(const BigInteger& left, const BigInteger& right) noexcept {
			return BigInteger::bitwiseOperation(left, right, std::bit_and());
		}

		template<std::integral Integral>
		[[nodiscard]] friend constexpr BigInteger operator&(const BigInteger& left, const Integral right) noexcept {
			return left & BigInteger(right);
		}

		constexpr BigInteger& operator&=(const BigInteger& operand) noexcept {
			return *this = *this & operand;
		}

		template<std::integral Integral>
		constexpr BigInteger& operator&=(const Integral operand) noexcept {
			return *this &= BigInteger(operand);
		}

		[[nodiscard]] friend constexpr BigInteger operator|(const BigInteger& left, const BigInteger& right) noexcept {
			return BigInteger::bitwiseOperation(left, right, std::bit_or());
		}

		template<std::integral Integral>
		[[nodiscard]] friend constexpr BigInteger operator|(const BigInteger& left, const Integral right) noexcept {
			return left | BigInteger(right);
		}

		constexpr BigInteger& operator|=(const BigInteger& operand) noexcept {
			return *this = *this | operand;
		}

		template<std::integral Integral>
		constexpr BigInteger& operator|=(const Integral operand) noexcept {
			return *this |= BigInteger(operand);
		}

		[[nodiscard]] friend constexpr BigInteger operator^(const BigInteger& left, const BigInteger& right) noexcept {
			return BigInteger::bitwiseOperation(left, right, std::bit_xor());
		}

		template<std::integral Integral>
		[[nodiscard]] friend constexpr BigInteger operator^(const BigInteger& left, const Integral right) noexcept {
			return left ^ BigInteger(right);
		}

		constexpr BigInteger& operator^=(const BigInteger& operand) noexcept {
			return *this = *this ^ operand;
		}

		template<std::integral Integral>
		constexpr BigInteger& operator^=(const Integral operand) noexcept {
			return *this ^= BigInteger(operand);
		}

		[[nodiscard]] friend constexpr BigInteger operator<<(const BigInteger& left, const BigInteger& right) noexcept {
			if (!left || !right) {
				return left;
			}
			if (right.negative) {
				return left >> -right;
			}
			const std::size_t dataShift = static_cast<std::size_t>(right) >> static_cast<std::size_t>(std::bit_width(xieite::bits::size<Limb>) - 1);
			const std::size_t bitsShift = static_cast<std::size_t>(right) & (xieite::bits::size<Limb> - 1);
			auto resultData = std::vector<Limb>(dataShift, 0);
			resultData.insert(resultData.end(), left.data.begin(), left.data.end());
			if (bitsShift) {
				Limb carry = 0;
				const std::size_t leftDataSize = left.data.size();
				for (std::size_t i = 0; i < leftDataSize; ++i) {
					resultData[i + dataShift] = (left.data[i] << bitsShift) | carry;
					carry = left.data[i] >> (xieite::bits::size<Limb> - bitsShift);
				}
				if (carry) {
					resultData.push_back(carry);
				}
			}
			return BigInteger(resultData, left.negative);
		}

		template<std::integral Integral>
		[[nodiscard]] friend constexpr BigInteger operator<<(const BigInteger& left, const Integral right) noexcept {
			return left << BigInteger(right);
		}

		constexpr BigInteger& operator<<=(const BigInteger& operand) noexcept {
			return *this = *this << operand;
		}

		template<std::integral Integral>
		constexpr BigInteger& operator<<=(const Integral operand) noexcept {
			return *this <<= BigInteger(operand);
		}

		[[nodiscard]] friend constexpr BigInteger operator>>(const BigInteger& left, const BigInteger& right) noexcept {
			if (!left || !right) {
				return left;
			}
			if (right.negative) {
				return left >> -right;
			}
			const std::size_t dataShift = static_cast<std::size_t>(right) >> static_cast<std::size_t>(std::bit_width(xieite::bits::size<Limb>) - 1);
			const std::size_t bitsShift = static_cast<std::size_t>(right) & (xieite::bits::size<Limb> - 1);
			const std::size_t leftDataSize = left.data.size();
			if (dataShift >= leftDataSize) {
				return 0;
			}
			auto resultData = std::vector<Limb>(std::ranges::next(left.data.begin(), static_cast<xieite::math::SignedSize>(dataShift), left.data.end()), left.data.end());
			if (bitsShift) {
				Limb carry = 0;
				for (Limb& resultLimb : std::views::reverse(resultData)) {
					const Limb copy = resultLimb;
					resultLimb = (copy >> bitsShift) | carry;
					carry = copy << (xieite::bits::size<Limb> - bitsShift);
				}
			}
			return BigInteger(resultData, left.negative) - left.negative;
		}

		template<std::integral Integral>
		[[nodiscard]] friend constexpr BigInteger operator>>(const BigInteger& left, const Integral right) noexcept {
			return left >> BigInteger(right);
		}

		constexpr BigInteger& operator>>=(const BigInteger& operand) noexcept {
			return *this = *this >> operand;
		}

		template<std::integral Integral>
		constexpr BigInteger& operator>>=(const Integral operand) noexcept {
			return *this >>= BigInteger(operand);
		}

		[[nodiscard]] constexpr BigInteger absolute() const noexcept {
			return BigInteger(this->data);
		}

		[[nodiscard]] constexpr BigInteger power(BigInteger exponent) const {
			if ((*this == 1) || (exponent == 1)) {
				return *this;
			}
			if (*this == -1) {
				return *this * xieite::math::splitBoolean(!!(exponent & 1));
			}
			if (!*this || !exponent) {
				if (exponent.negative) {
					throw std::out_of_range("must not take power of zero to negative exponent");
				}
				return !exponent;
			}
			BigInteger base = *this;
			BigInteger result = 1;
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
		[[nodiscard]] constexpr BigInteger power(const Integral exponent) const {
			return this->power(BigInteger(exponent));
		}

		[[nodiscard]] constexpr BigInteger root(const BigInteger& degree) const {
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
			BigInteger foo = degree - 1;
			BigInteger bar = *this;
			BigInteger baz = bar + 1;
			while (bar < baz) {
				baz = bar;
				bar = (foo * bar + *this / bar.power(foo)) / degree;
			}
			return baz;
		}

		template<std::integral Integral>
		[[nodiscard]] constexpr BigInteger root(const Integral degree) const {
			return this->root(BigInteger(degree));
		}

		[[nodiscard]] constexpr BigInteger logarithm(const BigInteger& base) const {
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
		[[nodiscard]] constexpr BigInteger logarithm(const Integral base) const {
			return this->logarithm(BigInteger(base));
		}

		[[nodiscard]] constexpr std::string string(const xieite::math::SignedSize radix = 10, const xieite::strings::NumberComponents components = xieite::strings::NumberComponents()) const noexcept {
			if (!*this || !radix) {
				return std::string(1, components.digits[0]);
			}
			std::string result;
			BigInteger value = this->absolute();
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

		[[nodiscard]] static constexpr BigInteger bitwiseOperation(BigInteger left, BigInteger right, const auto callback) noexcept {
			const bool leftNegative = left.negative;
			const bool rightNegative = right.negative;
			left += leftNegative;
			right += rightNegative;
			BigInteger result;
			result.data.clear();
			result.negative = static_cast<bool>(callback(leftNegative, rightNegative));
			const std::size_t leftDataSize = left.data.size();
			const std::size_t rightDataSize = right.data.size();
			for (std::size_t i = 0; (i < leftDataSize) || (i < rightDataSize); ++i) {
				const Limb word = callback((i < leftDataSize) ? (leftNegative ? ~left.data[i] : left.data[i]) : (std::numeric_limits<Limb>::max() * leftNegative), (i < rightDataSize) ? (rightNegative ? ~right.data[i] : right.data[i]) : (std::numeric_limits<Limb>::max() * rightNegative));
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
			const BigInteger absolute = this->absolute();
			return absolute && !(absolute & (absolute - 1));
		}

		[[nodiscard]] constexpr BigInteger logarithm2() const noexcept {
			return BigInteger(xieite::bits::size<Limb>) * (this->data.size() - 1) + std::bit_width(this->data.back()) - 1;
		}
	};
}
