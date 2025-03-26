#ifndef DETAIL_XIEITE_HEADER_MATH_BIT_FIELD
#	define DETAIL_XIEITE_HEADER_MATH_BIT_FIELD
#
#	include <compare>
#	include <cstddef>
#	include <type_traits>
#	include "../math/least_int.hpp"
#	include "../math/least_uint.hpp"
#	include "../math/ssize_t.hpp"

namespace xieite {
	template<std::size_t bits, bool sign>
	struct bit_field {
		using type = std::conditional_t<sign, xieite::least_int<bits>, xieite::least_uint<bits>>;

		typename xieite::bit_field<bits, sign>::type value : bits;

		template<std::integral T = xieite::ssize_t>
		[[nodiscard]] constexpr bit_field(T n = 0) noexcept
		: value(static_cast<typename xieite::bit_field<bits, sign>::type>(n)) {}

		template<std::integral T>
		[[nodiscard]] explicit constexpr operator T() const noexcept {
			return static_cast<T>(this->value);
		}

		template<std::size_t other_bits, bool other_sign>
		[[nodiscard]] explicit constexpr operator xieite::bit_field<other_bits, other_sign>() const noexcept {
			return xieite::bit_field<other_bits, other_sign>(this->value);
		}

		[[nodiscard]] friend constexpr std::strong_ordering operator<=>(xieite::bit_field<bits, sign> l, xieite::bit_field<bits, sign> r) noexcept {
			return l.value <=> r.value;
		}

		[[nodiscard]] friend bool operator==(xieite::bit_field<bits, sign>, xieite::bit_field<bits, sign>) = default;

		[[nodiscard]] constexpr xieite::bit_field<bits, sign> operator+() const noexcept {
			return this->value;
		}

		[[nodiscard]] friend constexpr xieite::bit_field<bits, sign> operator+(xieite::bit_field<bits, sign> l, xieite::bit_field<bits, sign> r) noexcept {
			return xieite::bit_field<bits, sign>(l.value + r.value);
		}

		constexpr xieite::bit_field<bits, sign>& operator+=(xieite::bit_field<bits, sign> r) noexcept {
			return *this = *this + r;
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

		[[nodiscard]] friend constexpr xieite::bit_field<bits, sign> operator-(xieite::bit_field<bits, sign> l, xieite::bit_field<bits, sign> r) noexcept {
			return xieite::bit_field<bits, sign>(l.value - r.value);
		}

		constexpr xieite::bit_field<bits, sign>& operator-=(xieite::bit_field<bits, sign> r) noexcept {
			return *this = *this - r;
		}

		constexpr xieite::bit_field<bits, sign>& operator--() noexcept {
			--this->value;
			return *this;
		}

		constexpr xieite::bit_field<bits, sign> operator--(int) noexcept {
			return xieite::bit_field<bits, sign>(this->value--);
		}

		[[nodiscard]] friend constexpr xieite::bit_field<bits, sign> operator*(xieite::bit_field<bits, sign> l, xieite::bit_field<bits, sign> r) noexcept {
			return xieite::bit_field<bits, sign>(l.value * r.value);
		}

		constexpr xieite::bit_field<bits, sign>& operator*=(xieite::bit_field<bits, sign> r) noexcept {
			return *this = *this * r;
		}

		[[nodiscard]] friend constexpr xieite::bit_field<bits, sign> operator/(xieite::bit_field<bits, sign> l, xieite::bit_field<bits, sign> r) noexcept {
			return xieite::bit_field<bits, sign>(l.value / r.value);
		}

		constexpr xieite::bit_field<bits, sign>& operator/=(xieite::bit_field<bits, sign> r) noexcept {
			return *this = *this / r;
		}

		[[nodiscard]] friend constexpr xieite::bit_field<bits, sign> operator%(xieite::bit_field<bits, sign> l, xieite::bit_field<bits, sign> r) noexcept {
			return xieite::bit_field<bits, sign>(l.value % r.value);
		}

		constexpr xieite::bit_field<bits, sign>& operator%=(xieite::bit_field<bits, sign> r) noexcept {
			return *this = *this % r;
		}

		[[nodiscard]] constexpr xieite::bit_field<bits, sign> operator~() const noexcept {
			return ~this->value;
		}

		[[nodiscard]] friend constexpr xieite::bit_field<bits, sign> operator&(xieite::bit_field<bits, sign> l, xieite::bit_field<bits, sign> r) noexcept {
			return xieite::bit_field<bits, sign>(l.value & r.value);
		}

		constexpr xieite::bit_field<bits, sign>& operator&=(xieite::bit_field<bits, sign> r) noexcept {
			return *this = *this & r;
		}

		[[nodiscard]] friend constexpr xieite::bit_field<bits, sign> operator|(xieite::bit_field<bits, sign> l, xieite::bit_field<bits, sign> r) noexcept {
			return xieite::bit_field<bits, sign>(l.value | r.value);
		}

		constexpr xieite::bit_field<bits, sign>& operator|=(xieite::bit_field<bits, sign> r) noexcept {
			return *this = *this | r;
		}

		[[nodiscard]] friend constexpr xieite::bit_field<bits, sign> operator^(xieite::bit_field<bits, sign> l, xieite::bit_field<bits, sign> r) noexcept {
			return xieite::bit_field<bits, sign>(l.value ^ r.value);
		}

		constexpr xieite::bit_field<bits, sign>& operator^=(xieite::bit_field<bits, sign> r) noexcept {
			return *this = *this ^ r;
		}

		[[nodiscard]] friend constexpr xieite::bit_field<bits, sign> operator<<(xieite::bit_field<bits, sign> l, std::size_t r) noexcept {
			return xieite::bit_field<bits, sign>(l.value << r);
		}

		constexpr xieite::bit_field<bits, sign> operator<<=(std::size_t r) noexcept {
			return *this = *this << r;
		}

		[[nodiscard]] friend constexpr xieite::bit_field<bits, sign> operator>>(xieite::bit_field<bits, sign> l, std::size_t r) noexcept {
			return xieite::bit_field<bits, sign>(l.value >> r);
		}

		constexpr xieite::bit_field<bits, sign> operator>>=(std::size_t r) noexcept {
			return *this = *this >> r;
		}
	};
}

#endif
