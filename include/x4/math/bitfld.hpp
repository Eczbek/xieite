#pragma once

#include <compare>
#include <cstddef>
#include <type_traits>
#include "../math/ileast.hpp"
#include "../math/uleast.hpp"

namespace x4 {
	template<std::size_t bits, bool sign>
	struct bitfld {
		using type = std::conditional_t<sign, x4::ileast<bits>, x4::uleast<bits>>;

		typename x4::bitfld<bits, sign>::type value : bits;

		template<std::integral T = int>
		[[nodiscard]] constexpr bitfld(T n = 0) noexcept
		: value(static_cast<typename x4::bitfld<bits, sign>::type>(n)) {}

		template<std::integral T>
		[[nodiscard]] explicit constexpr operator T() const noexcept {
			return static_cast<T>(this->value);
		}

		template<std::size_t other_bits, bool other_sign>
		[[nodiscard]] explicit constexpr operator x4::bitfld<other_bits, other_sign>() const noexcept {
			return x4::bitfld<other_bits, other_sign>(this->value);
		}

		[[nodiscard]] friend constexpr std::strong_ordering operator<=>(x4::bitfld<bits, sign> l, x4::bitfld<bits, sign> r) noexcept {
			return l.value <=> r.value;
		}

		[[nodiscard]] friend bool operator==(x4::bitfld<bits, sign>, x4::bitfld<bits, sign>) = default;

		[[nodiscard]] constexpr x4::bitfld<bits, sign> operator+() const noexcept {
			return this->value;
		}

		[[nodiscard]] friend constexpr x4::bitfld<bits, sign> operator+(x4::bitfld<bits, sign> l, x4::bitfld<bits, sign> r) noexcept {
			return x4::bitfld<bits, sign>(l.value + r.value);
		}

		constexpr x4::bitfld<bits, sign>& operator+=(x4::bitfld<bits, sign> r) noexcept {
			return *this = *this + r;
		}

		constexpr x4::bitfld<bits, sign>& operator++() noexcept {
			++this->value;
			return *this;
		}

		constexpr x4::bitfld<bits, sign> operator++(int) noexcept {
			return x4::bitfld<bits, sign>(this->value++);
		}

		[[nodiscard]] constexpr x4::bitfld<bits, sign> operator-() const noexcept {
			return x4::bitfld<bits, sign>(-this->value);
		}

		[[nodiscard]] friend constexpr x4::bitfld<bits, sign> operator-(x4::bitfld<bits, sign> l, x4::bitfld<bits, sign> r) noexcept {
			return x4::bitfld<bits, sign>(l.value - r.value);
		}

		constexpr x4::bitfld<bits, sign>& operator-=(x4::bitfld<bits, sign> r) noexcept {
			return *this = *this - r;
		}

		constexpr x4::bitfld<bits, sign>& operator--() noexcept {
			--this->value;
			return *this;
		}

		constexpr x4::bitfld<bits, sign> operator--(int) noexcept {
			return x4::bitfld<bits, sign>(this->value--);
		}

		[[nodiscard]] friend constexpr x4::bitfld<bits, sign> operator*(x4::bitfld<bits, sign> l, x4::bitfld<bits, sign> r) noexcept {
			return x4::bitfld<bits, sign>(l.value * r.value);
		}

		constexpr x4::bitfld<bits, sign>& operator*=(x4::bitfld<bits, sign> r) noexcept {
			return *this = *this * r;
		}

		[[nodiscard]] friend constexpr x4::bitfld<bits, sign> operator/(x4::bitfld<bits, sign> l, x4::bitfld<bits, sign> r) noexcept {
			return x4::bitfld<bits, sign>(l.value / r.value);
		}

		constexpr x4::bitfld<bits, sign>& operator/=(x4::bitfld<bits, sign> r) noexcept {
			return *this = *this / r;
		}

		[[nodiscard]] friend constexpr x4::bitfld<bits, sign> operator%(x4::bitfld<bits, sign> l, x4::bitfld<bits, sign> r) noexcept {
			return x4::bitfld<bits, sign>(l.value % r.value);
		}

		constexpr x4::bitfld<bits, sign>& operator%=(x4::bitfld<bits, sign> r) noexcept {
			return *this = *this % r;
		}

		[[nodiscard]] constexpr x4::bitfld<bits, sign> operator~() const noexcept {
			return ~this->value;
		}

		[[nodiscard]] friend constexpr x4::bitfld<bits, sign> operator&(x4::bitfld<bits, sign> l, x4::bitfld<bits, sign> r) noexcept {
			return x4::bitfld<bits, sign>(l.value & r.value);
		}

		constexpr x4::bitfld<bits, sign>& operator&=(x4::bitfld<bits, sign> r) noexcept {
			return *this = *this & r;
		}

		[[nodiscard]] friend constexpr x4::bitfld<bits, sign> operator|(x4::bitfld<bits, sign> l, x4::bitfld<bits, sign> r) noexcept {
			return x4::bitfld<bits, sign>(l.value | r.value);
		}

		constexpr x4::bitfld<bits, sign>& operator|=(x4::bitfld<bits, sign> r) noexcept {
			return *this = *this | r;
		}

		[[nodiscard]] friend constexpr x4::bitfld<bits, sign> operator^(x4::bitfld<bits, sign> l, x4::bitfld<bits, sign> r) noexcept {
			return x4::bitfld<bits, sign>(l.value ^ r.value);
		}

		constexpr x4::bitfld<bits, sign>& operator^=(x4::bitfld<bits, sign> r) noexcept {
			return *this = *this ^ r;
		}

		[[nodiscard]] friend constexpr x4::bitfld<bits, sign> operator<<(x4::bitfld<bits, sign> l, std::size_t r) noexcept {
			return x4::bitfld<bits, sign>(l.value << r);
		}

		constexpr x4::bitfld<bits, sign> operator<<=(std::size_t r) noexcept {
			return *this = *this << r;
		}

		[[nodiscard]] friend constexpr x4::bitfld<bits, sign> operator>>(x4::bitfld<bits, sign> l, std::size_t r) noexcept {
			return x4::bitfld<bits, sign>(l.value >> r);
		}

		constexpr x4::bitfld<bits, sign> operator>>=(std::size_t r) noexcept {
			return *this = *this >> r;
		}
	};
}
