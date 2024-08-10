#ifndef XIEITE_HEADER_MATH_INTEGER
#	define XIEITE_HEADER_MATH_INTEGER

#	include <compare>
#	include <concepts>
#	include <cstddef>
#	include <type_traits>
#	include "../types/maybe_signed.hpp"
#	include "../types/least_integer.hpp"

namespace xieite::math {
	template<std::size_t bits_, bool signed_>
	struct Integer {
	public:
		using Word = std::conditional_t<signed_, std::make_signed<xieite::types::LeastInteger<bits_>>, std::make_unsigned<xieite::types::LeastInteger<bits_>>>::type;

		template<std::integral OtherIntegral_ = int>
		constexpr Integer(const OtherIntegral_ value = 0) noexcept
		: value(static_cast<xieite::math::Integer<bits_, signed_>::Word>(value)) {}

		constexpr xieite::math::Integer<bits_, signed_> operator=(const xieite::math::Integer<bits_, signed_> value) noexcept {
			this->value = static_cast<xieite::math::Integer<bits_, signed_>::Word>(value.value);
		}

		template<std::integral OtherIntegral_>
		[[nodiscard]] explicit constexpr operator OtherIntegral_() const noexcept {
			return static_cast<OtherIntegral_>(this->value);
		}

		template<std::size_t otherBits_, bool otherSigned_>
		[[nodiscard]] explicit constexpr operator xieite::math::Integer<otherBits_, otherSigned_>() const noexcept {
			return xieite::math::Integer<otherBits_, otherSigned_>(this->value);
		}

		[[nodiscard]] friend constexpr std::strong_ordering operator<=>(const xieite::math::Integer<bits_, signed_> leftComparand, const xieite::math::Integer<bits_, signed_> rightComparand) noexcept {
			return leftComparand.value <=> rightComparand.value;
		}

		[[nodiscard]] friend constexpr bool operator==(const xieite::math::Integer<bits_, signed_> leftComparand, const xieite::math::Integer<bits_, signed_> rightComparand) noexcept {
			return leftComparand.value == rightComparand.value;
		}

		[[nodiscard]] constexpr xieite::math::Integer<bits_, signed_> operator+() const noexcept {
			return this->value;
		}

		[[nodiscard]] friend constexpr xieite::math::Integer<bits_, signed_> operator+(const xieite::math::Integer<bits_, signed_> augend, const xieite::math::Integer<bits_, signed_> addend) noexcept {
			return augend.value + addend.value;
		}

		constexpr xieite::math::Integer<bits_, signed_>& operator+=(const xieite::math::Integer<bits_, signed_> addend) noexcept {
			this->value += addend.value;
			return *this;
		}

		constexpr xieite::math::Integer<bits_, signed_>& operator++() noexcept {
			++this->value;
			return *this;
		}

		constexpr xieite::math::Integer<bits_, signed_> operator++(int) noexcept {
			return this->value++;
		}

		[[nodiscard]] constexpr xieite::math::Integer<bits_, signed_> operator-() const noexcept {
			return -this->value;
		}

		[[nodiscard]] friend constexpr xieite::math::Integer<bits_, signed_> operator-(const xieite::math::Integer<bits_, signed_> minuend, const xieite::math::Integer<bits_, signed_> subtrahend) noexcept {
			return minuend.value - subtrahend.value;
		}

		constexpr xieite::math::Integer<bits_, signed_>& operator-=(const xieite::math::Integer<bits_, signed_> subtrahend) noexcept {
			this->value -= subtrahend.value;
			return *this;
		}

		constexpr xieite::math::Integer<bits_, signed_>& operator--() noexcept {
			--this->value;
			return *this;
		}

		constexpr xieite::math::Integer<bits_, signed_> operator--(int) noexcept {
			return this->value--;
		}

		[[nodiscard]] friend constexpr xieite::math::Integer<bits_, signed_> operator*(const xieite::math::Integer<bits_, signed_> multiplier, const xieite::math::Integer<bits_, signed_> multiplicand) noexcept {
			return multiplier.value * multiplicand.value;
		}

		constexpr xieite::math::Integer<bits_, signed_>& operator*=(const xieite::math::Integer<bits_, signed_> multiplicand) noexcept {
			this->value *= multiplicand.value;
			return *this;
		}

		[[nodiscard]] friend constexpr xieite::math::Integer<bits_, signed_> operator/(const xieite::math::Integer<bits_, signed_> dividend, const xieite::math::Integer<bits_, signed_> divisor) noexcept {
			return dividend.value / divisor.value;
		}

		constexpr xieite::math::Integer<bits_, signed_> operator/=(const xieite::math::Integer<bits_, signed_> divisor) noexcept {
			this->value /= divisor.value;
			return *this;
		}

		[[nodiscard]] friend constexpr xieite::math::Integer<bits_, signed_> operator%(const xieite::math::Integer<bits_, signed_> dividend, const xieite::math::Integer<bits_, signed_> divisor) noexcept {
			return dividend.value % divisor.value;
		}

		constexpr xieite::math::Integer<bits_, signed_> operator%=(const xieite::math::Integer<bits_, signed_> divisor) noexcept {
			this->value %= divisor.value;
			return *this;
		}

		[[nodiscard]] constexpr xieite::math::Integer<bits_, signed_> operator~() const noexcept {
			return ~this->value;
		}

		[[nodiscard]] friend constexpr xieite::math::Integer<bits_, signed_> operator&(const xieite::math::Integer<bits_, signed_> leftOperand, const xieite::math::Integer<bits_, signed_> rightOperand) noexcept {
			return leftOperand.value & rightOperand.value;
		}

		constexpr xieite::math::Integer<bits_, signed_>& operator&=(const xieite::math::Integer<bits_, signed_> operand) noexcept {
			this->value &= operand.value;
			return *this;
		}

		[[nodiscard]] friend constexpr xieite::math::Integer<bits_, signed_> operator|(const xieite::math::Integer<bits_, signed_> leftOperand, const xieite::math::Integer<bits_, signed_> rightOperand) noexcept {
			return leftOperand.value | rightOperand.value;
		}

		constexpr xieite::math::Integer<bits_, signed_>& operator|=(const xieite::math::Integer<bits_, signed_> operand) noexcept {
			this->value |= operand.value;
			return *this;
		}

		[[nodiscard]] friend constexpr xieite::math::Integer<bits_, signed_> operator^(const xieite::math::Integer<bits_, signed_> leftOperand, const xieite::math::Integer<bits_, signed_> rightOperand) noexcept {
			return leftOperand.value ^ rightOperand.value;
		}

		constexpr xieite::math::Integer<bits_, signed_> operator^=(const xieite::math::Integer<bits_, signed_> operand) noexcept {
			this->value ^= operand.value;
			return *this;
		}

		[[nodiscard]] friend constexpr xieite::math::Integer<bits_, signed_> operator<<(const xieite::math::Integer<bits_, signed_> value, const std::size_t distance) noexcept {
			return value.value << distance;
		}

		constexpr xieite::math::Integer<bits_, signed_> operator<<=(const std::size_t distance) noexcept {
			this->value <<= distance;
			return *this;
		}

		[[nodiscard]] friend constexpr xieite::math::Integer<bits_, signed_> operator>>(const xieite::math::Integer<bits_, signed_> value, const std::size_t distance) noexcept {
			return value.value >> distance;
		}

		constexpr xieite::math::Integer<bits_, signed_> operator>>=(const std::size_t distance) noexcept {
			this->value >>= distance;
			return *this;
		}

		[[nodiscard]] constexpr xieite::math::Integer<bits_, signed_>::Word data() const noexcept {
			return this->value;
		}

	private:
		xieite::math::Integer<bits_, signed_>::Word value : bits_;
	};
}

#endif
