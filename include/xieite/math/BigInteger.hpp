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
#include <xieite/concepts/ComparatorCallback.hpp>
#include <xieite/macros/ASSERT.hpp>
#include <xieite/math/absolute.hpp>

namespace xieite::math {
	class BigInteger {
	private:
		std::vector<bool> bits;
		bool sign;

	public:
		BigInteger(const xieite::math::BigInteger& other) noexcept
		: bits(other.bits), sign(other.sign) {}

		BigInteger(xieite::math::BigInteger&& other) noexcept
		: bits(std::move(other.bits)), sign(other.sign) {}

		template<std::integral Integral = int>
		BigInteger(Integral value = 0) noexcept
		: sign(value < 0) {
			value = xieite::math::absolute(value);
			do {
				this->bits.push_back(value % 2);
				value /= 2;
			} while (value);
		}

		BigInteger(const std::vector<bool>& bits, const bool sign = false) noexcept
		: bits(bits), sign(sign) {
			std::size_t i = this->bits.size();
			if (i)
				while (!this->bits.back() && --i)
					this->bits.pop_back();
			else
				this->bits.push_back(false);
			if ((i < 2) && !this->bits[0])
				this->sign = false;
		}

		BigInteger(const std::string_view value) {
			const bool isNegative = value[0] == '-';
			const std::size_t valueSize = value.size();
			for (std::size_t i = isNegative; i < valueSize; ++i) {
				XIEITE_ASSERT((value[i] >= '0') && (value[i] <= '9'), "Cannot construct with non-digit character");
				*this += xieite::math::BigInteger(10).power(valueSize - i - 1) * (value[i] - '0');
			}
			this->sign = ((this->bits.size() < 2) && !this->bits[0]) * isNegative;
		}

		xieite::math::BigInteger& operator=(const xieite::math::BigInteger& other) noexcept {
			this->bits = other.bits;
			this->sign = other.sign;
			return *this;
		}

		xieite::math::BigInteger& operator=(xieite::math::BigInteger&& other) noexcept {
			if (this != &other) {
				this->bits = std::move(other.bits);
				this->sign = other.sign;
			}
			return *this;
		}

		xieite::math::BigInteger& operator=(const std::integral auto value) noexcept {
			return *this = xieite::math::BigInteger(value);
		}

		template<xieite::concepts::Arithmetic Number>
		[[nodiscard]]
		operator Number() const noexcept {
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
		operator bool() const noexcept {
			return *this != 0;
		}

		[[nodiscard]]
		bool operator!() const noexcept {
			return !static_cast<bool>(*this);
		}

		[[nodiscard]]
		bool operator==(const xieite::math::BigInteger& other) const noexcept {
			return (this->sign == other.sign) && (this->bits == other.bits);
		}
		
		[[nodiscard]]
		bool operator==(const std::integral auto value) const noexcept {
			return *this == xieite::math::BigInteger(value);
		}

		[[nodiscard]]
		std::strong_ordering operator<=>(const xieite::math::BigInteger& other) const noexcept {
			return (this->sign != other.sign) ? (other.sign <=> this->sign) : (this->sign ? ((this->bits.size() != other.bits.size()) ? (other.bits.size() <=> this->bits.size()) : (std::vector<bool>(other.bits.rbegin(), other.bits.rend()) <=> std::vector<bool>(this->bits.rbegin(), this->bits.rend()))) : ((this->bits.size() != other.bits.size()) ? (this->bits.size() <=> other.bits.size()) : (std::vector<bool>(this->bits.rbegin(), this->bits.rend()) <=> std::vector<bool>(other.bits.rbegin(), other.bits.rend()))));
		}

		[[nodiscard]]
		std::strong_ordering operator<=>(const std::integral auto value) const noexcept {
			return *this <=> xieite::math::BigInteger(value);
		}

		[[nodiscard]]
		xieite::math::BigInteger operator+() const noexcept {
			return *this;
		}

		[[nodiscard]]
		xieite::math::BigInteger operator+(const xieite::math::BigInteger& other) const noexcept {
			if (this->sign != other.sign)
				return *this - (-other);
			if (!*this)
				return other;
			if (!other)
				return *this;
			std::vector<bool> resultBits;
			bool carry = false;
			const std::size_t bitsSize = this->bits.size();
			const std::size_t otherBitsSize = other.bits.size();
			for (std::size_t i = 0; (i < bitsSize) || (i < otherBitsSize) || carry; ++i) {
				int sum = carry;
				if (i < bitsSize)
					sum += this->bits[i];
				if (i < otherBitsSize)
					sum += other.bits[i];
				carry = sum > 1;
				resultBits.push_back(sum % 2);
			}
			return xieite::math::BigInteger(resultBits, this->sign);
		}

		[[nodiscard]]
		xieite::math::BigInteger operator+(const std::integral auto value) const noexcept {
			return *this + xieite::math::BigInteger(value);
		}

		xieite::math::BigInteger& operator+=(const xieite::math::BigInteger& other) noexcept {
			return *this = *this + other;
		}

		xieite::math::BigInteger& operator+=(const std::integral auto value) noexcept {
			return *this += xieite::math::BigInteger(value);
		}

		xieite::math::BigInteger& operator++() noexcept {
			return *this += 1;
		}

		xieite::math::BigInteger operator++(int) noexcept {
			const xieite::math::BigInteger copy = *this;
			++*this;
			return copy;
		}

		[[nodiscard]]
		xieite::math::BigInteger operator-() const noexcept {
			xieite::math::BigInteger copy = *this;
			if (copy)
				copy.sign = !copy.sign;
			return copy;
		}

		[[nodiscard]]
		xieite::math::BigInteger operator-(const xieite::math::BigInteger& other) const noexcept {
			if (!other)
				return *this;
			if (this->sign != other.sign)
				return *this + (-other);
			if (this->sign && (*this > other) || !this->sign && (*this < other))
				return -(other - *this);
			std::vector<bool> resultBits = this->bits;
			bool borrow = false;
			const std::size_t bitsSize = this->bits.size();
			const std::size_t otherBitsSize = other.bits.size();
			for (std::size_t i = 0; (i < otherBitsSize) || borrow; ++i) {
				int difference = 2 - borrow + this->bits[i];
				if (i < otherBitsSize)
					difference -= other.bits[i];
				borrow = (i < bitsSize - 1) && (difference < 2);
				resultBits[i] = difference % 2;
			}
			return xieite::math::BigInteger(resultBits, this->sign != borrow);
		}

		[[nodiscard]]
		xieite::math::BigInteger operator-(const std::integral auto value) const noexcept {
			return *this - xieite::math::BigInteger(value);
		}

		xieite::math::BigInteger& operator-=(const xieite::math::BigInteger& other) noexcept {
			return *this = *this - other;
		}

		xieite::math::BigInteger& operator-=(const std::integral auto value) noexcept {
			return *this -= xieite::math::BigInteger(value);
		}

		xieite::math::BigInteger& operator--() noexcept {
			return *this -= 1;
		}

		xieite::math::BigInteger operator--(int) noexcept {
			const xieite::math::BigInteger copy = *this;
			--*this;
			return copy;
		}

		[[nodiscard]]
		xieite::math::BigInteger operator*(const xieite::math::BigInteger& other) const noexcept {
			if (!*this || !other)
				return xieite::math::BigInteger(0);
			if (*this == 1)
				return other;
			if (other == 1)
				return *this;
			if (*this == -1)
				return -other;
			if (other == -1)
				return -*this;
			const std::size_t halfSize = std::min(this->bits.size(), other.bits.size()) / 2;
			const std::vector<bool>::const_iterator i = std::next(this->bits.begin(), halfSize);
			const xieite::math::BigInteger a(std::vector<bool>(this->bits.begin(), i));
			const xieite::math::BigInteger b(std::vector<bool>(i, this->bits.end()));
			const std::vector<bool>::const_iterator j = std::next(other.bits.begin(), halfSize);
			const xieite::math::BigInteger c(std::vector<bool>(other.bits.begin(), j));
			const xieite::math::BigInteger d(std::vector<bool>(j, other.bits.end()));
			const xieite::math::BigInteger e = a * c;
			const xieite::math::BigInteger f = (a + b) * (c + d);
			const xieite::math::BigInteger g = b * d;
			xieite::math::BigInteger result = (g << (halfSize * 2)) + ((f - g - e) << halfSize) + e;
			result.sign = this->sign != other.sign;
			return result;
		}

		[[nodiscard]]
		xieite::math::BigInteger operator*(const std::integral auto value) const noexcept {
			return *this * xieite::math::BigInteger(value);
		}

		xieite::math::BigInteger& operator*=(const xieite::math::BigInteger& other) noexcept {
			return *this = *this * other;
		}

		xieite::math::BigInteger& operator*=(const std::integral auto value) noexcept {
			return *this *= xieite::math::BigInteger(value);
		}

		[[nodiscard]]
		xieite::math::BigInteger operator/(const xieite::math::BigInteger& other) const {
			XIEITE_ASSERT(static_cast<bool>(other), "Cannot divide by zero");
			if (other == 1)
				return *this;
			if (other == -1)
				return -*this;
			const bool otherSign = other.sign;
            const xieite::math::BigInteger otherCopy = other.absolute();
			if (absolute() < otherCopy)
				return xieite::math::BigInteger(0);
			std::vector<bool> resultBits;
			xieite::math::BigInteger difference;
			for (std::size_t i = this->bits.size(); i--;) {
				if (!difference)
					difference.bits.clear();
				difference.bits.insert(difference.bits.begin(), this->bits[i]);
				bool quotient = difference >= otherCopy;
				if (quotient)
					difference -= otherCopy;
				resultBits.insert(resultBits.begin(), quotient);
			}
			return xieite::math::BigInteger(resultBits, this->sign != otherSign);
		}

		[[nodiscard]]
		xieite::math::BigInteger operator/(const std::integral auto value) const {
			return *this / xieite::math::BigInteger(value);
		}

		xieite::math::BigInteger& operator/=(const xieite::math::BigInteger& other) {
			return *this = *this / other;
		}

		xieite::math::BigInteger& operator/=(const std::integral auto value) {
			return *this /= xieite::math::BigInteger(value);
		}

		[[nodiscard]]
		xieite::math::BigInteger operator%(const xieite::math::BigInteger& other) const {
			XIEITE_ASSERT(static_cast<bool>(other), "Cannot find remainder of division by zero");
			const xieite::math::BigInteger copy = absolute();
			const xieite::math::BigInteger otherCopy = other.absolute();
			if (!*this || (otherCopy == 1) || (copy == otherCopy))
				return xieite::math::BigInteger(0);
			if (copy < otherCopy)
				return *this;
			xieite::math::BigInteger difference;
			for (std::size_t i = this->bits.size(); i--;) {
				if (!difference)
					difference.bits.clear();
				difference.bits.insert(difference.bits.begin(), this->bits[i]);
				if (difference >= otherCopy)
					difference -= otherCopy;
			}
			difference.sign = this->sign;
			return difference;
		}

		[[nodiscard]]
		xieite::math::BigInteger operator%(const std::integral auto value) const {
			return *this % xieite::math::BigInteger(value);
		}

		xieite::math::BigInteger& operator%=(const xieite::math::BigInteger& other) {
			return *this = *this % other;
		}

		xieite::math::BigInteger& operator%=(const std::integral auto value) {
			return *this %= xieite::math::BigInteger(value);
		}

		[[nodiscard]]
		xieite::math::BigInteger operator~() const noexcept {
			return -(*this + 1);
		}

		[[nodiscard]]
		xieite::math::BigInteger operator&(const xieite::math::BigInteger& other) const noexcept {
			return (!*this || !other) ? xieite::math::BigInteger(0) : commonBitwiseOperation(other, [](const bool left, const bool right) -> bool {
				return left && right;
			});
		}

		[[nodiscard]]
		xieite::math::BigInteger operator&(const std::integral auto value) const noexcept {
			return *this & xieite::math::BigInteger(value);
		}

		xieite::math::BigInteger& operator&=(const xieite::math::BigInteger& other) noexcept {
			return *this = *this & other;
		}

		xieite::math::BigInteger& operator&=(const std::integral auto value) noexcept {
			return *this &= xieite::math::BigInteger(value);
		}

		[[nodiscard]]
		xieite::math::BigInteger operator|(const xieite::math::BigInteger& other) const noexcept {
			return !*this ? other : (!other ? *this : commonBitwiseOperation(other, [](const bool left, const bool right) -> bool {
				return left || right;
			}));
		}

		[[nodiscard]]
		xieite::math::BigInteger operator|(const std::integral auto value) const noexcept {
			return *this | xieite::math::BigInteger(value);
		}

		xieite::math::BigInteger& operator|=(const xieite::math::BigInteger& other) noexcept {
			return *this = *this | other;
		}

		xieite::math::BigInteger& operator|=(const std::integral auto value) noexcept {
			return *this |= xieite::math::BigInteger(value);
		}

		[[nodiscard]]
		xieite::math::BigInteger operator^(const xieite::math::BigInteger& other) const noexcept {
			return !*this ? other : (!other ? *this : commonBitwiseOperation(other, [](const bool left, const bool right) -> bool {
				return left != right;
			}));
		}

		[[nodiscard]]
		xieite::math::BigInteger operator^(const std::integral auto value) const noexcept {
			return *this ^ xieite::math::BigInteger(value);
		}

		xieite::math::BigInteger& operator^=(const xieite::math::BigInteger& other) noexcept {
			return *this = *this ^ other;
		}

		xieite::math::BigInteger& operator^=(const std::integral auto value) noexcept {
			return *this ^= xieite::math::BigInteger(value);
		}

		[[nodiscard]]
		xieite::math::BigInteger operator<<(const xieite::math::BigInteger& other) const noexcept {
			if (other.sign || !*this)
				return xieite::math::BigInteger(0);
			if (!other)
				return *this;
			std::vector<bool> resultBits(static_cast<std::size_t>(other));
			resultBits.insert(resultBits.end(), this->bits.begin(), this->bits.end());
			return xieite::math::BigInteger(resultBits, this->sign);
		}

		[[nodiscard]]
		xieite::math::BigInteger operator<<(const std::integral auto value) const noexcept {
			return *this << xieite::math::BigInteger(value);
		}

		xieite::math::BigInteger& operator<<=(const xieite::math::BigInteger& other) noexcept {
			return *this = *this << other;
		}

		xieite::math::BigInteger& operator<<=(const std::integral auto value) noexcept {
			return *this <<= xieite::math::BigInteger(value);
		}

		[[nodiscard]]
		xieite::math::BigInteger operator>>(const xieite::math::BigInteger& other) const noexcept {
			if (!this->sign && other.sign || !*this)
				return xieite::math::BigInteger(0);
			if (!other)
				return *this;
			std::vector<bool> resultBits = this->bits;
			std::vector<bool>::iterator end = resultBits.begin();
			resultBits.erase(resultBits.begin(), std::next(resultBits.begin(), static_cast<std::size_t>(other)));
			BigInteger result(resultBits, this->sign);
			return result ? result : -xieite::math::BigInteger(this->sign);
		}

		[[nodiscard]]
		xieite::math::BigInteger operator>>(const std::integral auto value) const noexcept {
			return *this >> xieite::math::BigInteger(value);
		}

		xieite::math::BigInteger operator>>=(const xieite::math::BigInteger& other) noexcept {
			return *this = *this >> other;
		}

		xieite::math::BigInteger operator>>=(const std::integral auto value) noexcept {
			return *this >>= xieite::math::BigInteger(value);
		}

		[[nodiscard]]
		xieite::math::BigInteger absolute() const noexcept {
			xieite::math::BigInteger copy = *this;
			copy.sign = false;
			return copy;
		}

		[[nodiscard]]
		xieite::math::BigInteger power(xieite::math::BigInteger other) const {
			if ((*this == 1) || (other == 1))
				return *this;
			if (*this == -1)
				return *this * (other % 2) * 2 - 1;
			if (!other)
				return xieite::math::BigInteger(1);
			if (other.sign) {
				XIEITE_ASSERT(static_cast<bool>(*this), "Cannot find power of zero to negative exponent");
				return !other;
			}
			if (!*this)
				return !other;
			xieite::math::BigInteger x = *this;
			xieite::math::BigInteger y = 1;
			while (other > 1) {
				if (other % 2) {
					y *= x;
					other = (other - 1) / 2;
				} else
					other /= 2;
				x *= x;
			}
			return x * y;
		}

		[[nodiscard]]
		xieite::math::BigInteger power(const std::integral auto value) const {
			return power(xieite::math::BigInteger(value));
		}

		[[nodiscard]]
		xieite::math::BigInteger root(const xieite::math::BigInteger& other) const {
			XIEITE_ASSERT(!this->sign, "Cannot find root of negative value");
			if (*this == 1)
				return xieite::math::BigInteger(1);
			if (other.sign)
				return xieite::math::BigInteger(0);
			xieite::math::BigInteger x = other - 1;
			xieite::math::BigInteger y = *this;
			xieite::math::BigInteger z = y + 1;
			while (y < z) {
				z = y;
				y = (x * y + *this / y.power(x)) / other;
			}
			return z;
		}

		[[nodiscard]]
		xieite::math::BigInteger root(const std::integral auto value) const {
			return root(xieite::math::BigInteger(value));
		}

		[[nodiscard]]
		const std::vector<bool>& data() const noexcept {
			return this->bits;
		}

		[[nodiscard]]
		std::string string() const noexcept {
			if (!*this)
				return "0";
			xieite::math::BigInteger copy = absolute();
			std::string result;
			do {
				result = static_cast<char>(copy % 10 + '0') + result;
				copy /= 10;
			} while (copy);
			if (this->sign)
				result = '-' + result;
			return result;
		}
	
	private:
		template<xieite::concepts::ComparatorCallback<bool> Callback>
		xieite::math::BigInteger commonBitwiseOperation(const xieite::math::BigInteger& other, Callback&& callback) const noexcept {
			xieite::math::BigInteger copy = *this;
			const std::size_t bitsSize = this->bits.size();
			if (this->sign) {
				++copy;
				for (std::size_t i = 0; i < bitsSize; ++i)
					copy.bits[i] = !copy.bits[i];
			}
			xieite::math::BigInteger otherCopy = other;
			const std::size_t otherBitsSize = other.bits.size();
			if (other.sign) {
				++otherCopy;
				for (std::size_t i = 0; i < otherBitsSize; ++i)
					otherCopy.bits[i] = !otherCopy.bits[i];
			}
			xieite::math::BigInteger result;
			result.bits.clear();
			result.sign = this->sign && other.sign;
			for (std::size_t i = 0; (i < bitsSize) || (i < otherBitsSize); ++i)
				result.bits.push_back(callback((i < bitsSize) ? copy.bits[i] : this->sign, (i < otherBitsSize) ? otherCopy.bits[i] : other.sign));
			if (result.sign) {
				for (std::size_t i = 0; (i < bitsSize) || (i < otherBitsSize); ++i)
					result.bits[i] = !result.bits[i];
				--result;
			}
			return result;
		}
	};
}
