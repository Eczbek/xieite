export module xieite:math.BitField;

import std;
import :types.LeastInteger;

export namespace xieite::math {
	template<std::size_t bits, bool sign>
	struct BitField
	: std::type_identity<typename std::conditional_t<sign, std::make_signed<xieite::types::LeastInteger<bits>>, std::make_unsigned<xieite::types::LeastInteger<bits>>>::type> {
		typename BitField::type value : bits;

		template<std::integral Integral = int>
		explicit(false) constexpr BitField(const Integral value = 0) noexcept
		: value(static_cast<typename BitField::type>(value)) {}

		template<std::integral Integral>
		[[nodiscard]] explicit constexpr operator Integral() const noexcept {
			return static_cast<Integral>(this->value);
		}

		template<std::size_t otherBits, bool otherSign>
		[[nodiscard]] explicit constexpr operator BitField<otherBits, otherSign>() const noexcept {
			return BitField<otherBits, otherSign>(this->value);
		}

		[[nodiscard]] friend constexpr std::strong_ordering operator<=>(const BitField leftComparand, const BitField rightComparand) noexcept {
			return leftComparand.value <=> rightComparand.value;
		}

		[[nodiscard]] friend bool operator==(BitField, BitField) = default;

		[[nodiscard]] constexpr BitField operator+() const noexcept {
			return this->value;
		}

		[[nodiscard]] friend constexpr BitField operator+(const BitField augend, const BitField addend) noexcept {
			return BitField(augend.value + addend.value);
		}

		constexpr BitField& operator+=(const BitField addend) noexcept {
			return *this = *this + addend;
		}

		constexpr BitField& operator++() noexcept {
			++this->value;
			return *this;
		}

		constexpr BitField operator++(int) noexcept {
			return BitField(this->value++);
		}

		[[nodiscard]] constexpr BitField operator-() const noexcept {
			return BitField(-this->value);
		}

		[[nodiscard]] friend constexpr BitField operator-(const BitField minuend, const BitField subtrahend) noexcept {
			return BitField(minuend.value - subtrahend.value);
		}

		constexpr BitField& operator-=(const BitField subtrahend) noexcept {
			return *this = *this - subtrahend;
		}

		constexpr BitField& operator--() noexcept {
			--this->value;
			return *this;
		}

		constexpr BitField operator--(int) noexcept {
			return BitField(this->value--);
		}

		[[nodiscard]] friend constexpr BitField operator*(const BitField multiplier, const BitField multiplicand) noexcept {
			return BitField(multiplier.value * multiplicand.value);
		}

		constexpr BitField& operator*=(const BitField multiplicand) noexcept {
			return *this = *this * multiplicand;
		}

		[[nodiscard]] friend constexpr BitField operator/(const BitField dividend, const BitField divisor) noexcept {
			return BitField(dividend.value / divisor.value);
		}

		constexpr BitField& operator/=(const BitField divisor) noexcept {
			return *this = *this / divisor;
		}

		[[nodiscard]] friend constexpr BitField operator%(const BitField dividend, const BitField divisor) noexcept {
			return BitField(dividend.value % divisor.value);
		}

		constexpr BitField& operator%=(const BitField divisor) noexcept {
			return *this = *this % divisor;
		}

		[[nodiscard]] constexpr BitField operator~() const noexcept {
			return ~this->value;
		}

		[[nodiscard]] friend constexpr BitField operator&(const BitField left, const BitField right) noexcept {
			return BitField(left.value & right.value);
		}

		constexpr BitField& operator&=(const BitField right) noexcept {
			return *this = *this & right;
		}

		[[nodiscard]] friend constexpr BitField operator|(const BitField left, const BitField right) noexcept {
			return BitField(left.value | right.value);
		}

		constexpr BitField& operator|=(const BitField right) noexcept {
			return *this = *this | right;
		}

		[[nodiscard]] friend constexpr BitField operator^(const BitField left, const BitField right) noexcept {
			return BitField(left.value ^ right.value);
		}

		constexpr BitField& operator^=(const BitField right) noexcept {
			return *this = *this ^ right;
		}

		[[nodiscard]] friend constexpr BitField operator<<(const BitField value, const std::size_t right) noexcept {
			return BitField(value.value << right);
		}

		constexpr BitField operator<<=(const std::size_t right) noexcept {
			return *this = *this << right;
		}

		[[nodiscard]] friend constexpr BitField operator>>(const BitField value, const std::size_t right) noexcept {
			return BitField(value.value >> right);
		}

		constexpr BitField operator>>=(const std::size_t right) noexcept {
			return *this = *this >> right;
		}
	};
}
