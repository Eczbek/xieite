#pragma once
#include <cctype>
#include <cmath>
#include <compare>
#include <concepts>
#include <ostream>
#include <stdexcept>
#include <string>
#include <string_view>
#include <vector>
#include <xieite/concepts/Arithmetic.hpp>

namespace xieite::math {
	class BigInt {
	private:
		bool sign;
		std::vector<bool> bits;

	public:
		constexpr BigInt(const xieite::math::BigInt& other) noexcept
		: sign(other.sign), bits(other.bits) {}

		template<std::signed_integral N = int>
		constexpr BigInt(N value = 0) noexcept
		: sign(value < 0) {
			value = std::abs(value);
			do {
				bits.push_back(value % 2);
				value /= 2;
			} while (value);
		}

		template<std::unsigned_integral N>
		constexpr BigInt(N value) noexcept
		: sign(false) {
			do {
				bits.push_back(value % 2);
				value /= 2;
			} while (value);
		}

		template<std::forward_iterator I>
		requires(std::convertible_to<typename I::value_type, bool>)
		constexpr BigInt(const I begin, const I end, const bool sign = false) noexcept
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

		constexpr BigInt(std::string_view value) noexcept {
			const bool isNegative = value[0] == '-';
			value.remove_prefix(isNegative || value[0] == '+');
			const std::size_t valueSize = value.size();
			for (std::size_t i = 0; i < valueSize && std::isdigit(static_cast<unsigned char>(value[i])); ++i)
				*this += xieite::math::BigInt(10).pow(valueSize - i - 1) * (value[i] - '0');
			*this *= -isNegative;
		}

		constexpr xieite::math::BigInt& operator=(const xieite::math::BigInt& other) noexcept {
			sign = other.sign;
			bits = other.bits;
			return *this;
		}

		template<std::integral N>
		constexpr xieite::math::BigInt& operator=(const N value) noexcept {
			return *this = xieite::math::BigInt(value);
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
		constexpr bool operator==(const xieite::math::BigInt& other) const noexcept {
			return sign == other.sign && bits == other.bits;
		}

		template<std::integral N>
		[[nodiscard]]
		constexpr bool operator==(const N value) const noexcept {
			return *this == xieite::math::BigInt(value);
		}

		[[nodiscard]]
		constexpr std::strong_ordering operator<=>(const xieite::math::BigInt& other) const noexcept {
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
			return *this <=> xieite::math::BigInt(value);
		}

		[[nodiscard]]
		constexpr xieite::math::BigInt operator+() const noexcept {
			return *this;
		}

		[[nodiscard]]
		constexpr xieite::math::BigInt operator+(const xieite::math::BigInt& other) const noexcept {
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
			return xieite::math::BigInt(resultBits.begin(), resultBits.end(), sign);
		}

		template<std::integral N>
		[[nodiscard]]
		constexpr xieite::math::BigInt operator+(const N value) const noexcept {
			return *this + xieite::math::BigInt(value);
		}

		constexpr xieite::math::BigInt& operator+=(const xieite::math::BigInt& other) noexcept {
			return *this = *this + other;
		}

		template<std::integral N>
		constexpr xieite::math::BigInt& operator+=(const N value) noexcept {
			return *this += xieite::math::BigInt(value);
		}

		constexpr xieite::math::BigInt& operator++() noexcept {
			return *this += 1;
		}

		constexpr xieite::math::BigInt operator++(int) noexcept {
			const xieite::math::BigInt copy = *this;
			++*this;
			return copy;
		}

		[[nodiscard]]
		constexpr xieite::math::BigInt operator-() const noexcept {
			xieite::math::BigInt copy = *this;
			if (copy)
				copy.sign = !copy.sign;
			return copy;
		}

		[[nodiscard]]
		constexpr xieite::math::BigInt operator-(const xieite::math::BigInt& other) const noexcept {
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
			return xieite::math::BigInt(resultBits.begin(), resultBits.end(), sign != borrow);
		}

		template<std::integral N>
		[[nodiscard]]
		constexpr xieite::math::BigInt operator-(const N value) const noexcept {
			return *this - xieite::math::BigInt(value);
		}

		constexpr xieite::math::BigInt& operator-=(const xieite::math::BigInt& other) noexcept {
			return *this = *this - other;
		}

		template<std::integral N>
		constexpr xieite::math::BigInt& operator-=(const N value) noexcept {
			return *this -= xieite::math::BigInt(value);
		}

		constexpr xieite::math::BigInt& operator--() noexcept {
			return *this -= 1;
		}

		constexpr xieite::math::BigInt operator--(int) noexcept {
			const xieite::math::BigInt copy = *this;
			--*this;
			return copy;
		}

		[[nodiscard]]
		constexpr xieite::math::BigInt operator*(const xieite::math::BigInt& other) const noexcept {
			if (!*this || !other)
				return xieite::math::BigInt(0);
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
			const xieite::math::BigInt a(bits.begin(), i);
			const xieite::math::BigInt b(i, bits.end());
			std::vector<bool>::const_iterator j = other.bits.begin();
			std::advance(j, halfSize);
			const xieite::math::BigInt c(other.bits.begin(), j);
			const xieite::math::BigInt d(j, other.bits.end());
			const xieite::math::BigInt e = a * c;
			const xieite::math::BigInt f = (a + b) * (c + d);
			const xieite::math::BigInt g = b * d;
			xieite::math::BigInt result = (g << (halfSize * 2)) + ((f - g - e) << halfSize) + e;
			result.sign = sign != other.sign;
			return result;
		}

		template<std::integral N>
		[[nodiscard]]
		constexpr xieite::math::BigInt operator*(const N value) const noexcept {
			return *this * xieite::math::BigInt(value);
		}

		constexpr xieite::math::BigInt& operator*=(const xieite::math::BigInt& other) noexcept {
			return *this = *this * other;
		}

		template<std::integral N>
		constexpr xieite::math::BigInt& operator*=(const N value) noexcept {
			return *this *= xieite::math::BigInt(value);
		}

		[[nodiscard]]
		constexpr xieite::math::BigInt operator/(xieite::math::BigInt other) const {
			if (!other)
				throw std::domain_error("Cannot divide by 0");
			if (other == 1)
				return *this;
			if (other == -1)
				return -*this;
			const bool otherSign = other.sign;
			other.sign = false;
			if (abs() < other)
				return xieite::math::BigInt(0);
			std::vector<bool> resultBits;
			xieite::math::BigInt difference;
			for (std::size_t i = bits.size(); i--;) {
				if (!difference)
					difference.bits.clear();
				difference.bits.insert(difference.bits.begin(), bits[i]);
				bool quotient = difference >= other;
				if (quotient)
					difference -= other;
				resultBits.insert(resultBits.begin(), quotient);
			}
			return xieite::math::BigInt(resultBits.begin(), resultBits.end(), sign != otherSign);
		}

		template<std::integral N>
		[[nodiscard]]
		constexpr xieite::math::BigInt operator/(const N value) const {
			return *this / xieite::math::BigInt(value);
		}

		constexpr xieite::math::BigInt& operator/=(const xieite::math::BigInt& other) {
			return *this = *this / other;
		}

		template<std::integral N>
		constexpr xieite::math::BigInt& operator/=(const N value) {
			return *this /= xieite::math::BigInt(value);
		}

		[[nodiscard]]
		constexpr xieite::math::BigInt operator%(xieite::math::BigInt other) const {
			if (!other)
				throw std::domain_error("Cannot divide by 0");
			const xieite::math::BigInt copy = abs();
			other.sign = false;
			if (!*this || other == 1 || copy == other)
				return xieite::math::BigInt(0);
			if (copy < other)
				return *this;
			xieite::math::BigInt difference;
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
		constexpr xieite::math::BigInt operator%(const N value) const {
			return *this % xieite::math::BigInt(value);
		}

		constexpr xieite::math::BigInt& operator%=(const xieite::math::BigInt& other) {
			return *this = *this % other;
		}

		template<std::integral N>
		constexpr xieite::math::BigInt& operator%=(const N value) {
			return *this %= xieite::math::BigInt(value);
		}

		[[nodiscard]]
		constexpr xieite::math::BigInt operator~() const noexcept {
			return -(*this + 1);
		}

		[[nodiscard]]
		constexpr xieite::math::BigInt operator&(const xieite::math::BigInt& other) const noexcept {
			if (!*this || !other)
				return xieite::math::BigInt(0);
			xieite::math::BigInt copy = *this;
			const std::size_t bitsSize = bits.size();
			if (sign) {
				++copy;
				for (std::size_t i = 0; i < bitsSize; ++i)
					copy.bits[i] = !copy.bits[i];
			}
			xieite::math::BigInt otherCopy = other;
			const std::size_t otherBitsSize = other.bits.size();
			if (other.sign) {
				++otherCopy;
				for (std::size_t i = 0; i < otherBitsSize; ++i)
					otherCopy.bits[i] = !otherCopy.bits[i];
			}
			xieite::math::BigInt result;
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
		constexpr xieite::math::BigInt operator&(const N value) const noexcept {
			return *this & xieite::math::BigInt(value);
		}

		constexpr xieite::math::BigInt& operator&=(const xieite::math::BigInt& other) noexcept {
			return *this = *this & other;
		}

		template<std::integral N>
		constexpr xieite::math::BigInt& operator&=(const N value) noexcept {
			return *this &= xieite::math::BigInt(value);
		}

		[[nodiscard]]
		constexpr xieite::math::BigInt operator|(const xieite::math::BigInt& other) const noexcept {
			if (!*this)
				return other;
			if (!other)
				return *this;
			xieite::math::BigInt copy = *this;
			const std::size_t bitsSize = bits.size();
			if (sign) {
				++copy;
				for (std::size_t i = 0; i < bitsSize; ++i)
					copy.bits[i] = !copy.bits[i];
			}
			xieite::math::BigInt otherCopy = other;
			const std::size_t otherBitsSize = other.bits.size();
			if (other.sign) {
				++otherCopy;
				for (std::size_t i = 0; i < otherBitsSize; ++i)
					otherCopy.bits[i] = !otherCopy.bits[i];
			}
			xieite::math::BigInt result;
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
		constexpr xieite::math::BigInt operator|(const N value) const noexcept {
			return *this | xieite::math::BigInt(value);
		}

		constexpr xieite::math::BigInt& operator|=(const xieite::math::BigInt& other) noexcept {
			return *this = *this | other;
		}

		template<std::integral N>
		constexpr xieite::math::BigInt& operator|=(const N value) noexcept {
			return *this |= xieite::math::BigInt(value);
		}

		[[nodiscard]]
		constexpr xieite::math::BigInt operator^(const xieite::math::BigInt& other) const noexcept {
			if (!*this)
				return other;
			if (!other)
				return *this;
			xieite::math::BigInt copy = *this;
			const std::size_t bitsSize = bits.size();
			if (sign) {
				++copy;
				for (std::size_t i = 0; i < bitsSize; ++i)
					copy.bits[i] = !copy.bits[i];
			}
			xieite::math::BigInt otherCopy = other;
			const std::size_t otherBitsSize = other.bits.size();
			if (other.sign) {
				++otherCopy;
				for (std::size_t i = 0; i < otherBitsSize; ++i)
					otherCopy.bits[i] = !otherCopy.bits[i];
			}
			xieite::math::BigInt result;
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
		constexpr xieite::math::BigInt operator^(const N value) const noexcept {
			return *this ^ xieite::math::BigInt(value);
		}

		constexpr xieite::math::BigInt& operator^=(const xieite::math::BigInt& other) noexcept {
			return *this = *this ^ other;
		}

		template<std::integral N>
		constexpr xieite::math::BigInt& operator^=(const N value) noexcept {
			return *this ^= xieite::math::BigInt(value);
		}

		[[nodiscard]]
		constexpr xieite::math::BigInt operator<<(const xieite::math::BigInt& other) const noexcept {
			if (other.sign || !*this)
				return xieite::math::BigInt(0);
			if (!other)
				return *this;
			std::vector<bool> resultBits(static_cast<std::size_t>(other));
			resultBits.insert(resultBits.end(), bits.begin(), bits.end());
			return xieite::math::BigInt(resultBits.begin(), resultBits.end(), sign);
		}

		template<std::integral N>
		[[nodiscard]]
		constexpr xieite::math::BigInt operator<<(const N value) const noexcept {
			return *this << xieite::math::BigInt(value);
		}

		constexpr xieite::math::BigInt& operator<<=(const xieite::math::BigInt& other) noexcept {
			return *this = *this << other;
		}

		template<std::integral N>
		constexpr xieite::math::BigInt& operator<<=(const N value) noexcept {
			return *this <<= xieite::math::BigInt(value);
		}

		[[nodiscard]]
		constexpr xieite::math::BigInt operator>>(const xieite::math::BigInt& other) const noexcept {
			if (!sign && other.sign || !*this)
				return BigInt(0);
			if (!other)
				return *this;
			std::vector<bool> resultBits = bits;
			std::vector<bool>::iterator end = resultBits.begin();
			std::advance(end, static_cast<std::size_t>(other));
			resultBits.erase(resultBits.begin(), end);
			BigInt result(resultBits.begin(), resultBits.end(), sign);
			return result
				? result
				: -xieite::math::BigInt(sign);
		}

		template<std::integral N>
		[[nodiscard]]
		constexpr xieite::math::BigInt operator>>(const N value) const noexcept {
			return *this >> BigInt(value);
		}

		constexpr xieite::math::BigInt operator>>=(const xieite::math::BigInt& other) noexcept {
			return *this = *this >> other;
		}

		template<std::integral N>
		constexpr xieite::math::BigInt operator>>=(const N value) noexcept {
			return *this >>= BigInt(value);
		}

		[[nodiscard]]
		constexpr xieite::math::BigInt abs() const noexcept {
			xieite::math::BigInt copy = *this;
			copy.sign = false;
			return copy;
		}

		[[nodiscard]]
		constexpr xieite::math::BigInt pow(xieite::math::BigInt other) const {
			if (*this == 1 || other == 1)
				return *this;
			if (*this == -1)
				return other % 2
					? *this
					: -*this;
			if (!other)
				return xieite::math::BigInt(1);
			if (other.sign) {
				if (!*this)
					throw std::domain_error("Cannot divide by 0");
				return !other;
			}
			if (!*this)
				return !other;
			xieite::math::BigInt x = *this;
			xieite::math::BigInt y = 1;
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
		constexpr xieite::math::BigInt pow(const N value) const {
			return pow(xieite::math::BigInt(value));
		}

		[[nodiscard]]
		constexpr xieite::math::BigInt root(const xieite::math::BigInt& other) const {
			if (sign)
				throw std::domain_error("Cannot find root of negative");
			if (*this == 1)
				return xieite::math::BigInt(1);
			if (other.sign)
				return xieite::math::BigInt(0);
			xieite::math::BigInt x = other - 1;
			xieite::math::BigInt y = *this;
			xieite::math::BigInt z = y + 1;
			while (y < z) {
				z = y;
				y = (x * y + *this / y.pow(x)) / other;
			}
			return z;
		}

		template<std::integral N>
		[[nodiscard]]
		constexpr xieite::math::BigInt root(const N value) const {
			return root(xieite::math::BigInt(value));
		}

		[[nodiscard]]
		constexpr const std::vector<bool>& data() const noexcept {
			return bits;
		}

		[[nodiscard]]
		constexpr std::string string() const noexcept {
			BigInt copy = abs();
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
