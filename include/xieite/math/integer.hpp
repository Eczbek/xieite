#ifndef XIEITE_HEADER_MATH_INTEGER
#	define XIEITE_HEADER_MATH_INTEGER

#	include <compare>
#	include <concepts>
#	include <cstddef>
#	include "../types/conditionally_signed.hpp"
#	include "../types/least_integer.hpp"

namespace xieite::math {
	template<std::size_t bits, bool sign>
	struct Integer {
	public:
		using Type = xieite::types::ConditionallySigned<xieite::types::LeastInteger<bits>, sign>;

		template<std::integral OtherInteger = int>
		constexpr Integer(const OtherInteger value = 0) noexcept
		: value(static_cast<xieite::math::Integer<bits, sign>::Type>(value)) {}

		constexpr xieite::math::Integer<bits, sign> operator=(const xieite::math::Integer<bits, sign> value) noexcept {
			this->value = static_cast<xieite::math::Integer<bits, sign>::Type>(value.value);
		}

		template<std::integral OtherInteger>
		[[nodiscard]] constexpr operator OtherInteger() const noexcept {
			return static_cast<OtherInteger>(this->value);
		}

		template<std::size_t otherBits, bool otherSign>
		[[nodiscard]] constexpr operator xieite::math::Integer<otherBits, otherSign>() const noexcept {
			return xieite::math::Integer<otherBits, otherSign>(this->value);
		}

		[[nodiscard]] friend constexpr std::strong_ordering operator<=>(const xieite::math::Integer<bits, sign> leftComparand, const xieite::math::Integer<bits, sign> rightComparand) noexcept {
			return leftComparand.value <=> rightComparand.value;
		}

		[[nodiscard]] friend constexpr bool operator==(const xieite::math::Integer<bits, sign> leftComparand, const xieite::math::Integer<bits, sign> rightComparand) noexcept {
			return leftComparand.value == rightComparand.value;
		}

		[[nodiscard]] constexpr xieite::math::Integer<bits, sign> operator+() const noexcept {
			return this->value;
		}

		[[nodiscard]] friend constexpr xieite::math::Integer<bits, sign> operator+(const xieite::math::Integer<bits, sign> augend, const xieite::math::Integer<bits, sign> addend) noexcept {
			return augend.value + addend.value;
		}

		constexpr xieite::math::Integer<bits, sign>& operator+=(const xieite::math::Integer<bits, sign> addend) noexcept {
			this->value += addend.value;
			return *this;
		}

		constexpr xieite::math::Integer<bits, sign>& operator++() noexcept {
			++this->value;
			return *this;
		}

		constexpr xieite::math::Integer<bits, sign> operator++(int) noexcept {
			return this->value++;
		}

		[[nodiscard]] constexpr xieite::math::Integer<bits, sign> operator-() const noexcept {
			return -this->value;
		}

		[[nodiscard]] friend constexpr xieite::math::Integer<bits, sign> operator-(const xieite::math::Integer<bits, sign> minuend, const xieite::math::Integer<bits, sign> subtrahend) noexcept {
			return minuend.value - subtrahend.value;
		}

		constexpr xieite::math::Integer<bits, sign>& operator-=(const xieite::math::Integer<bits, sign> subtrahend) noexcept {
			this->value -= subtrahend.value;
			return *this;
		}

		constexpr xieite::math::Integer<bits, sign>& operator--() noexcept {
			--this->value;
			return *this;
		}

		constexpr xieite::math::Integer<bits, sign> operator--(int) noexcept {
			return this->value--;
		}

		[[nodiscard]] friend constexpr xieite::math::Integer<bits, sign> operator*(const xieite::math::Integer<bits, sign> multiplier, const xieite::math::Integer<bits, sign> multiplicand) noexcept {
			return multiplier.value * multiplicand.value;
		}

		constexpr xieite::math::Integer<bits, sign>& operator*=(const xieite::math::Integer<bits, sign> multiplicand) noexcept {
			this->value *= multiplicand.value;
			return *this;
		}

		[[nodiscard]] friend constexpr xieite::math::Integer<bits, sign> operator/(const xieite::math::Integer<bits, sign> dividend, const xieite::math::Integer<bits, sign> divisor) noexcept {
			return dividend.value / divisor.value;
		}

		constexpr xieite::math::Integer<bits, sign> operator/=(const xieite::math::Integer<bits, sign> divisor) noexcept {
			this->value /= divisor.value;
			return *this;
		}

		[[nodiscard]] friend constexpr xieite::math::Integer<bits, sign> operator%(const xieite::math::Integer<bits, sign> dividend, const xieite::math::Integer<bits, sign> divisor) noexcept {
			return dividend.value % divisor.value;
		}

		constexpr xieite::math::Integer<bits, sign> operator%=(const xieite::math::Integer<bits, sign> divisor) noexcept {
			this->value %= divisor.value;
			return *this;
		}

		[[nodiscard]] constexpr xieite::math::Integer<bits, sign> operator~() const noexcept {
			return ~this->value;
		}

		[[nodiscard]] friend constexpr xieite::math::Integer<bits, sign> operator&(const xieite::math::Integer<bits, sign> leftOperand, const xieite::math::Integer<bits, sign> rightOperand) noexcept {
			return leftOperand.value & rightOperand.value;
		}

		constexpr xieite::math::Integer<bits, sign>& operator&=(const xieite::math::Integer<bits, sign> operand) noexcept {
			this->value &= operand.value;
			return *this;
		}

		[[nodiscard]] friend constexpr xieite::math::Integer<bits, sign> operator|(const xieite::math::Integer<bits, sign> leftOperand, const xieite::math::Integer<bits, sign> rightOperand) noexcept {
			return leftOperand.value | rightOperand.value;
		}

		constexpr xieite::math::Integer<bits, sign>& operator|=(const xieite::math::Integer<bits, sign> operand) noexcept {
			this->value |= operand.value;
			return *this;
		}

		[[nodiscard]] friend constexpr xieite::math::Integer<bits, sign> operator^(const xieite::math::Integer<bits, sign> leftOperand, const xieite::math::Integer<bits, sign> rightOperand) noexcept {
			return leftOperand.value ^ rightOperand.value;
		}

		constexpr xieite::math::Integer<bits, sign> operator^=(const xieite::math::Integer<bits, sign> operand) noexcept {
			this->value ^= operand.value;
			return *this;
		}

		[[nodiscard]] friend constexpr xieite::math::Integer<bits, sign> operator<<(const xieite::math::Integer<bits, sign> value, const std::size_t distance) noexcept {
			return value.value << distance;
		}

		constexpr xieite::math::Integer<bits, sign> operator<<=(const std::size_t distance) noexcept {
			this->value <<= distance;
			return *this;
		}

		[[nodiscard]] friend constexpr xieite::math::Integer<bits, sign> operator>>(const xieite::math::Integer<bits, sign> value, const std::size_t distance) noexcept {
			return value.value >> distance;
		}

		constexpr xieite::math::Integer<bits, sign> operator>>=(const std::size_t distance) noexcept {
			this->value >>= distance;
			return *this;
		}

		[[nodiscard]] constexpr xieite::math::Integer<bits, sign>::Type data() const noexcept {
			return this->value;
		}

	private:
		xieite::math::Integer<bits, sign>::Type value : bits;
	};
}

#endif
