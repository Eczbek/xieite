#ifndef XIEITE_HEADER_MATH_BIGINTEGER
#	define XIEITE_HEADER_MATH_BIGINTEGER

#	include <cmath>
#	include <compare>
#	include <concepts>
#	include <cstddef>
#	include <iterator>
#	include <ranges>
#	include <stdexcept>
#	include <string>
#	include <string_view>
#	include <utility>
#	include <vector>
#	include <xieite/concepts/Arithmetic.hpp>
#	include <xieite/concepts/Functable.hpp>
#	include <xieite/concepts/RangeOf.hpp>
#	include <xieite/math/absolute.hpp>

namespace xieite::math {
	class BigInteger {
	public:
		template<std::integral Integral = int>
		constexpr BigInteger(Integral value = 0) noexcept
		: sign(value < 0) {
			value = xieite::math::absolute(value);
			do {
				this->bits.push_back(value % 2);
				value /= 2;
			} while (value);
		}

		constexpr BigInteger(const xieite::math::BigInteger& value) noexcept
		: bits(value.bits), sign(value.sign) {}

		constexpr BigInteger(const xieite::concepts::RangeOf<bool> auto& bits, const bool sign = false) noexcept
		: bits(bits.begin(), bits.end()), sign(sign) {
			std::size_t i = std::ranges::size(this->bits);
			if (i) {
				while (!this->bits.back() && --i) {
					this->bits.pop_back();
				}
			} else {
				this->bits.push_back(false);
			}
			if ((i < 2) && !this->bits[0]) {
				this->sign = false;
			}
		}

		constexpr BigInteger(const std::string_view value) {
			const bool isNegative = value[0] == '-';
			const std::size_t valueSize = std::ranges::size(value);
			for (std::size_t i = isNegative; i < valueSize; ++i) {
				if ((value[i] < '0') || (value[i] > '9')) {
					throw std::invalid_argument("Cannot construct integer with non-digit character");
				}
				*this += xieite::math::BigInteger(10).power(valueSize - i - 1) * (value[i] - '0');
			}
			this->sign = ((std::ranges::size(this->bits) < 2) && !this->bits[0]) * isNegative;
		}

		constexpr xieite::math::BigInteger& operator=(const xieite::math::BigInteger& value) noexcept {
			this->bits = value.bits;
			this->sign = value.sign;
			return *this;
		}

		constexpr xieite::math::BigInteger& operator=(const std::integral auto value) noexcept {
			return *this = xieite::math::BigInteger(value);
		}

		template<xieite::concepts::Arithmetic Number>
		[[nodiscard]]
		constexpr operator Number() const noexcept {
			Number result = 0;
			Number exponent = 1;
			for (const bool bit : this->bits) {
				result += exponent * bit;
				exponent *= 2;
			}
			result *= !this->sign * 2 - 1;
			return result;
		}

		[[nodiscard]]
		constexpr operator bool() const noexcept {
			return *this != 0;
		}

		[[nodiscard]]
		constexpr bool operator==(const xieite::math::BigInteger& comparand) const noexcept {
			return (this->sign == comparand.sign) && (this->bits == comparand.bits);
		}
		
		[[nodiscard]]
		constexpr bool operator==(const std::integral auto comparand) const noexcept {
			return *this == xieite::math::BigInteger(comparand);
		}

		[[nodiscard]]
		constexpr std::strong_ordering operator<=>(const xieite::math::BigInteger& comparand) const noexcept {
			return (this->sign != comparand.sign) ? (comparand.sign <=> this->sign) : (this->sign ? ((std::ranges::size(this->bits) != std::ranges::size(comparand.bits)) ? (std::ranges::size(comparand.bits) <=> std::ranges::size(this->bits)) : (std::vector<bool>(std::ranges::rbegin(comparand.bits), std::ranges::rend(comparand.bits)) <=> std::vector<bool>(std::ranges::rbegin(this->bits), std::ranges::rend(this->bits)))) : ((std::ranges::size(this->bits) != std::ranges::size(comparand.bits)) ? (std::ranges::size(this->bits) <=> std::ranges::size(comparand.bits)) : (std::vector<bool>(std::ranges::rbegin(this->bits), std::ranges::rend(this->bits)) <=> std::vector<bool>(std::ranges::rbegin(comparand.bits), std::ranges::rend(comparand.bits)))));
		}

		[[nodiscard]]
		constexpr std::strong_ordering operator<=>(const std::integral auto comparand) const noexcept {
			return *this <=> xieite::math::BigInteger(comparand);
		}

		[[nodiscard]]
		constexpr xieite::math::BigInteger operator+() const noexcept {
			return *this;
		}

		[[nodiscard]]
		constexpr xieite::math::BigInteger operator+(const xieite::math::BigInteger& addend) const noexcept {
			if (this->sign != addend.sign) {
				return *this - (-addend);
			}
			if (!*this) {
				return addend;
			}
			if (!addend) {
				return *this;
			}
			std::vector<bool> resultBits;
			bool carry = false;
			const std::size_t bitsSize = std::ranges::size(this->bits);
			const std::size_t addendBitsSize = std::ranges::size(addend.bits);
			for (std::size_t i = 0; (i < bitsSize) || (i < addendBitsSize) || carry; ++i) {
				int sum = carry;
				if (i < bitsSize) {
					sum += this->bits[i];
				}
				if (i < addendBitsSize) {
					sum += addend.bits[i];
				}
				carry = sum > 1;
				resultBits.push_back(sum % 2);
			}
			return xieite::math::BigInteger(resultBits, this->sign);
		}

		[[nodiscard]]
		constexpr xieite::math::BigInteger operator+(const std::integral auto addend) const noexcept {
			return *this + xieite::math::BigInteger(addend);
		}

		constexpr xieite::math::BigInteger& operator+=(const xieite::math::BigInteger& addend) noexcept {
			return *this = *this + addend;
		}

		constexpr xieite::math::BigInteger& operator+=(const std::integral auto addend) noexcept {
			return *this += xieite::math::BigInteger(addend);
		}

		constexpr xieite::math::BigInteger& operator++() noexcept {
			return *this += 1;
		}

		constexpr xieite::math::BigInteger operator++(int) noexcept {
			const xieite::math::BigInteger copy = *this;
			++*this;
			return copy;
		}

		[[nodiscard]]
		constexpr xieite::math::BigInteger operator-() const noexcept {
			xieite::math::BigInteger copy = *this;
			if (copy) {
				copy.sign = !copy.sign;
			}
			return copy;
		}

		[[nodiscard]]
		constexpr xieite::math::BigInteger operator-(const xieite::math::BigInteger& subtrahend) const noexcept {
			if (!subtrahend) {
				return *this;
			}
			if (this->sign != subtrahend.sign) {
				return *this + (-subtrahend);
			}
			if (this->sign && (*this > subtrahend) || !this->sign && (*this < subtrahend)) {
				return -(subtrahend - *this);
			}
			std::vector<bool> resultBits = this->bits;
			bool borrow = false;
			const std::size_t bitsSize = std::ranges::size(this->bits);
			const std::size_t subtrahendBitsSize = std::ranges::size(subtrahend.bits);
			for (std::size_t i = 0; (i < subtrahendBitsSize) || borrow; ++i) {
				int difference = 2 - borrow + this->bits[i];
				if (i < subtrahendBitsSize) {
					difference -= subtrahend.bits[i];
				}
				borrow = (i < bitsSize - 1) && (difference < 2);
				resultBits[i] = difference % 2;
			}
			return xieite::math::BigInteger(resultBits, this->sign != borrow);
		}

		[[nodiscard]]
		constexpr xieite::math::BigInteger operator-(const std::integral auto subtrahend) const noexcept {
			return *this - xieite::math::BigInteger(subtrahend);
		}

		constexpr xieite::math::BigInteger& operator-=(const xieite::math::BigInteger& subtrahend) noexcept {
			return *this = *this - subtrahend;
		}

		constexpr xieite::math::BigInteger& operator-=(const std::integral auto subtrahend) noexcept {
			return *this -= xieite::math::BigInteger(subtrahend);
		}

		constexpr xieite::math::BigInteger& operator--() noexcept {
			return *this -= 1;
		}

		constexpr xieite::math::BigInteger operator--(int) noexcept {
			const xieite::math::BigInteger copy = *this;
			--*this;
			return copy;
		}

		[[nodiscard]]
		constexpr xieite::math::BigInteger operator*(const xieite::math::BigInteger& multiplicand) const noexcept {
			if (!*this || !multiplicand) {
				return xieite::math::BigInteger(0);
			}
			if (*this == 1) {
				return multiplicand;
			}
			if (multiplicand == 1) {
				return *this;
			}
			if (*this == -1) {
				return -multiplicand;
			}
			if (multiplicand == -1) {
				return -*this;
			}
			const std::size_t halfSize = std::min(std::ranges::size(this->bits), std::ranges::size(multiplicand.bits)) / 2;
			const std::vector<bool>::const_iterator i = std::ranges::next(std::ranges::begin(this->bits), halfSize);
			const xieite::math::BigInteger a = xieite::math::BigInteger(std::vector<bool>(std::ranges::begin(this->bits), i));
			const xieite::math::BigInteger b = xieite::math::BigInteger(std::vector<bool>(i, std::ranges::end(this->bits)));
			const std::vector<bool>::const_iterator j = std::ranges::next(std::ranges::begin(multiplicand.bits), halfSize);
			const xieite::math::BigInteger c = xieite::math::BigInteger(std::vector<bool>(std::ranges::begin(multiplicand.bits), j));
			const xieite::math::BigInteger d = xieite::math::BigInteger(std::vector<bool>(j, std::ranges::end(multiplicand.bits)));
			const xieite::math::BigInteger e = a * c;
			const xieite::math::BigInteger f = (a + b) * (c + d);
			const xieite::math::BigInteger g = b * d;
			xieite::math::BigInteger result = (g << (halfSize * 2)) + ((f - g - e) << halfSize) + e;
			result.sign = this->sign != multiplicand.sign;
			return result;
		}

		[[nodiscard]]
		constexpr xieite::math::BigInteger operator*(const std::integral auto multiplicand) const noexcept {
			return *this * xieite::math::BigInteger(multiplicand);
		}

		constexpr xieite::math::BigInteger& operator*=(const xieite::math::BigInteger& multiplicand) noexcept {
			return *this = *this * multiplicand;
		}

		constexpr xieite::math::BigInteger& operator*=(const std::integral auto multiplicand) noexcept {
			return *this *= xieite::math::BigInteger(multiplicand);
		}

		[[nodiscard]]
		constexpr xieite::math::BigInteger operator/(const xieite::math::BigInteger& divisor) const {
			if (!divisor) {
				throw std::domain_error("Cannot divide by zero");
			}
			if (divisor == 1) {
				return *this;
			}
			if (divisor == -1) {
				return -*this;
			}
			const bool divisorSign = divisor.sign;
            const xieite::math::BigInteger divisorCopy = divisor.absolute();
			if (this->absolute() < divisorCopy) {
				return xieite::math::BigInteger(0);
			}
			std::vector<bool> resultBits;
			xieite::math::BigInteger difference;
			for (std::size_t i = std::ranges::size(this->bits); i--;) {
				if (!difference) {
					difference.bits.clear();
				}
				difference.bits.insert(std::ranges::begin(difference.bits), this->bits[i]);
				const bool quotient = difference >= divisorCopy;
				if (quotient) {
					difference -= divisorCopy;
				}
				resultBits.insert(std::ranges::begin(resultBits), quotient);
			}
			return xieite::math::BigInteger(resultBits, this->sign != divisorSign);
		}

		[[nodiscard]]
		constexpr xieite::math::BigInteger operator/(const std::integral auto divisor) const {
			return *this / xieite::math::BigInteger(divisor);
		}

		constexpr xieite::math::BigInteger& operator/=(const xieite::math::BigInteger& divisor) {
			return *this = *this / divisor;
		}

		constexpr xieite::math::BigInteger& operator/=(const std::integral auto divisor) {
			return *this /= xieite::math::BigInteger(divisor);
		}

		[[nodiscard]]
		constexpr xieite::math::BigInteger operator%(const xieite::math::BigInteger& divisor) const {
			if (!divisor) {
				throw std::domain_error("Cannot take modulus of zero");
			}
			const xieite::math::BigInteger copy = this->absolute();
			const xieite::math::BigInteger divisorCopy = divisor.absolute();
			if (!*this || (divisorCopy == 1) || (copy == divisorCopy)) {
				return xieite::math::BigInteger(0);
			}
			if (copy < divisorCopy) {
				return *this;
			}
			xieite::math::BigInteger difference;
			for (std::size_t i = std::ranges::size(this->bits); i--;) {
				if (!difference) {
					difference.bits.clear();
				}
				difference.bits.insert(std::ranges::begin(difference.bits), this->bits[i]);
				if (difference >= divisorCopy) {
					difference -= divisorCopy;
				}
			}
			difference.sign = this->sign;
			return difference;
		}

		[[nodiscard]]
		constexpr xieite::math::BigInteger operator%(const std::integral auto divisor) const {
			return *this % xieite::math::BigInteger(divisor);
		}

		constexpr xieite::math::BigInteger& operator%=(const xieite::math::BigInteger& divisor) {
			return *this = *this % divisor;
		}

		constexpr xieite::math::BigInteger& operator%=(const std::integral auto divisor) {
			return *this %= xieite::math::BigInteger(divisor);
		}

		[[nodiscard]]
		constexpr xieite::math::BigInteger operator~() const noexcept {
			return -(*this + 1);
		}

		[[nodiscard]]
		constexpr xieite::math::BigInteger operator&(const xieite::math::BigInteger& operand) const noexcept {
			return (!*this || !operand) ? xieite::math::BigInteger(0) : this->commonBitwiseOperation(operand, [](const bool left, const bool right) noexcept -> bool {
				return left && right;
			});
		}

		[[nodiscard]]
		constexpr xieite::math::BigInteger operator&(const std::integral auto operand) const noexcept {
			return *this & xieite::math::BigInteger(operand);
		}

		constexpr xieite::math::BigInteger& operator&=(const xieite::math::BigInteger& operand) noexcept {
			return *this = *this & operand;
		}

		constexpr xieite::math::BigInteger& operator&=(const std::integral auto operand) noexcept {
			return *this &= xieite::math::BigInteger(operand);
		}

		[[nodiscard]]
		constexpr xieite::math::BigInteger operator|(const xieite::math::BigInteger& operand) const noexcept {
			return !*this ? operand : (!operand ? *this : this->commonBitwiseOperation(operand, [](const bool left, const bool right) noexcept -> bool {
				return left || right;
			}));
		}

		[[nodiscard]]
		constexpr xieite::math::BigInteger operator|(const std::integral auto operand) const noexcept {
			return *this | xieite::math::BigInteger(operand);
		}

		constexpr xieite::math::BigInteger& operator|=(const xieite::math::BigInteger& operand) noexcept {
			return *this = *this | operand;
		}

		constexpr xieite::math::BigInteger& operator|=(const std::integral auto operand) noexcept {
			return *this |= xieite::math::BigInteger(operand);
		}

		[[nodiscard]]
		constexpr xieite::math::BigInteger operator^(const xieite::math::BigInteger& operand) const noexcept {
			return !*this ? operand : (!operand ? *this : this->commonBitwiseOperation(operand, [](const bool left, const bool right) noexcept -> bool {
				return left != right;
			}));
		}

		[[nodiscard]]
		constexpr xieite::math::BigInteger operator^(const std::integral auto operand) const noexcept {
			return *this ^ xieite::math::BigInteger(operand);
		}

		constexpr xieite::math::BigInteger& operator^=(const xieite::math::BigInteger& operand) noexcept {
			return *this = *this ^ operand;
		}

		constexpr xieite::math::BigInteger& operator^=(const std::integral auto operand) noexcept {
			return *this ^= xieite::math::BigInteger(operand);
		}

		[[nodiscard]]
		constexpr xieite::math::BigInteger operator<<(const xieite::math::BigInteger& positions) const noexcept {
			if (positions.sign || !*this) {
				return xieite::math::BigInteger(0);
			}
			if (!positions) {
				return *this;
			}
			std::vector<bool> resultBits = std::vector<bool>(static_cast<std::size_t>(positions));
			resultBits.insert(std::ranges::end(resultBits), std::ranges::begin(this->bits), std::ranges::end(this->bits));
			return xieite::math::BigInteger(resultBits, this->sign);
		}

		[[nodiscard]]
		constexpr xieite::math::BigInteger operator<<(const std::integral auto positions) const noexcept {
			return *this << xieite::math::BigInteger(positions);
		}

		constexpr xieite::math::BigInteger& operator<<=(const xieite::math::BigInteger& positions) noexcept {
			return *this = *this << positions;
		}

		constexpr xieite::math::BigInteger& operator<<=(const std::integral auto positions) noexcept {
			return *this <<= xieite::math::BigInteger(positions);
		}

		[[nodiscard]]
		constexpr xieite::math::BigInteger operator>>(const xieite::math::BigInteger& positions) const noexcept {
			if (!this->sign && positions.sign || !*this) {
				return xieite::math::BigInteger(0);
			}
			if (!positions) {
				return *this;
			}
			std::vector<bool> resultBits = this->bits;
			std::vector<bool>::iterator end = std::ranges::begin(resultBits);
			resultBits.erase(std::ranges::begin(resultBits), std::ranges::next(std::ranges::begin(resultBits), static_cast<std::size_t>(positions)));
			xieite::math::BigInteger result = xieite::math::BigInteger(resultBits, this->sign);
			return result ? result : -xieite::math::BigInteger(this->sign);
		}

		[[nodiscard]]
		constexpr xieite::math::BigInteger operator>>(const std::integral auto positions) const noexcept {
			return *this >> xieite::math::BigInteger(positions);
		}

		constexpr xieite::math::BigInteger operator>>=(const xieite::math::BigInteger& positions) noexcept {
			return *this = *this >> positions;
		}

		constexpr xieite::math::BigInteger operator>>=(const std::integral auto positions) noexcept {
			return *this >>= xieite::math::BigInteger(positions);
		}

		[[nodiscard]]
		constexpr xieite::math::BigInteger absolute() const noexcept {
			xieite::math::BigInteger copy = *this;
			copy.sign = false;
			return copy;
		}

		[[nodiscard]]
		constexpr xieite::math::BigInteger power(xieite::math::BigInteger exponent) const {
			if ((*this == 1) || (exponent == 1)) {
				return *this;
			}
			if (*this == -1) {
				return *this * (exponent % 2) * 2 - 1;
			}
			if (!exponent) {
				return xieite::math::BigInteger(1);
			}
			if (exponent.sign) {
				if (!*this) {
					throw std::domain_error("Cannot take power of zero to negative exponent");
				}
				return !exponent;
			}
			if (!*this) {
				return !exponent;
			}
			xieite::math::BigInteger x = *this;
			xieite::math::BigInteger y = 1;
			while (exponent > 1) {
				if (exponent % 2) {
					y *= x;
					exponent = (exponent - 1) / 2;
				} else {
					exponent /= 2;
				}
				x *= x;
			}
			return x * y;
		}

		[[nodiscard]]
		constexpr xieite::math::BigInteger power(const std::integral auto exponent) const {
			return this->power(xieite::math::BigInteger(exponent));
		}

		[[nodiscard]]
		constexpr xieite::math::BigInteger root(const xieite::math::BigInteger& degree) const {
			if (this->sign) {
				throw std::domain_error("Cannot take root of negative radicand");
			}
			if (*this == 1) {
				return xieite::math::BigInteger(1);
			}
			if (degree.sign) {
				return xieite::math::BigInteger(0);
			}
			xieite::math::BigInteger x = degree - 1;
			xieite::math::BigInteger y = *this;
			xieite::math::BigInteger z = y + 1;
			while (y < z) {
				z = y;
				y = (x * y + *this / y.power(x)) / degree;
			}
			return z;
		}

		[[nodiscard]]
		constexpr xieite::math::BigInteger root(const std::integral auto degree) const {
			return this->root(xieite::math::BigInteger(degree));
		}

		[[nodiscard]]
		constexpr xieite::math::BigInteger logarithm(const xieite::math::BigInteger& base) const {
			if (!base) {
				return base;
			}
			if (*this < 0) {
				throw std::domain_error("Cannot take logarithm of negative value");
			}
			if (base == 1) {
				throw std::domain_error("Cannot take logarithm of first base");
			}
			if (base < 0) {
				throw std::domain_error("Cannot take logarithm of negative base");
			}
			return (std::ranges::size(this->bits) - 1) / (std::ranges::size(base.bits) - 1);
		}

		[[nodiscard]]
		constexpr xieite::math::BigInteger logarithm(const std::integral auto base) const {
			return this->logarithm(xieite::math::BigInteger(base));
		}

		[[nodiscard]]
		constexpr const std::vector<bool>& data() const noexcept {
			return this->bits;
		}

		[[nodiscard]]
		constexpr std::string string() const noexcept {
			if (!*this) {
				return "0";
			}
			xieite::math::BigInteger copy = this->absolute();
			std::string result;
			do {
				result = static_cast<char>(copy % 10 + '0') + result;
				copy /= 10;
			} while (copy);
			if (this->sign) {
				result = '-' + result;
			}
			return result;
		}
	
	private:
		std::vector<bool> bits;
		bool sign;

		[[nodiscard]]
		constexpr xieite::math::BigInteger commonBitwiseOperation(const xieite::math::BigInteger& value, const xieite::concepts::Functable<bool(bool, bool)> auto& callback) const noexcept {
			xieite::math::BigInteger copy = *this;
			const std::size_t bitsSize = std::ranges::size(this->bits);
			if (this->sign) {
				++copy;
				for (std::size_t i = 0; i < bitsSize; ++i) {
					copy.bits[i] = !copy.bits[i];
				}
			}
			xieite::math::BigInteger valueCopy = value;
			const std::size_t valueBitsSize = std::ranges::size(value.bits);
			if (value.sign) {
				++valueCopy;
				for (std::size_t i = 0; i < valueBitsSize; ++i) {
					valueCopy.bits[i] = !valueCopy.bits[i];
				}
			}
			xieite::math::BigInteger result;
			result.bits.clear();
			result.sign = this->sign && value.sign;
			for (std::size_t i = 0; (i < bitsSize) || (i < valueBitsSize); ++i) {
				result.bits.push_back(callback((i < bitsSize) ? copy.bits[i] : this->sign, (i < valueBitsSize) ? valueCopy.bits[i] : value.sign));
			}
			if (result.sign) {
				for (std::size_t i = 0; (i < bitsSize) || (i < valueBitsSize); ++i) {
					result.bits[i] = !result.bits[i];
				}
				--result;
			}
			return result;
		}
	};
}

#endif
