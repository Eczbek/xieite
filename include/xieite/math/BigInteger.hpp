#ifndef XIEITE_HEADER_MATH_BIGINTEGER
#	define XIEITE_HEADER_MATH_BIGINTEGER

#	include <compare>
#	include <concepts>
#	include <cstddef>
#	include <iterator>
#	include <ranges>
#	include <stdexcept>
#	include <string>
#	include <string_view>
#	include <type_traits>
#	include <utility>
#	include <vector>
#	include "../concepts/Arithmetic.hpp"
#	include "../concepts/Functable.hpp"
#	include "../concepts/RangeOf.hpp"
#	include "../math/absolute.hpp"
#	include "../types/bits.hpp"

namespace xieite::math {
	class BigInteger {
	public:
		template<std::integral Integral = int>
		constexpr BigInteger(const Integral value = 0) noexcept
		: sign(value < 0) {
			std::make_unsigned_t<Integral> absolute = xieite::math::absolute(value);
			do {
				this->bits.push_back(absolute % 2);
				absolute /= 2;
			} while (absolute);
		}

		constexpr BigInteger(const xieite::math::BigInteger& value) noexcept
		: bits(value.bits), sign(value.sign) {}

		template<xieite::concepts::RangeOf<bool> BooleanRange>
		constexpr BigInteger(const BooleanRange& bits, const bool sign = false) noexcept
		: bits(std::ranges::begin(bits), std::ranges::end(bits)), sign(sign) {
			std::size_t i = this->bits.size();
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
			const std::size_t valueSize = value.size();
			for (std::size_t i = isNegative; i < valueSize; ++i) {
				if ((value[i] < '0') || (value[i] > '9')) {
					throw std::invalid_argument("Cannot construct integer with non-digit character");
				}
				*this += xieite::math::BigInteger(10).power(valueSize - i - 1) * (value[i] - '0');
			}
			this->sign = ((this->bits.size() < 2) && !this->bits[0]) * isNegative;
		}

		constexpr xieite::math::BigInteger& operator=(const xieite::math::BigInteger& value) noexcept {
			this->bits = value.bits;
			this->sign = value.sign;
			return *this;
		}

		template<std::integral Integral>
		constexpr xieite::math::BigInteger& operator=(const Integral value) noexcept {
			return *this = xieite::math::BigInteger(value);
		}

		template<xieite::concepts::Arithmetic Arithmetic>
		[[nodiscard]]
		constexpr operator Arithmetic() const noexcept {
			Arithmetic result = 0;
			Arithmetic power = 1;
			for (std::size_t i = 0; i < xieite::types::bits<Arithmetic>; ++i) {
				result += power * this->bits[i];
				power *= 2;
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

		template<std::integral Integral>
		[[nodiscard]]
		constexpr bool operator==(const Integral comparand) const noexcept {
			return *this == xieite::math::BigInteger(comparand);
		}

		[[nodiscard]]
		constexpr std::strong_ordering operator<=>(const xieite::math::BigInteger& comparand) const noexcept {
			return (this->sign != comparand.sign) ? (comparand.sign <=> this->sign) : (this->sign ? ((this->bits.size() != comparand.bits.size()) ? (comparand.bits.size() <=> this->bits.size()) : (std::vector<bool>(comparand.bits.rbegin(), comparand.bits.rend()) <=> std::vector<bool>(this->bits.rbegin(), this->bits.rend()))) : ((this->bits.size() != comparand.bits.size()) ? (this->bits.size() <=> comparand.bits.size()) : (std::vector<bool>(this->bits.rbegin(), this->bits.rend()) <=> std::vector<bool>(comparand.bits.rbegin(), comparand.bits.rend()))));
		}

		template<std::integral Integral>
		[[nodiscard]]
		constexpr std::strong_ordering operator<=>(const Integral comparand) const noexcept {
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
			const std::size_t bitsSize = this->bits.size();
			const std::size_t addendBitsSize = addend.bits.size();
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

		template<std::integral Integral>
		[[nodiscard]]
		constexpr xieite::math::BigInteger operator+(const Integral addend) const noexcept {
			return *this + xieite::math::BigInteger(addend);
		}

		constexpr xieite::math::BigInteger& operator+=(const xieite::math::BigInteger& addend) noexcept {
			return *this = *this + addend;
		}

		template<std::integral Integral>
		constexpr xieite::math::BigInteger& operator+=(const Integral addend) noexcept {
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
			const std::size_t bitsSize = this->bits.size();
			const std::size_t subtrahendBitsSize = subtrahend.bits.size();
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

		template<std::integral Integral>
		[[nodiscard]]
		constexpr xieite::math::BigInteger operator-(const Integral subtrahend) const noexcept {
			return *this - xieite::math::BigInteger(subtrahend);
		}

		constexpr xieite::math::BigInteger& operator-=(const xieite::math::BigInteger& subtrahend) noexcept {
			return *this = *this - subtrahend;
		}

		template<std::integral Integral>
		constexpr xieite::math::BigInteger& operator-=(const Integral subtrahend) noexcept {
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
			const std::size_t halfSize = std::min(this->bits.size(), multiplicand.bits.size()) / 2;
			const std::vector<bool>::const_iterator i = std::ranges::next(this->bits.begin(), halfSize);
			const xieite::math::BigInteger a = xieite::math::BigInteger(std::vector<bool>(this->bits.begin(), i));
			const xieite::math::BigInteger b = xieite::math::BigInteger(std::vector<bool>(i, this->bits.end()));
			const std::vector<bool>::const_iterator j = std::ranges::next(multiplicand.bits.begin(), halfSize);
			const xieite::math::BigInteger c = xieite::math::BigInteger(std::vector<bool>(multiplicand.bits.begin(), j));
			const xieite::math::BigInteger d = xieite::math::BigInteger(std::vector<bool>(j, multiplicand.bits.end()));
			const xieite::math::BigInteger e = a * c;
			const xieite::math::BigInteger f = (a + b) * (c + d);
			const xieite::math::BigInteger g = b * d;
			xieite::math::BigInteger result = (g << (halfSize * 2)) + ((f - g - e) << halfSize) + e;
			result.sign = this->sign != multiplicand.sign;
			return result;
		}
		// I absolutely despise recursion

		template<std::integral Integral>
		[[nodiscard]]
		constexpr xieite::math::BigInteger operator*(const Integral multiplicand) const noexcept {
			return *this * xieite::math::BigInteger(multiplicand);
		}

		constexpr xieite::math::BigInteger& operator*=(const xieite::math::BigInteger& multiplicand) noexcept {
			return *this = *this * multiplicand;
		}

		template<std::integral Integral>
		constexpr xieite::math::BigInteger& operator*=(const Integral multiplicand) noexcept {
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
			for (std::size_t i = this->bits.size(); i--;) {
				if (!difference) {
					difference.bits.clear();
				}
				difference.bits.insert(difference.bits.begin(), this->bits[i]);
				const bool quotient = difference >= divisorCopy;
				if (quotient) {
					difference -= divisorCopy;
				}
				resultBits.insert(resultBits.begin(), quotient);
			}
			return xieite::math::BigInteger(resultBits, this->sign != divisorSign);
		}

		template<std::integral Integral>
		[[nodiscard]]
		constexpr xieite::math::BigInteger operator/(const Integral divisor) const {
			return *this / xieite::math::BigInteger(divisor);
		}

		constexpr xieite::math::BigInteger& operator/=(const xieite::math::BigInteger& divisor) {
			return *this = *this / divisor;
		}

		template<std::integral Integral>
		constexpr xieite::math::BigInteger& operator/=(const Integral divisor) {
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
			for (std::size_t i = this->bits.size(); i--;) {
				if (!difference) {
					difference.bits.clear();
				}
				difference.bits.insert(difference.bits.begin(), this->bits[i]);
				if (difference >= divisorCopy) {
					difference -= divisorCopy;
				}
			}
			difference.sign = this->sign;
			return difference;
		}

		template<std::integral Integral>
		[[nodiscard]]
		constexpr xieite::math::BigInteger operator%(const Integral divisor) const {
			return *this % xieite::math::BigInteger(divisor);
		}

		constexpr xieite::math::BigInteger& operator%=(const xieite::math::BigInteger& divisor) {
			return *this = *this % divisor;
		}

		template<std::integral Integral>
		constexpr xieite::math::BigInteger& operator%=(const Integral divisor) {
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

		template<std::integral Integral>
		[[nodiscard]]
		constexpr xieite::math::BigInteger operator&(const Integral operand) const noexcept {
			return *this & xieite::math::BigInteger(operand);
		}

		constexpr xieite::math::BigInteger& operator&=(const xieite::math::BigInteger& operand) noexcept {
			return *this = *this & operand;
		}

		template<std::integral Integral>
		constexpr xieite::math::BigInteger& operator&=(const Integral operand) noexcept {
			return *this &= xieite::math::BigInteger(operand);
		}

		[[nodiscard]]
		constexpr xieite::math::BigInteger operator|(const xieite::math::BigInteger& operand) const noexcept {
			return !*this ? operand : (!operand ? *this : this->commonBitwiseOperation(operand, [](const bool left, const bool right) noexcept -> bool {
				return left || right;
			}));
		}

		template<std::integral Integral>
		[[nodiscard]]
		constexpr xieite::math::BigInteger operator|(const Integral operand) const noexcept {
			return *this | xieite::math::BigInteger(operand);
		}

		constexpr xieite::math::BigInteger& operator|=(const xieite::math::BigInteger& operand) noexcept {
			return *this = *this | operand;
		}

		template<std::integral Integral>
		constexpr xieite::math::BigInteger& operator|=(const Integral operand) noexcept {
			return *this |= xieite::math::BigInteger(operand);
		}

		[[nodiscard]]
		constexpr xieite::math::BigInteger operator^(const xieite::math::BigInteger& operand) const noexcept {
			return !*this ? operand : (!operand ? *this : this->commonBitwiseOperation(operand, [](const bool left, const bool right) noexcept -> bool {
				return left != right;
			}));
		}

		template<std::integral Integral>
		[[nodiscard]]
		constexpr xieite::math::BigInteger operator^(const Integral operand) const noexcept {
			return *this ^ xieite::math::BigInteger(operand);
		}

		constexpr xieite::math::BigInteger& operator^=(const xieite::math::BigInteger& operand) noexcept {
			return *this = *this ^ operand;
		}

		template<std::integral Integral>
		constexpr xieite::math::BigInteger& operator^=(const Integral operand) noexcept {
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
			resultBits.insert(resultBits.end(), this->bits.begin(), this->bits.end());
			return xieite::math::BigInteger(resultBits, this->sign);
		}

		template<std::integral Integral>
		[[nodiscard]]
		constexpr xieite::math::BigInteger operator<<(const Integral positions) const noexcept {
			return *this << xieite::math::BigInteger(positions);
		}

		constexpr xieite::math::BigInteger& operator<<=(const xieite::math::BigInteger& positions) noexcept {
			return *this = *this << positions;
		}

		template<std::integral Integral>
		constexpr xieite::math::BigInteger& operator<<=(const Integral positions) noexcept {
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
			resultBits.erase(resultBits.begin(), std::ranges::next(resultBits.begin(), static_cast<std::size_t>(positions)));
			xieite::math::BigInteger result = xieite::math::BigInteger(resultBits, this->sign);
			return result ? result : -xieite::math::BigInteger(this->sign);
		}

		template<std::integral Integral>
		[[nodiscard]]
		constexpr xieite::math::BigInteger operator>>(const Integral positions) const noexcept {
			return *this >> xieite::math::BigInteger(positions);
		}

		constexpr xieite::math::BigInteger operator>>=(const xieite::math::BigInteger& positions) noexcept {
			return *this = *this >> positions;
		}

		template<std::integral Integral>
		constexpr xieite::math::BigInteger operator>>=(const Integral positions) noexcept {
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

		template<std::integral Integral>
		[[nodiscard]]
		constexpr xieite::math::BigInteger power(const Integral exponent) const {
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

		template<std::integral Integral>
		[[nodiscard]]
		constexpr xieite::math::BigInteger root(const Integral degree) const {
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
			return (this->bits.size() - 1) / (base.bits.size() - 1);
		}

		template<std::integral Integral>
		[[nodiscard]]
		constexpr xieite::math::BigInteger logarithm(const Integral base) const {
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

		template<xieite::concepts::Functable<bool(bool, bool)> Functable>
		[[nodiscard]]
		constexpr xieite::math::BigInteger commonBitwiseOperation(const xieite::math::BigInteger& value, const Functable& callback) const noexcept {
			xieite::math::BigInteger copy = *this;
			const std::size_t bitsSize = this->bits.size();
			if (this->sign) {
				++copy;
				for (std::size_t i = 0; i < bitsSize; ++i) {
					copy.bits[i] = !copy.bits[i];
				}
			}
			xieite::math::BigInteger valueCopy = value;
			const std::size_t valueBitsSize = value.bits.size();
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
