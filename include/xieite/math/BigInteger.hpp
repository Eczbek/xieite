#pragma once
#include <cmath> // std::abs, std::min
#include <compare> // std::strong_ordering
#include <concepts> // std::convertible_to, std::integral, std::signed_integral, std::unsigned_integral
#include <cstddef> // std::size_t
#include <iterator> // std::advance, std::forward_iterator
#include <stdexcept> // std::domain_error, std::invalid_argument
#include <string> // std::string
#include <string_view> // std::string_view
#include <vector> // std::vector
#include <xieite/concepts/Arithmetic.hpp>

namespace xieite::math {
	class BigInteger {
	private:
		bool sign;
		std::vector<bool> bits;

	public:
		constexpr BigInteger(const xieite::math::BigInteger& other) noexcept
		: sign(other.sign), bits(other.bits) {}

		template<std::signed_integral N = int>
		constexpr BigInteger(N value = 0) noexcept
		: sign(value < 0) {
			value = std::abs(value);
			do {
				bits.push_back(value % 2);
				value /= 2;
			} while (value);
		}

		template<std::unsigned_integral N>
		constexpr BigInteger(N value) noexcept
		: sign(false) {
			do {
				bits.push_back(value % 2);
				value /= 2;
			} while (value);
		}

		template<std::forward_iterator I>
		requires(std::convertible_to<typename I::value_type, bool>)
		constexpr BigInteger(const I begin, const I end, const bool sign = false) noexcept
		: sign(sign), bits(begin, end) {
			std::size_t i = bits.size();
			if (i)
				while (!bits.back() && --i)
					bits.pop_back();
			else
				bits.push_back(false);
			if (i < 2 && !bits[0])
				this->sign = false;
		}

		constexpr BigInteger(const std::string_view value) {
			const bool isNegative = value[0] == '-';
			const std::size_t valueSize = value.size();
			for (std::size_t i = isNegative; i < valueSize; ++i) {
				if (value[i] < '0' || value[i] > '9')
					throw std::invalid_argument("Cannot construct with non-digit character");
				*this += xieite::math::BigInteger(10).pow(valueSize - i - 1) * (value[i] - '0');
			}
			sign = isNegative;
		}

		constexpr xieite::math::BigInteger& operator=(const xieite::math::BigInteger& other) noexcept {
			sign = other.sign;
			bits = other.bits;
			return *this;
		}

		template<std::integral N>
		constexpr xieite::math::BigInteger& operator=(const N value) noexcept {
			return *this = xieite::math::BigInteger(value);
		}

		template<xieite::concepts::Arithmetic N>
		[[nodiscard]]
		constexpr operator N() const noexcept {
			N result = 0;
			N power = 1;
			for (const bool bit : bits) {
				result += bit * power;
				power *= 2;
			}
			return result;
		}

		[[nodiscard]]
		constexpr operator bool() const noexcept {
			return *this != 0;
		}

		[[nodiscard]]
		constexpr bool operator!() const noexcept {
			return !static_cast<bool>(*this);
		}

		[[nodiscard]]
		constexpr bool operator==(const xieite::math::BigInteger& other) const noexcept {
			return sign == other.sign && bits == other.bits;
		}

		template<std::integral N>
		[[nodiscard]]
		constexpr bool operator==(const N value) const noexcept {
			return *this == xieite::math::BigInteger(value);
		}

		[[nodiscard]]
		constexpr std::strong_ordering operator<=>(const xieite::math::BigInteger& other) const noexcept {
			return (sign != other.sign)
				? (other.sign <=> sign)
				: sign
					? (bits.size() != other.bits.size())
						? (other.bits.size() <=> bits.size())
						: (std::vector<bool>(other.bits.rbegin(), other.bits.rend()) <=> std::vector<bool>(bits.rbegin(), bits.rend()))
					: (bits.size() != other.bits.size())
						? (bits.size() <=> other.bits.size())
						: (std::vector<bool>(bits.rbegin(), bits.rend()) <=> std::vector<bool>(other.bits.rbegin(), other.bits.rend()));
		}

		template<std::integral N>
		[[nodiscard]]
		constexpr std::strong_ordering operator<=>(const N value) const noexcept {
			return *this <=> xieite::math::BigInteger(value);
		}

		[[nodiscard]]
		constexpr xieite::math::BigInteger operator+() const noexcept {
			return *this;
		}

		[[nodiscard]]
		constexpr xieite::math::BigInteger operator+(const xieite::math::BigInteger& other) const noexcept {
			if (sign != other.sign)
				return *this - (-other);
			if (!*this)
				return other;
			if (!other)
				return *this;
			std::vector<bool> resultBits;
			bool carry = false;
			const std::size_t bitsSize = bits.size();
			const std::size_t otherBitsSize = other.bits.size();
			for (std::size_t i = 0; i < bitsSize || i < otherBitsSize || carry; ++i) {
				int sum = carry;
				if (i < bitsSize)
					sum += bits[i];
				if (i < otherBitsSize)
					sum += other.bits[i];
				carry = sum > 1;
				resultBits.push_back(sum % 2);
			}
			return xieite::math::BigInteger(resultBits.begin(), resultBits.end(), sign);
		}

		template<std::integral N>
		[[nodiscard]]
		constexpr xieite::math::BigInteger operator+(const N value) const noexcept {
			return *this + xieite::math::BigInteger(value);
		}

		constexpr xieite::math::BigInteger& operator+=(const xieite::math::BigInteger& other) noexcept {
			return *this = *this + other;
		}

		template<std::integral N>
		constexpr xieite::math::BigInteger& operator+=(const N value) noexcept {
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
			if (copy)
				copy.sign = !copy.sign;
			return copy;
		}

		[[nodiscard]]
		constexpr xieite::math::BigInteger operator-(const xieite::math::BigInteger& other) const noexcept {
			if (!other)
				return *this;
			if (sign != other.sign)
				return *this + (-other);
			if (sign && *this > other || !sign && *this < other)
				return -(other - *this);
			std::vector<bool> resultBits = bits;
			bool borrow = false;
			const std::size_t bitsSize = bits.size();
			const std::size_t otherBitsSize = other.bits.size();
			for (std::size_t i = 0; i < otherBitsSize || borrow; ++i) {
				int difference = 2 - borrow + bits[i];
				if (i < otherBitsSize)
					difference -= other.bits[i];
				borrow = i < bitsSize - 1 && difference < 2;
				resultBits[i] = difference % 2;
			}
			return xieite::math::BigInteger(resultBits.begin(), resultBits.end(), sign != borrow);
		}

		template<std::integral N>
		[[nodiscard]]
		constexpr xieite::math::BigInteger operator-(const N value) const noexcept {
			return *this - xieite::math::BigInteger(value);
		}

		constexpr xieite::math::BigInteger& operator-=(const xieite::math::BigInteger& other) noexcept {
			return *this = *this - other;
		}

		template<std::integral N>
		constexpr xieite::math::BigInteger& operator-=(const N value) noexcept {
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
		constexpr xieite::math::BigInteger operator*(const xieite::math::BigInteger& other) const noexcept {
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
			const std::size_t halfSize = std::min(bits.size(), other.bits.size()) / 2;
			std::vector<bool>::const_iterator i = bits.begin();
			std::advance(i, halfSize);
			const xieite::math::BigInteger a(bits.begin(), i);
			const xieite::math::BigInteger b(i, bits.end());
			std::vector<bool>::const_iterator j = other.bits.begin();
			std::advance(j, halfSize);
			const xieite::math::BigInteger c(other.bits.begin(), j);
			const xieite::math::BigInteger d(j, other.bits.end());
			const xieite::math::BigInteger e = a * c;
			const xieite::math::BigInteger f = (a + b) * (c + d);
			const xieite::math::BigInteger g = b * d;
			xieite::math::BigInteger result = (g << (halfSize * 2)) + ((f - g - e) << halfSize) + e;
			result.sign = sign != other.sign;
			return result;
		}

		template<std::integral N>
		[[nodiscard]]
		constexpr xieite::math::BigInteger operator*(const N value) const noexcept {
			return *this * xieite::math::BigInteger(value);
		}

		constexpr xieite::math::BigInteger& operator*=(const xieite::math::BigInteger& other) noexcept {
			return *this = *this * other;
		}

		template<std::integral N>
		constexpr xieite::math::BigInteger& operator*=(const N value) noexcept {
			return *this *= xieite::math::BigInteger(value);
		}

		[[nodiscard]]
		constexpr xieite::math::BigInteger operator/(xieite::math::BigInteger other) const {
			if (!other)
				throw std::domain_error("Cannot divide by zero");
			if (other == 1)
				return *this;
			if (other == -1)
				return -*this;
			const bool otherSign = other.sign;
			other.sign = false;
			if (abs() < other)
				return xieite::math::BigInteger(0);
			std::vector<bool> resultBits;
			xieite::math::BigInteger difference;
			for (std::size_t i = bits.size(); i--;) {
				if (!difference)
					difference.bits.clear();
				difference.bits.insert(difference.bits.begin(), bits[i]);
				bool quotient = difference >= other;
				if (quotient)
					difference -= other;
				resultBits.insert(resultBits.begin(), quotient);
			}
			return xieite::math::BigInteger(resultBits.begin(), resultBits.end(), sign != otherSign);
		}

		template<std::integral N>
		[[nodiscard]]
		constexpr xieite::math::BigInteger operator/(const N value) const {
			return *this / xieite::math::BigInteger(value);
		}

		constexpr xieite::math::BigInteger& operator/=(const xieite::math::BigInteger& other) {
			return *this = *this / other;
		}

		template<std::integral N>
		constexpr xieite::math::BigInteger& operator/=(const N value) {
			return *this /= xieite::math::BigInteger(value);
		}

		[[nodiscard]]
		constexpr xieite::math::BigInteger operator%(xieite::math::BigInteger other) const {
			if (!other)
				throw std::domain_error("Cannot find remainder of division by zero");
			const xieite::math::BigInteger copy = abs();
			other.sign = false;
			if (!*this || other == 1 || copy == other)
				return xieite::math::BigInteger(0);
			if (copy < other)
				return *this;
			xieite::math::BigInteger difference;
			for (std::size_t i = bits.size(); i--;) {
				if (!difference)
					difference.bits.clear();
				difference.bits.insert(difference.bits.begin(), bits[i]);
				if (difference >= other)
					difference -= other;
			}
			difference.sign = sign;
			return difference;
		}

		template<std::integral N>
		[[nodiscard]]
		constexpr xieite::math::BigInteger operator%(const N value) const {
			return *this % xieite::math::BigInteger(value);
		}

		constexpr xieite::math::BigInteger& operator%=(const xieite::math::BigInteger& other) {
			return *this = *this % other;
		}

		template<std::integral N>
		constexpr xieite::math::BigInteger& operator%=(const N value) {
			return *this %= xieite::math::BigInteger(value);
		}

		[[nodiscard]]
		constexpr xieite::math::BigInteger operator~() const noexcept {
			return -(*this + 1);
		}

		[[nodiscard]]
		constexpr xieite::math::BigInteger operator&(const xieite::math::BigInteger& other) const noexcept {
			if (!*this || !other)
				return xieite::math::BigInteger(0);
			xieite::math::BigInteger copy = *this;
			const std::size_t bitsSize = bits.size();
			if (sign) {
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
			result.sign = sign && other.sign;
			for (std::size_t i = 0; i < bitsSize || i < otherBitsSize; ++i)
				result.bits.push_back(((i < bitsSize)
					? copy.bits[i]
					: sign)
						&& ((i < otherBitsSize)
							? otherCopy.bits[i]
							: other.sign));
			if (result.sign) {
				for (std::size_t i = 0; i < bitsSize || i < otherBitsSize; ++i)
					result.bits[i] = !result.bits[i];
				--result;
			}
			return result;
		}

		template<std::integral N>
		[[nodiscard]]
		constexpr xieite::math::BigInteger operator&(const N value) const noexcept {
			return *this & xieite::math::BigInteger(value);
		}

		constexpr xieite::math::BigInteger& operator&=(const xieite::math::BigInteger& other) noexcept {
			return *this = *this & other;
		}

		template<std::integral N>
		constexpr xieite::math::BigInteger& operator&=(const N value) noexcept {
			return *this &= xieite::math::BigInteger(value);
		}

		[[nodiscard]]
		constexpr xieite::math::BigInteger operator|(const xieite::math::BigInteger& other) const noexcept {
			if (!*this)
				return other;
			if (!other)
				return *this;
			xieite::math::BigInteger copy = *this;
			const std::size_t bitsSize = bits.size();
			if (sign) {
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
			result.sign = sign || other.sign;
			for (std::size_t i = 0; i < bitsSize || i < otherBitsSize; ++i)
				result.bits.push_back(((i < bitsSize)
					? copy.bits[i]
					: sign)
						|| ((i < otherBitsSize)
							? otherCopy.bits[i]
							: other.sign));
			if (result.sign) {
				for (std::size_t i = 0; i < bitsSize || i < otherBitsSize; ++i)
					result.bits[i] = !result.bits[i];
				--result;
			}
			return result;
		}

		template<std::integral N>
		[[nodiscard]]
		constexpr xieite::math::BigInteger operator|(const N value) const noexcept {
			return *this | xieite::math::BigInteger(value);
		}

		constexpr xieite::math::BigInteger& operator|=(const xieite::math::BigInteger& other) noexcept {
			return *this = *this | other;
		}

		template<std::integral N>
		constexpr xieite::math::BigInteger& operator|=(const N value) noexcept {
			return *this |= xieite::math::BigInteger(value);
		}

		[[nodiscard]]
		constexpr xieite::math::BigInteger operator^(const xieite::math::BigInteger& other) const noexcept {
			if (!*this)
				return other;
			if (!other)
				return *this;
			xieite::math::BigInteger copy = *this;
			const std::size_t bitsSize = bits.size();
			if (sign) {
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
			result.sign = sign != other.sign;
			for (std::size_t i = 0; i < bitsSize || i < otherBitsSize; ++i)
				result.bits.push_back(((i < bitsSize)
					? copy.bits[i]
					: sign)
						!= ((i < otherBitsSize)
							? otherCopy.bits[i]
							: other.sign));
			if (result.sign) {
				for (std::size_t i = 0; i < bitsSize || i < otherBitsSize; ++i)
					result.bits[i] = !result.bits[i];
				--result;
			}
			return result;
		}

		template<std::integral N>
		[[nodiscard]]
		constexpr xieite::math::BigInteger operator^(const N value) const noexcept {
			return *this ^ xieite::math::BigInteger(value);
		}

		constexpr xieite::math::BigInteger& operator^=(const xieite::math::BigInteger& other) noexcept {
			return *this = *this ^ other;
		}

		template<std::integral N>
		constexpr xieite::math::BigInteger& operator^=(const N value) noexcept {
			return *this ^= xieite::math::BigInteger(value);
		}

		[[nodiscard]]
		constexpr xieite::math::BigInteger operator<<(const xieite::math::BigInteger& other) const noexcept {
			if (other.sign || !*this)
				return xieite::math::BigInteger(0);
			if (!other)
				return *this;
			std::vector<bool> resultBits(static_cast<std::size_t>(other));
			resultBits.insert(resultBits.end(), bits.begin(), bits.end());
			return xieite::math::BigInteger(resultBits.begin(), resultBits.end(), sign);
		}

		template<std::integral N>
		[[nodiscard]]
		constexpr xieite::math::BigInteger operator<<(const N value) const noexcept {
			return *this << xieite::math::BigInteger(value);
		}

		constexpr xieite::math::BigInteger& operator<<=(const xieite::math::BigInteger& other) noexcept {
			return *this = *this << other;
		}

		template<std::integral N>
		constexpr xieite::math::BigInteger& operator<<=(const N value) noexcept {
			return *this <<= xieite::math::BigInteger(value);
		}

		[[nodiscard]]
		constexpr xieite::math::BigInteger operator>>(const xieite::math::BigInteger& other) const noexcept {
			if (!sign && other.sign || !*this)
				return BigInteger(0);
			if (!other)
				return *this;
			std::vector<bool> resultBits = bits;
			std::vector<bool>::iterator end = resultBits.begin();
			std::advance(end, static_cast<std::size_t>(other));
			resultBits.erase(resultBits.begin(), end);
			BigInteger result(resultBits.begin(), resultBits.end(), sign);
			return result
				? result
				: -xieite::math::BigInteger(sign);
		}

		template<std::integral N>
		[[nodiscard]]
		constexpr xieite::math::BigInteger operator>>(const N value) const noexcept {
			return *this >> BigInteger(value);
		}

		constexpr xieite::math::BigInteger operator>>=(const xieite::math::BigInteger& other) noexcept {
			return *this = *this >> other;
		}

		template<std::integral N>
		constexpr xieite::math::BigInteger operator>>=(const N value) noexcept {
			return *this >>= BigInteger(value);
		}

		[[nodiscard]]
		constexpr xieite::math::BigInteger abs() const noexcept {
			xieite::math::BigInteger copy = *this;
			copy.sign = false;
			return copy;
		}

		[[nodiscard]]
		constexpr xieite::math::BigInteger pow(xieite::math::BigInteger other) const {
			if (*this == 1 || other == 1)
				return *this;
			if (*this == -1)
				return other % 2
					? *this
					: -*this;
			if (!other)
				return xieite::math::BigInteger(1);
			if (other.sign) {
				if (!*this)
					throw std::domain_error("Cannot find power of zero to negative exponent");
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

		template<std::integral N>
		[[nodiscard]]
		constexpr xieite::math::BigInteger pow(const N value) const {
			return pow(xieite::math::BigInteger(value));
		}

		[[nodiscard]]
		constexpr xieite::math::BigInteger root(const xieite::math::BigInteger& other) const {
			if (sign)
				throw std::domain_error("Cannot find root of negative value");
			if (*this == 1)
				return xieite::math::BigInteger(1);
			if (other.sign)
				return xieite::math::BigInteger(0);
			xieite::math::BigInteger x = other - 1;
			xieite::math::BigInteger y = *this;
			xieite::math::BigInteger z = y + 1;
			while (y < z) {
				z = y;
				y = (x * y + *this / y.pow(x)) / other;
			}
			return z;
		}

		template<std::integral N>
		[[nodiscard]]
		constexpr xieite::math::BigInteger root(const N value) const {
			return root(xieite::math::BigInteger(value));
		}

		[[nodiscard]]
		constexpr const std::vector<bool>& data() const noexcept {
			return bits;
		}

		[[nodiscard]]
		constexpr std::string string() const noexcept {
			BigInteger copy = abs();
			std::string result;
			do {
				const std::vector<bool>& bits = (copy % 10).bits;
				const std::size_t bitsSize = bits.size();
				char digit = '0';
				int power = 1;
				for (const bool bit : bits) {
					digit += bit * power;
					power *= 2;
				}
				result = digit + result;
				copy /= 10;
			} while (copy);
			if (sign)
				result = '-' + result;
			return result;
		}
	};
}
