#ifndef DETAIL_XIEITE_HEADER_MATH_BIT_FIELD
#	define DETAIL_XIEITE_HEADER_MATH_BIT_FIELD
#
#	include <compare>
#	include <cstddef>
#	include <type_traits>
#	include "../math/least_int.hpp"
#	include "../math/least_uint.hpp"

namespace xieite {
	template<std::size_t bits, bool sign>
	struct bit_field {
		using type = std::conditional_t<sign, xieite::least_int<bits>, xieite::least_uint<bits>>;

		typename xieite::bit_field<bits, sign>::type value : bits;

		[[nodiscard]] constexpr bit_field(std::integral auto x = 0z) noexcept
		: value(static_cast<typename xieite::bit_field<bits, sign>::type>(x)) {}

		template<std::integral Int>
		[[nodiscard]] explicit constexpr operator Int() const noexcept {
			return static_cast<Int>(this->value);
		}

		template<std::size_t other_bits, bool other_sign>
		[[nodiscard]] explicit constexpr operator xieite::bit_field<other_bits, other_sign>() const noexcept {
			return xieite::bit_field<other_bits, other_sign>(this->value);
		}

		[[nodiscard]] friend constexpr std::strong_ordering operator<=>(xieite::bit_field<bits, sign> lhs, xieite::bit_field<bits, sign> rhs) noexcept {
			return lhs.value <=> rhs.value;
		}

		[[nodiscard]] friend bool operator==(xieite::bit_field<bits, sign>, xieite::bit_field<bits, sign>) = default;

		[[nodiscard]] constexpr xieite::bit_field<bits, sign> operator+() const noexcept {
			return this->value;
		}

		[[nodiscard]] friend constexpr xieite::bit_field<bits, sign> operator+(xieite::bit_field<bits, sign> lhs, xieite::bit_field<bits, sign> rhs) noexcept {
			return xieite::bit_field<bits, sign>(lhs.value + rhs.value);
		}

		constexpr xieite::bit_field<bits, sign>& operator+=(xieite::bit_field<bits, sign> rhs) noexcept {
			return *this = *this + rhs;
		}

		constexpr xieite::bit_field<bits, sign>& operator++() noexcept {
			++this->value;
			return *this;
		}

		constexpr xieite::bit_field<bits, sign> operator++(int) noexcept {
			return xieite::bit_field<bits, sign>(this->value++);
		}

		[[nodiscard]] constexpr xieite::bit_field<bits, sign> operator-() const noexcept {
			return xieite::bit_field<bits, sign>(-this->value);
		}

		[[nodiscard]] friend constexpr xieite::bit_field<bits, sign> operator-(xieite::bit_field<bits, sign> lhs, xieite::bit_field<bits, sign> rhs) noexcept {
			return xieite::bit_field<bits, sign>(lhs.value - rhs.value);
		}

		constexpr xieite::bit_field<bits, sign>& operator-=(xieite::bit_field<bits, sign> rhs) noexcept {
			return *this = *this - rhs;
		}

		constexpr xieite::bit_field<bits, sign>& operator--() noexcept {
			--this->value;
			return *this;
		}

		constexpr xieite::bit_field<bits, sign> operator--(int) noexcept {
			return xieite::bit_field<bits, sign>(this->value--);
		}

		[[nodiscard]] friend constexpr xieite::bit_field<bits, sign> operator*(xieite::bit_field<bits, sign> lhs, xieite::bit_field<bits, sign> rhs) noexcept {
			return xieite::bit_field<bits, sign>(lhs.value * rhs.value);
		}

		constexpr xieite::bit_field<bits, sign>& operator*=(xieite::bit_field<bits, sign> rhs) noexcept {
			return *this = *this * rhs;
		}

		[[nodiscard]] friend constexpr xieite::bit_field<bits, sign> operator/(xieite::bit_field<bits, sign> lhs, xieite::bit_field<bits, sign> rhs) noexcept {
			return xieite::bit_field<bits, sign>(lhs.value / rhs.value);
		}

		constexpr xieite::bit_field<bits, sign>& operator/=(xieite::bit_field<bits, sign> rhs) noexcept {
			return *this = *this / rhs;
		}

		[[nodiscard]] friend constexpr xieite::bit_field<bits, sign> operator%(xieite::bit_field<bits, sign> lhs, xieite::bit_field<bits, sign> rhs) noexcept {
			return xieite::bit_field<bits, sign>(lhs.value % rhs.value);
		}

		constexpr xieite::bit_field<bits, sign>& operator%=(xieite::bit_field<bits, sign> rhs) noexcept {
			return *this = *this % rhs;
		}

		[[nodiscard]] constexpr xieite::bit_field<bits, sign> operator~() const noexcept {
			return ~this->value;
		}

		[[nodiscard]] friend constexpr xieite::bit_field<bits, sign> operator&(xieite::bit_field<bits, sign> lhs, xieite::bit_field<bits, sign> rhs) noexcept {
			return xieite::bit_field<bits, sign>(lhs.value & rhs.value);
		}

		constexpr xieite::bit_field<bits, sign>& operator&=(xieite::bit_field<bits, sign> rhs) noexcept {
			return *this = *this & rhs;
		}

		[[nodiscard]] friend constexpr xieite::bit_field<bits, sign> operator|(xieite::bit_field<bits, sign> lhs, xieite::bit_field<bits, sign> rhs) noexcept {
			return xieite::bit_field<bits, sign>(lhs.value | rhs.value);
		}

		constexpr xieite::bit_field<bits, sign>& operator|=(xieite::bit_field<bits, sign> rhs) noexcept {
			return *this = *this | rhs;
		}

		[[nodiscard]] friend constexpr xieite::bit_field<bits, sign> operator^(xieite::bit_field<bits, sign> lhs, xieite::bit_field<bits, sign> rhs) noexcept {
			return xieite::bit_field<bits, sign>(lhs.value ^ rhs.value);
		}

		constexpr xieite::bit_field<bits, sign>& operator^=(xieite::bit_field<bits, sign> rhs) noexcept {
			return *this = *this ^ rhs;
		}

		[[nodiscard]] friend constexpr xieite::bit_field<bits, sign> operator<<(xieite::bit_field<bits, sign> lhs, std::size_t rhs) noexcept {
			return xieite::bit_field<bits, sign>(lhs.value << rhs);
		}

		constexpr xieite::bit_field<bits, sign> operator<<=(std::size_t rhs) noexcept {
			return *this = *this << rhs;
		}

		[[nodiscard]] friend constexpr xieite::bit_field<bits, sign> operator>>(xieite::bit_field<bits, sign> lhs, std::size_t rhs) noexcept {
			return xieite::bit_field<bits, sign>(lhs.value >> rhs);
		}

		constexpr xieite::bit_field<bits, sign> operator>>=(std::size_t rhs) noexcept {
			return *this = *this >> rhs;
		}
	};
}

#endif
