export module xieite:bit_field;

import std;
import :least_int;
import :least_uint;

export namespace xieite {
	template<std::size_t bits, bool sign>
	struct bit_field : std::conditional<sign, xieite::least_int<bits>, xieite::least_uint<bits>> {
		typename xieite::bit_field<bits, sign>::type value : bits;

		template<std::integral T = int>
		[[nodiscard]] explicit(false) constexpr bit_field(T value = 0) noexcept
		: value(static_cast<typename xieite::bit_field<bits, sign>::type>(value)) {}

		template<std::integral T>
		[[nodiscard]] explicit constexpr operator T() const noexcept {
			return static_cast<T>(this->value);
		}

		template<std::size_t other_bits, bool other_sign>
		[[nodiscard]] explicit constexpr operator xieite::bit_field<other_bits, other_sign>() const noexcept {
			return xieite::bit_field<other_bits, other_sign>(this->value);
		}

		[[nodiscard]] friend constexpr std::strong_ordering operator<=>(xieite::bit_field<bits, sign> left, xieite::bit_field<bits, sign> right) noexcept {
			return left.value <=> right.value;
		}

		[[nodiscard]] friend bool operator==(xieite::bit_field<bits, sign>, xieite::bit_field<bits, sign>) = default;

		[[nodiscard]] constexpr xieite::bit_field<bits, sign> operator+() const noexcept {
			return this->value;
		}

		[[nodiscard]] friend constexpr xieite::bit_field<bits, sign> operator+(xieite::bit_field<bits, sign> augend, xieite::bit_field<bits, sign> addend) noexcept {
			return xieite::bit_field<bits, sign>(augend.value + addend.value);
		}

		constexpr xieite::bit_field<bits, sign>& operator+=(xieite::bit_field<bits, sign> addend) noexcept {
			return *this = *this + addend;
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

		[[nodiscard]] friend constexpr xieite::bit_field<bits, sign> operator-(xieite::bit_field<bits, sign> minuend, xieite::bit_field<bits, sign> subtrahend) noexcept {
			return xieite::bit_field<bits, sign>(minuend.value - subtrahend.value);
		}

		constexpr xieite::bit_field<bits, sign>& operator-=(xieite::bit_field<bits, sign> subtrahend) noexcept {
			return *this = *this - subtrahend;
		}

		constexpr xieite::bit_field<bits, sign>& operator--() noexcept {
			--this->value;
			return *this;
		}

		constexpr xieite::bit_field<bits, sign> operator--(int) noexcept {
			return xieite::bit_field<bits, sign>(this->value--);
		}

		[[nodiscard]] friend constexpr xieite::bit_field<bits, sign> operator*(xieite::bit_field<bits, sign> multiplier, xieite::bit_field<bits, sign> multiplicand) noexcept {
			return xieite::bit_field<bits, sign>(multiplier.value * multiplicand.value);
		}

		constexpr xieite::bit_field<bits, sign>& operator*=(xieite::bit_field<bits, sign> multiplicand) noexcept {
			return *this = *this * multiplicand;
		}

		[[nodiscard]] friend constexpr xieite::bit_field<bits, sign> operator/(xieite::bit_field<bits, sign> dividend, xieite::bit_field<bits, sign> divisor) noexcept {
			return xieite::bit_field<bits, sign>(dividend.value / divisor.value);
		}

		constexpr xieite::bit_field<bits, sign>& operator/=(xieite::bit_field<bits, sign> divisor) noexcept {
			return *this = *this / divisor;
		}

		[[nodiscard]] friend constexpr xieite::bit_field<bits, sign> operator%(xieite::bit_field<bits, sign> dividend, xieite::bit_field<bits, sign> divisor) noexcept {
			return xieite::bit_field<bits, sign>(dividend.value % divisor.value);
		}

		constexpr xieite::bit_field<bits, sign>& operator%=(xieite::bit_field<bits, sign> divisor) noexcept {
			return *this = *this % divisor;
		}

		[[nodiscard]] constexpr xieite::bit_field<bits, sign> operator~() const noexcept {
			return ~this->value;
		}

		[[nodiscard]] friend constexpr xieite::bit_field<bits, sign> operator&(xieite::bit_field<bits, sign> left, xieite::bit_field<bits, sign> right) noexcept {
			return xieite::bit_field<bits, sign>(left.value & right.value);
		}

		constexpr xieite::bit_field<bits, sign>& operator&=(xieite::bit_field<bits, sign> right) noexcept {
			return *this = *this & right;
		}

		[[nodiscard]] friend constexpr xieite::bit_field<bits, sign> operator|(xieite::bit_field<bits, sign> left, xieite::bit_field<bits, sign> right) noexcept {
			return xieite::bit_field<bits, sign>(left.value | right.value);
		}

		constexpr xieite::bit_field<bits, sign>& operator|=(xieite::bit_field<bits, sign> right) noexcept {
			return *this = *this | right;
		}

		[[nodiscard]] friend constexpr xieite::bit_field<bits, sign> operator^(xieite::bit_field<bits, sign> left, xieite::bit_field<bits, sign> right) noexcept {
			return xieite::bit_field<bits, sign>(left.value ^ right.value);
		}

		constexpr xieite::bit_field<bits, sign>& operator^=(xieite::bit_field<bits, sign> right) noexcept {
			return *this = *this ^ right;
		}

		[[nodiscard]] friend constexpr xieite::bit_field<bits, sign> operator<<(xieite::bit_field<bits, sign> value, std::size_t right) noexcept {
			return xieite::bit_field<bits, sign>(value.value << right);
		}

		constexpr xieite::bit_field<bits, sign> operator<<=(std::size_t right) noexcept {
			return *this = *this << right;
		}

		[[nodiscard]] friend constexpr xieite::bit_field<bits, sign> operator>>(xieite::bit_field<bits, sign> value, std::size_t right) noexcept {
			return xieite::bit_field<bits, sign>(value.value >> right);
		}

		constexpr xieite::bit_field<bits, sign> operator>>=(std::size_t right) noexcept {
			return *this = *this >> right;
		}
	};
}
