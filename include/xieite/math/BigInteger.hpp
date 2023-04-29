#pragma once

#include <cmath>
#include <compare>
#include <concepts>
#include <cstddef>
#include <iterator>
#include <string>
#include <string_view>
#include <utility>
#include <vector>
#include <xieite/concepts/Arithmetic.hpp>
#include <xieite/concepts/CallbackComparator.hpp>
#include <xieite/macros/ASSERT.hpp>
#include <xieite/math/absolute.hpp>

namespace xieite::math {
	class BigInteger {
	public:
		template<std::integral Number = int>
		constexpr BigInteger(Number value = 0) noexcept
		: sign(value < 0) {
			value = xieite::math::absolute(value);
			do {
				this->bits.push_back(value % 2);
				value /= 2;
			} while (value);
		}

		constexpr BigInteger(const xieite::math::BigInteger& bigInteger) noexcept
		: bits(bigInteger.bits), sign(bigInteger.sign) {}

		constexpr BigInteger(const std::vector<bool>& bits, const bool sign = false) noexcept
		: bits(std::vector<bool>(bits.begin(), bits.end())), sign(sign) {
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
				XIEITE_ASSERT((value[i] >= '0') && (value[i] <= '9'), "Cannot construct with non-digit character");
				*this += xieite::math::BigInteger(10).power(valueSize - i - 1) * (value[i] - '0');
			}
			this->sign = ((this->bits.size() < 2) && !this->bits[0]) * isNegative;
		}

		constexpr xieite::math::BigInteger& operator=(const xieite::math::BigInteger& bigInteger) noexcept {
			this->bits = bigInteger.bits;
			this->sign = bigInteger.sign;
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
		constexpr bool operator==(const xieite::math::BigInteger& bigInteger) const noexcept {
			return (this->sign == bigInteger.sign) && (this->bits == bigInteger.bits);
		}
		
		[[nodiscard]]
		constexpr bool operator==(const std::integral auto value) const noexcept {
			return *this == xieite::math::BigInteger(value);
		}

		[[nodiscard]]
		constexpr std::strong_ordering operator<=>(const xieite::math::BigInteger& bigInteger) const noexcept {
			return (this->sign != bigInteger.sign) ? (bigInteger.sign <=> this->sign) : (this->sign ? ((this->bits.size() != bigInteger.bits.size()) ? (bigInteger.bits.size() <=> this->bits.size()) : (std::vector<bool>(std::rbegin(bigInteger.bits), std::rend(bigInteger.bits)) <=> std::vector<bool>(std::rbegin(this->bits), std::rend(this->bits)))) : ((this->bits.size() != bigInteger.bits.size()) ? (this->bits.size() <=> bigInteger.bits.size()) : (std::vector<bool>(std::rbegin(this->bits), std::rend(this->bits)) <=> std::vector<bool>(std::rbegin(bigInteger.bits), std::rend(bigInteger.bits)))));
		}

		[[nodiscard]]
		constexpr std::strong_ordering operator<=>(const std::integral auto value) const noexcept {
			return *this <=> xieite::math::BigInteger(value);
		}

		[[nodiscard]]
		constexpr xieite::math::BigInteger operator+() const noexcept {
			return *this;
		}

		[[nodiscard]]
		constexpr xieite::math::BigInteger operator+(const xieite::math::BigInteger& bigInteger) const noexcept {
			if (this->sign != bigInteger.sign) {
				return *this - (-bigInteger);
			}
			if (!*this) {
				return bigInteger;
			}
			if (!bigInteger) {
				return *this;
			}
			std::vector<bool> resultBits;
			bool carry = false;
			const std::size_t bitsSize = this->bits.size();
			const std::size_t bigIntegerBitsSize = bigInteger.bits.size();
			for (std::size_t i = 0; (i < bitsSize) || (i < bigIntegerBitsSize) || carry; ++i) {
				int sum = carry;
				if (i < bitsSize) {
					sum += this->bits[i];
				}
				if (i < bigIntegerBitsSize) {
					sum += bigInteger.bits[i];
				}
				carry = sum > 1;
				resultBits.push_back(sum % 2);
			}
			return xieite::math::BigInteger(resultBits, this->sign);
		}

		[[nodiscard]]
		constexpr xieite::math::BigInteger operator+(const std::integral auto value) const noexcept {
			return *this + xieite::math::BigInteger(value);
		}

		constexpr xieite::math::BigInteger& operator+=(const xieite::math::BigInteger& bigInteger) noexcept {
			return *this = *this + bigInteger;
		}

		constexpr xieite::math::BigInteger& operator+=(const std::integral auto value) noexcept {
			return *this += xieite::math::BigInteger(value);
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
		constexpr xieite::math::BigInteger operator-(const xieite::math::BigInteger& bigInteger) const noexcept {
			if (!bigInteger) {
				return *this;
			}
			if (this->sign != bigInteger.sign) {
				return *this + (-bigInteger);
			}
			if (this->sign && (*this > bigInteger) || !this->sign && (*this < bigInteger)) {
				return -(bigInteger - *this);
			}
			std::vector<bool> resultBits = this->bits;
			bool borrow = false;
			const std::size_t bitsSize = this->bits.size();
			const std::size_t bigIntegerBitsSize = bigInteger.bits.size();
			for (std::size_t i = 0; (i < bigIntegerBitsSize) || borrow; ++i) {
				int difference = 2 - borrow + this->bits[i];
				if (i < bigIntegerBitsSize) {
					difference -= bigInteger.bits[i];
				}
				borrow = (i < bitsSize - 1) && (difference < 2);
				resultBits[i] = difference % 2;
			}
			return xieite::math::BigInteger(resultBits, this->sign != borrow);
		}

		[[nodiscard]]
		constexpr xieite::math::BigInteger operator-(const std::integral auto value) const noexcept {
			return *this - xieite::math::BigInteger(value);
		}

		constexpr xieite::math::BigInteger& operator-=(const xieite::math::BigInteger& bigInteger) noexcept {
			return *this = *this - bigInteger;
		}

		constexpr xieite::math::BigInteger& operator-=(const std::integral auto value) noexcept {
			return *this -= xieite::math::BigInteger(value);
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
		constexpr xieite::math::BigInteger operator*(const xieite::math::BigInteger& bigInteger) const noexcept {
			if (!*this || !bigInteger) {
				return xieite::math::BigInteger(0);
			}
			if (*this == 1) {
				return bigInteger;
			}
			if (bigInteger == 1) {
				return *this;
			}
			if (*this == -1) {
				return -bigInteger;
			}
			if (bigInteger == -1) {
				return -*this;
			}
			const std::size_t halfSize = std::min(this->bits.size(), bigInteger.bits.size()) / 2;
			const std::vector<bool>::const_iterator i = std::next(std::begin(this->bits), halfSize);
			const xieite::math::BigInteger a(std::vector<bool>(std::begin(this->bits), i));
			const xieite::math::BigInteger b(std::vector<bool>(i, std::end(this->bits)));
			const std::vector<bool>::const_iterator j = std::next(std::begin(bigInteger.bits), halfSize);
			const xieite::math::BigInteger c(std::vector<bool>(std::begin(bigInteger.bits), j));
			const xieite::math::BigInteger d(std::vector<bool>(j, std::end(bigInteger.bits)));
			const xieite::math::BigInteger e = a * c;
			const xieite::math::BigInteger f = (a + b) * (c + d);
			const xieite::math::BigInteger g = b * d;
			xieite::math::BigInteger result = (g << (halfSize * 2)) + ((f - g - e) << halfSize) + e;
			result.sign = this->sign != bigInteger.sign;
			return result;
		}

		[[nodiscard]]
		constexpr xieite::math::BigInteger operator*(const std::integral auto value) const noexcept {
			return *this * xieite::math::BigInteger(value);
		}

		constexpr xieite::math::BigInteger& operator*=(const xieite::math::BigInteger& bigInteger) noexcept {
			return *this = *this * bigInteger;
		}

		constexpr xieite::math::BigInteger& operator*=(const std::integral auto value) noexcept {
			return *this *= xieite::math::BigInteger(value);
		}

		[[nodiscard]]
		constexpr xieite::math::BigInteger operator/(const xieite::math::BigInteger& bigInteger) const {
			XIEITE_ASSERT(static_cast<bool>(bigInteger), "Cannot divide by zero");
			if (bigInteger == 1) {
				return *this;
			}
			if (bigInteger == -1) {
				return -*this;
			}
			const bool bigIntegerSign = bigInteger.sign;
            const xieite::math::BigInteger bigIntegerCopy = bigInteger.absolute();
			if (this->absolute() < bigIntegerCopy) {
				return xieite::math::BigInteger(0);
			}
			std::vector<bool> resultBits;
			xieite::math::BigInteger difference;
			for (std::size_t i = this->bits.size(); i--;) {
				if (!difference) {
					difference.bits.clear();
				}
				difference.bits.insert(std::begin(difference.bits), this->bits[i]);
				bool quotient = difference >= bigIntegerCopy;
				if (quotient) {
					difference -= bigIntegerCopy;
				}
				resultBits.insert(std::begin(resultBits), quotient);
			}
			return xieite::math::BigInteger(resultBits, this->sign != bigIntegerSign);
		}

		[[nodiscard]]
		constexpr xieite::math::BigInteger operator/(const std::integral auto value) const {
			return *this / xieite::math::BigInteger(value);
		}

		constexpr xieite::math::BigInteger& operator/=(const xieite::math::BigInteger& bigInteger) {
			return *this = *this / bigInteger;
		}

		constexpr xieite::math::BigInteger& operator/=(const std::integral auto value) {
			return *this /= xieite::math::BigInteger(value);
		}

		[[nodiscard]]
		constexpr xieite::math::BigInteger operator%(const xieite::math::BigInteger& bigInteger) const {
			XIEITE_ASSERT(static_cast<bool>(bigInteger), "Cannot find remainder of division by zero");
			const xieite::math::BigInteger copy = this->absolute();
			const xieite::math::BigInteger bigIntegerCopy = bigInteger.absolute();
			if (!*this || (bigIntegerCopy == 1) || (copy == bigIntegerCopy)) {
				return xieite::math::BigInteger(0);
			}
			if (copy < bigIntegerCopy) {
				return *this;
			}
			xieite::math::BigInteger difference;
			for (std::size_t i = this->bits.size(); i--;) {
				if (!difference) {
					difference.bits.clear();
				}
				difference.bits.insert(std::begin(difference.bits), this->bits[i]);
				if (difference >= bigIntegerCopy) {
					difference -= bigIntegerCopy;
				}
			}
			difference.sign = this->sign;
			return difference;
		}

		[[nodiscard]]
		constexpr xieite::math::BigInteger operator%(const std::integral auto value) const {
			return *this % xieite::math::BigInteger(value);
		}

		constexpr xieite::math::BigInteger& operator%=(const xieite::math::BigInteger& bigInteger) {
			return *this = *this % bigInteger;
		}

		constexpr xieite::math::BigInteger& operator%=(const std::integral auto value) {
			return *this %= xieite::math::BigInteger(value);
		}

		[[nodiscard]]
		constexpr xieite::math::BigInteger operator~() const noexcept {
			return -(*this + 1);
		}

		[[nodiscard]]
		constexpr xieite::math::BigInteger operator&(const xieite::math::BigInteger& bigInteger) const noexcept {
			return (!*this || !bigInteger) ? xieite::math::BigInteger(0) : this->commonBitwiseOperation(bigInteger, [](const bool left, const bool right) noexcept -> bool {
				return left && right;
			});
		}

		[[nodiscard]]
		constexpr xieite::math::BigInteger operator&(const std::integral auto value) const noexcept {
			return *this & xieite::math::BigInteger(value);
		}

		constexpr xieite::math::BigInteger& operator&=(const xieite::math::BigInteger& bigInteger) noexcept {
			return *this = *this & bigInteger;
		}

		constexpr xieite::math::BigInteger& operator&=(const std::integral auto value) noexcept {
			return *this &= xieite::math::BigInteger(value);
		}

		[[nodiscard]]
		constexpr xieite::math::BigInteger operator|(const xieite::math::BigInteger& bigInteger) const noexcept {
			return !*this ? bigInteger : (!bigInteger ? *this : this->commonBitwiseOperation(bigInteger, [](const bool left, const bool right) noexcept -> bool {
				return left || right;
			}));
		}

		[[nodiscard]]
		constexpr xieite::math::BigInteger operator|(const std::integral auto value) const noexcept {
			return *this | xieite::math::BigInteger(value);
		}

		constexpr xieite::math::BigInteger& operator|=(const xieite::math::BigInteger& bigInteger) noexcept {
			return *this = *this | bigInteger;
		}

		constexpr xieite::math::BigInteger& operator|=(const std::integral auto value) noexcept {
			return *this |= xieite::math::BigInteger(value);
		}

		[[nodiscard]]
		constexpr xieite::math::BigInteger operator^(const xieite::math::BigInteger& bigInteger) const noexcept {
			return !*this ? bigInteger : (!bigInteger ? *this : this->commonBitwiseOperation(bigInteger, [](const bool left, const bool right) noexcept -> bool {
				return left != right;
			}));
		}

		[[nodiscard]]
		constexpr xieite::math::BigInteger operator^(const std::integral auto value) const noexcept {
			return *this ^ xieite::math::BigInteger(value);
		}

		constexpr xieite::math::BigInteger& operator^=(const xieite::math::BigInteger& bigInteger) noexcept {
			return *this = *this ^ bigInteger;
		}

		constexpr xieite::math::BigInteger& operator^=(const std::integral auto value) noexcept {
			return *this ^= xieite::math::BigInteger(value);
		}

		[[nodiscard]]
		constexpr xieite::math::BigInteger operator<<(const xieite::math::BigInteger& bigInteger) const noexcept {
			if (bigInteger.sign || !*this) {
				return xieite::math::BigInteger(0);
			}
			if (!bigInteger) {
				return *this;
			}
			std::vector<bool> resultBits(static_cast<std::size_t>(bigInteger));
			resultBits.insert(std::end(resultBits), std::begin(this->bits), std::end(this->bits));
			return xieite::math::BigInteger(resultBits, this->sign);
		}

		[[nodiscard]]
		constexpr xieite::math::BigInteger operator<<(const std::integral auto value) const noexcept {
			return *this << xieite::math::BigInteger(value);
		}

		constexpr xieite::math::BigInteger& operator<<=(const xieite::math::BigInteger& bigInteger) noexcept {
			return *this = *this << bigInteger;
		}

		constexpr xieite::math::BigInteger& operator<<=(const std::integral auto value) noexcept {
			return *this <<= xieite::math::BigInteger(value);
		}

		[[nodiscard]]
		constexpr xieite::math::BigInteger operator>>(const xieite::math::BigInteger& bigInteger) const noexcept {
			if (!this->sign && bigInteger.sign || !*this) {
				return xieite::math::BigInteger(0);
			}
			if (!bigInteger) {
				return *this;
			}
			std::vector<bool> resultBits = this->bits;
			std::vector<bool>::iterator end = std::begin(resultBits);
			resultBits.erase(std::begin(resultBits), std::next(std::begin(resultBits), static_cast<std::size_t>(bigInteger)));
			BigInteger result(resultBits, this->sign);
			return result ? result : -xieite::math::BigInteger(this->sign);
		}

		[[nodiscard]]
		constexpr xieite::math::BigInteger operator>>(const std::integral auto value) const noexcept {
			return *this >> xieite::math::BigInteger(value);
		}

		constexpr xieite::math::BigInteger operator>>=(const xieite::math::BigInteger& bigInteger) noexcept {
			return *this = *this >> bigInteger;
		}

		constexpr xieite::math::BigInteger operator>>=(const std::integral auto value) noexcept {
			return *this >>= xieite::math::BigInteger(value);
		}

		[[nodiscard]]
		constexpr xieite::math::BigInteger absolute() const noexcept {
			xieite::math::BigInteger copy = *this;
			copy.sign = false;
			return copy;
		}

		[[nodiscard]]
		constexpr xieite::math::BigInteger power(xieite::math::BigInteger bigInteger) const {
			if ((*this == 1) || (bigInteger == 1)) {
				return *this;
			}
			if (*this == -1) {
				return *this * (bigInteger % 2) * 2 - 1;
			}
			if (!bigInteger) {
				return xieite::math::BigInteger(1);
			}
			if (bigInteger.sign) {
				XIEITE_ASSERT(static_cast<bool>(*this), "Cannot find power of zero to negative exponent");
				return !bigInteger;
			}
			if (!*this) {
				return !bigInteger;
			}
			xieite::math::BigInteger x = *this;
			xieite::math::BigInteger y = 1;
			while (bigInteger > 1) {
				if (bigInteger % 2) {
					y *= x;
					bigInteger = (bigInteger - 1) / 2;
				} else {
					bigInteger /= 2;
				}
				x *= x;
			}
			return x * y;
		}

		[[nodiscard]]
		constexpr xieite::math::BigInteger power(const std::integral auto value) const {
			return this->power(xieite::math::BigInteger(value));
		}

		[[nodiscard]]
		constexpr xieite::math::BigInteger root(const xieite::math::BigInteger& bigInteger) const {
			XIEITE_ASSERT(!this->sign, "Cannot find root of negative value");
			if (*this == 1) {
				return xieite::math::BigInteger(1);
			}
			if (bigInteger.sign) {
				return xieite::math::BigInteger(0);
			}
			xieite::math::BigInteger x = bigInteger - 1;
			xieite::math::BigInteger y = *this;
			xieite::math::BigInteger z = y + 1;
			while (y < z) {
				z = y;
				y = (x * y + *this / y.power(x)) / bigInteger;
			}
			return z;
		}

		[[nodiscard]]
		constexpr xieite::math::BigInteger root(const std::integral auto value) const {
			return this->root(xieite::math::BigInteger(value));
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

		template<xieite::concepts::CallbackComparator<bool> Callback>
		[[nodiscard]]
		constexpr xieite::math::BigInteger commonBitwiseOperation(const xieite::math::BigInteger& bigInteger, const Callback& callback) const noexcept {
			xieite::math::BigInteger copy = *this;
			const std::size_t bitsSize = this->bits.size();
			if (this->sign) {
				++copy;
				for (std::size_t i = 0; i < bitsSize; ++i) {
					copy.bits[i] = !copy.bits[i];
				}
			}
			xieite::math::BigInteger bigIntegerCopy = bigInteger;
			const std::size_t bigIntegerBitsSize = bigInteger.bits.size();
			if (bigInteger.sign) {
				++bigIntegerCopy;
				for (std::size_t i = 0; i < bigIntegerBitsSize; ++i) {
					bigIntegerCopy.bits[i] = !bigIntegerCopy.bits[i];
				}
			}
			xieite::math::BigInteger result;
			result.bits.clear();
			result.sign = this->sign && bigInteger.sign;
			for (std::size_t i = 0; (i < bitsSize) || (i < bigIntegerBitsSize); ++i) {
				result.bits.push_back(callback((i < bitsSize) ? copy.bits[i] : this->sign, (i < bigIntegerBitsSize) ? bigIntegerCopy.bits[i] : bigInteger.sign));
			}
			if (result.sign) {
				for (std::size_t i = 0; (i < bitsSize) || (i < bigIntegerBitsSize); ++i) {
					result.bits[i] = !result.bits[i];
				}
				--result;
			}
			return result;
		}
	};
}
