#pragma once

#include <compare>
#include <concepts>
#include <cstddef>
#include <ostream>
#include <xieite/types/ConditionalIntegerSign.hpp>
#include <xieite/types/OptimalIntegerSize.hpp>

namespace xieite::math {
	template<std::size_t bits, bool sign>
	class Integer {
	private:
		xieite::types::ConditionalIntegerSign<xieite::types::OptimalIntegerSize<bits>, sign> value: bits;

	public:
		constexpr Integer(const std::integral auto value = 0) noexcept
		: value(value) {}

		constexpr Integer<bits, sign> operator=(const Integer<bits, sign> other) noexcept {
			this->value = other.value;
		}

		template<std::integral Integral>
		[[nodiscard]]
		constexpr operator Integral() const noexcept {
			return this->value;
		}

		template<std::size_t otherBits, bool otherSign>
		[[nodiscard]]
		constexpr operator xieite::math::Integer<otherBits, otherSign>() const noexcept {
			return this->value;
		}

		[[nodiscard]]
		constexpr bool operator==(const Integer<bits, sign> other) const noexcept {
			return this->value == other.value;
		}

		[[nodiscard]]
		constexpr std::strong_ordering operator<=>(const Integer<bits, sign> other) const noexcept {
			return this->value <=> other.value;
		}

		[[nodiscard]]
		constexpr Integer<bits, sign> operator+() const noexcept {
			return this->value;
		}

		[[nodiscard]]
		constexpr Integer<bits, sign> operator+(const Integer<bits, sign> other) const noexcept {
			return this->value + other.value;
		}

		constexpr Integer<bits, sign> operator+=(const Integer<bits, sign> other) noexcept {
			return this->value += other.value;
		}

		constexpr Integer<bits, sign> operator++() noexcept {
			return ++this->value;
		}

		constexpr Integer<bits, sign> operator++(int) noexcept {
			return this->value++;
		}

		[[nodiscard]]
		constexpr Integer<bits, sign> operator-() const noexcept {
			return -this->value;
		}

		[[nodiscard]]
		constexpr Integer<bits, sign> operator-(const Integer<bits, sign> other) const noexcept {
			return this->value - other.value;
		}

		constexpr Integer<bits, sign> operator-=(const Integer<bits, sign> other) noexcept {
			return this->value -= other.value;
		}

		constexpr Integer<bits, sign> operator--() noexcept {
			return --this->value;
		}

		constexpr Integer<bits, sign> operator--(int) noexcept {
			return this->value--;
		}

		[[nodiscard]]
		constexpr Integer<bits, sign> operator*(const Integer<bits, sign> other) const noexcept {
			return this->value * other.value;
		}

		constexpr Integer<bits, sign> operator*=(const Integer<bits, sign> other) noexcept {
			return this->value *= other.value;
		}

		[[nodiscard]]
		constexpr Integer<bits, sign> operator/(const Integer<bits, sign> other) const noexcept {
			return this->value / other.value;
		}

		constexpr Integer<bits, sign> operator/=(const Integer<bits, sign> other) noexcept {
			return this->value /= other.value;
		}

		[[nodiscard]]
		constexpr Integer<bits, sign> operator%(const Integer<bits, sign> other) const noexcept {
			return this->value % other.value;
		}

		constexpr Integer<bits, sign> operator%=(const Integer<bits, sign> other) noexcept {
			return this->value %= other.value;
		}

		[[nodiscard]]
		constexpr Integer<bits, sign> operator~() const noexcept {
			return ~this->value;
		}

		[[nodiscard]]
		constexpr Integer<bits, sign> operator|(const Integer<bits, sign> other) const noexcept {
			return this->value | other.value;
		}

		constexpr Integer<bits, sign> operator|=(const Integer<bits, sign> other) noexcept {
			return this->value |= other.value;
		}

		[[nodiscard]]
		constexpr Integer<bits, sign> operator&(const Integer<bits, sign> other) const noexcept {
			return this->value & other.value;
		}

		constexpr Integer<bits, sign> operator&=(const Integer<bits, sign> other) noexcept {
			return this->value &= other.value;
		}

		[[nodiscard]]
		constexpr Integer<bits, sign> operator^(const Integer<bits, sign> other) const noexcept {
			return this->value ^ other.value;
		}

		constexpr Integer<bits, sign> operator^=(const Integer<bits, sign> other) noexcept {
			return this->value ^= other.value;
		}

		[[nodiscard]]
		constexpr Integer<bits, sign> operator<<(const std::size_t other) const noexcept {
			return this->value << other;
		}

		constexpr Integer<bits, sign> operator<<=(const std::size_t other) noexcept {
			return this->value <<= other;
		}

		[[nodiscard]]
		constexpr Integer<bits, sign> operator>>(const std::size_t other) const noexcept {
			return this->value >> other;
		}

		constexpr Integer<bits, sign> operator>>=(const std::size_t other) noexcept {
			return this->value >>= other;
		}

		friend constexpr std::ostream& operator<<(std::ostream& outStream, const Integer<bits, sign> self) noexcept {
			return outStream << self.value;
		}

		friend constexpr std::istream& operator>>(std::istream& inStream, Integer<bits, sign> self) noexcept {
			return inStream >> self.value;
		}
	};
}
