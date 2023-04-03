#pragma once

#include <compare>
#include <concepts>
#include <cstddef>

namespace xieite::math {
	template<std::size_t bits, std::integral Value = int>
	class [[gnu::packed]] Integer {
	private:
		Value value: bits;

	public:
		constexpr Integer(const Value value = 0) noexcept
		: value(value) {}

		constexpr xieite::math::Integer<bits> operator=(const xieite::math::Integer<bits> other) noexcept {
			return this->value = other.value;
		}

		template<std::integral Integral>
		[[nodiscard]]
		constexpr operator Integral() const noexcept {
			return this->value;
		}

		[[nodiscard]]
		constexpr bool operator==(const xieite::math::Integer<bits> other) const noexcept {
			return this->value == other.value;
		}

		[[nodiscard]]
		constexpr std::strong_ordering operator<=>(const xieite::math::Integer<bits> other) const noexcept {
			return this->value <=> other.value;
		}

		[[nodiscard]]
		constexpr xieite::math::Integer<bits> operator+() const noexcept {
			return this->value;
		}

		[[nodiscard]]
		constexpr xieite::math::Integer<bits> operator+(const xieite::math::Integer<bits> other) const noexcept {
			return this->value + other.value;
		}

		constexpr xieite::math::Integer<bits> operator+=(const xieite::math::Integer<bits> other) noexcept {
			return this->value += other.value;
		}

		constexpr xieite::math::Integer<bits> operator++() noexcept {
			return ++this->value;
		}

		constexpr xieite::math::Integer<bits> operator++(int) noexcept {
			return this->value++;
		}

		[[nodiscard]]
		constexpr xieite::math::Integer<bits> operator-() const noexcept {
			return -this->value;
		}

		[[nodiscard]]
		constexpr xieite::math::Integer<bits> operator-(const xieite::math::Integer<bits> other) const noexcept {
			return this->value - other.value;
		}

		constexpr xieite::math::Integer<bits> operator-=(const xieite::math::Integer<bits> other) noexcept {
			return this->value -= other.value;
		}

		constexpr xieite::math::Integer<bits> operator--() noexcept {
			return --this->value;
		}

		constexpr xieite::math::Integer<bits> operator--(int) noexcept {
			return this->value--;
		}

		[[nodiscard]]
		constexpr xieite::math::Integer<bits> operator*(const xieite::math::Integer<bits> other) const noexcept {
			return this->value * other.value;
		}

		constexpr xieite::math::Integer<bits> operator*=(const xieite::math::Integer<bits> other) noexcept {
			return this->value *= other.value;
		}

		[[nodiscard]]
		constexpr xieite::math::Integer<bits> operator/(const xieite::math::Integer<bits> other) const noexcept {
			return this->value / other.value;
		}

		constexpr xieite::math::Integer<bits> operator/=(const xieite::math::Integer<bits> other) noexcept {
			return this->value /= other.value;
		}

		[[nodiscard]]
		constexpr xieite::math::Integer<bits> operator%(const xieite::math::Integer<bits> other) const noexcept {
			return this->value % other.value;
		}

		constexpr xieite::math::Integer<bits> operator%=(const xieite::math::Integer<bits> other) noexcept {
			return this->value %= other.value;
		}

		[[nodiscard]]
		constexpr xieite::math::Integer<bits> operator~() const noexcept {
			return ~this->value;
		}

		[[nodiscard]]
		constexpr xieite::math::Integer<bits> operator|(const xieite::math::Integer<bits> other) const noexcept {
			return this->value | other.value;
		}

		constexpr xieite::math::Integer<bits> operator|=(const xieite::math::Integer<bits> other) noexcept {
			return this->value |= other.value;
		}

		[[nodiscard]]
		constexpr xieite::math::Integer<bits> operator&(const xieite::math::Integer<bits> other) const noexcept {
			return this->value & other.value;
		}

		constexpr xieite::math::Integer<bits> operator&=(const xieite::math::Integer<bits> other) noexcept {
			return this->value &= other.value;
		}

		[[nodiscard]]
		constexpr xieite::math::Integer<bits> operator^(const xieite::math::Integer<bits> other) const noexcept {
			return this->value ^ other.value;
		}

		constexpr xieite::math::Integer<bits> operator^=(const xieite::math::Integer<bits> other) noexcept {
			return this->value ^= other.value;
		}

		[[nodiscard]]
		constexpr xieite::math::Integer<bits> operator<<(const std::size_t other) const noexcept {
			return this->value << other;
		}

		constexpr xieite::math::Integer<bits> operator<<=(const std::size_t other) noexcept {
			return this->value <<= other;
		}

		[[nodiscard]]
		constexpr xieite::math::Integer<bits> operator>>(const std::size_t other) const noexcept {
			return this->value >> other;
		}

		constexpr xieite::math::Integer<bits> operator>>=(const std::size_t other) noexcept {
			return this->value >>= other;
		}

		friend constexpr std::ostream& operator<<(std::ostream& outStream, const xieite::math::Integer<bits> self) noexcept {
			return outStream << self.value;
		}

		friend constexpr std::istream& operator>>(std::istream& inStream, xieite::math::Integer<bits> self) noexcept {
			return inStream >> self.value;
		}
	};
}
