#ifndef XIEITE_HEADER_MATH_INTEGER
#	define XIEITE_HEADER_MATH_INTEGER

#	include <compare>
#	include <concepts>
#	include <cstddef>
#	include "../types/maybe_signed.hpp"
#	include "../types/least_integer.hpp"

namespace xieite::math {
	template<std::size_t bits_, bool sign_>
	struct Integer {
	public:
		using Word = xieite::types::MaybeSigned<xieite::types::LeastInteger<bits_>, sign_>;

		template<std::integral OtherIntegral = int>
		constexpr Integer(const OtherIntegral value = 0) noexcept
		: value(static_cast<xieite::math::Integer<bits_, sign_>::Word>(value)) {}

		constexpr xieite::math::Integer<bits_, sign_> operator=(const xieite::math::Integer<bits_, sign_> value) noexcept {
			this->value = static_cast<xieite::math::Integer<bits_, sign_>::Word>(value.value);
		}

		template<std::integral OtherIntegral>
		[[nodiscard]] constexpr operator OtherIntegral() const noexcept {
			return static_cast<OtherIntegral>(this->value);
		}

		template<std::size_t otherBits, bool otherSign>
		[[nodiscard]] constexpr operator xieite::math::Integer<otherBits, otherSign>() const noexcept {
			return xieite::math::Integer<otherBits, otherSign>(this->value);
		}

		[[nodiscard]] friend constexpr std::strong_ordering operator<=>(const xieite::math::Integer<bits_, sign_> leftComparand, const xieite::math::Integer<bits_, sign_> rightComparand) noexcept {
			return leftComparand.value <=> rightComparand.value;
		}

		[[nodiscard]] friend constexpr bool operator==(const xieite::math::Integer<bits_, sign_> leftComparand, const xieite::math::Integer<bits_, sign_> rightComparand) noexcept {
			return leftComparand.value == rightComparand.value;
		}

		[[nodiscard]] constexpr xieite::math::Integer<bits_, sign_> operator+() const noexcept {
			return this->value;
		}

		[[nodiscard]] friend constexpr xieite::math::Integer<bits_, sign_> operator+(const xieite::math::Integer<bits_, sign_> augend, const xieite::math::Integer<bits_, sign_> addend) noexcept {
			return augend.value + addend.value;
		}

		constexpr xieite::math::Integer<bits_, sign_>& operator+=(const xieite::math::Integer<bits_, sign_> addend) noexcept {
			this->value += addend.value;
			return *this;
		}

		constexpr xieite::math::Integer<bits_, sign_>& operator++() noexcept {
			++this->value;
			return *this;
		}

		constexpr xieite::math::Integer<bits_, sign_> operator++(int) noexcept {
			return this->value++;
		}

		[[nodiscard]] constexpr xieite::math::Integer<bits_, sign_> operator-() const noexcept {
			return -this->value;
		}

		[[nodiscard]] friend constexpr xieite::math::Integer<bits_, sign_> operator-(const xieite::math::Integer<bits_, sign_> minuend, const xieite::math::Integer<bits_, sign_> subtrahend) noexcept {
			return minuend.value - subtrahend.value;
		}

		constexpr xieite::math::Integer<bits_, sign_>& operator-=(const xieite::math::Integer<bits_, sign_> subtrahend) noexcept {
			this->value -= subtrahend.value;
			return *this;
		}

		constexpr xieite::math::Integer<bits_, sign_>& operator--() noexcept {
			--this->value;
			return *this;
		}

		constexpr xieite::math::Integer<bits_, sign_> operator--(int) noexcept {
			return this->value--;
		}

		[[nodiscard]] friend constexpr xieite::math::Integer<bits_, sign_> operator*(const xieite::math::Integer<bits_, sign_> multiplier, const xieite::math::Integer<bits_, sign_> multiplicand) noexcept {
			return multiplier.value * multiplicand.value;
		}

		constexpr xieite::math::Integer<bits_, sign_>& operator*=(const xieite::math::Integer<bits_, sign_> multiplicand) noexcept {
			this->value *= multiplicand.value;
			return *this;
		}

		[[nodiscard]] friend constexpr xieite::math::Integer<bits_, sign_> operator/(const xieite::math::Integer<bits_, sign_> dividend, const xieite::math::Integer<bits_, sign_> divisor) noexcept {
			return dividend.value / divisor.value;
		}

		constexpr xieite::math::Integer<bits_, sign_> operator/=(const xieite::math::Integer<bits_, sign_> divisor) noexcept {
			this->value /= divisor.value;
			return *this;
		}

		[[nodiscard]] friend constexpr xieite::math::Integer<bits_, sign_> operator%(const xieite::math::Integer<bits_, sign_> dividend, const xieite::math::Integer<bits_, sign_> divisor) noexcept {
			return dividend.value % divisor.value;
		}

		constexpr xieite::math::Integer<bits_, sign_> operator%=(const xieite::math::Integer<bits_, sign_> divisor) noexcept {
			this->value %= divisor.value;
			return *this;
		}

		[[nodiscard]] constexpr xieite::math::Integer<bits_, sign_> operator~() const noexcept {
			return ~this->value;
		}

		[[nodiscard]] friend constexpr xieite::math::Integer<bits_, sign_> operator&(const xieite::math::Integer<bits_, sign_> leftOperand, const xieite::math::Integer<bits_, sign_> rightOperand) noexcept {
			return leftOperand.value & rightOperand.value;
		}

		constexpr xieite::math::Integer<bits_, sign_>& operator&=(const xieite::math::Integer<bits_, sign_> operand) noexcept {
			this->value &= operand.value;
			return *this;
		}

		[[nodiscard]] friend constexpr xieite::math::Integer<bits_, sign_> operator|(const xieite::math::Integer<bits_, sign_> leftOperand, const xieite::math::Integer<bits_, sign_> rightOperand) noexcept {
			return leftOperand.value | rightOperand.value;
		}

		constexpr xieite::math::Integer<bits_, sign_>& operator|=(const xieite::math::Integer<bits_, sign_> operand) noexcept {
			this->value |= operand.value;
			return *this;
		}

		[[nodiscard]] friend constexpr xieite::math::Integer<bits_, sign_> operator^(const xieite::math::Integer<bits_, sign_> leftOperand, const xieite::math::Integer<bits_, sign_> rightOperand) noexcept {
			return leftOperand.value ^ rightOperand.value;
		}

		constexpr xieite::math::Integer<bits_, sign_> operator^=(const xieite::math::Integer<bits_, sign_> operand) noexcept {
			this->value ^= operand.value;
			return *this;
		}

		[[nodiscard]] friend constexpr xieite::math::Integer<bits_, sign_> operator<<(const xieite::math::Integer<bits_, sign_> value, const std::size_t distance) noexcept {
			return value.value << distance;
		}

		constexpr xieite::math::Integer<bits_, sign_> operator<<=(const std::size_t distance) noexcept {
			this->value <<= distance;
			return *this;
		}

		[[nodiscard]] friend constexpr xieite::math::Integer<bits_, sign_> operator>>(const xieite::math::Integer<bits_, sign_> value, const std::size_t distance) noexcept {
			return value.value >> distance;
		}

		constexpr xieite::math::Integer<bits_, sign_> operator>>=(const std::size_t distance) noexcept {
			this->value >>= distance;
			return *this;
		}

		[[nodiscard]] constexpr xieite::math::Integer<bits_, sign_>::Word data() const noexcept {
			return this->value;
		}

	private:
		xieite::math::Integer<bits_, sign_>::Word value : bits_;
	};
}

#endif
