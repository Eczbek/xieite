#pragma once

#include <memory>
#include "../pp/ar.hpp"
#include "../pp/fwd.hpp"

namespace x4 {
	template<typename T>
	struct ref {
		T& value;

		constexpr auto operator++(int) const
			X4AR(this->value++)

		constexpr auto operator--(int) const
			X4AR(this->value--)

		template<typename... Args>
		[[nodiscard]] constexpr auto operator()(Args&&... args)
			X4AR(this->value(X4FWD(args)...))

		template<typename... Args>
		[[nodiscard]] constexpr auto operator[](Args&&... args)
			X4AR(this->value[X4FWD(args)...])

		[[nodiscard]] constexpr T* operator->() const noexcept {
			return std::addressof(this->value);
		}

		constexpr auto operator++() const
			X4AR(++this->value)

		constexpr auto operator--() const
			X4AR(--this->value)

		[[nodiscard]] constexpr auto operator+() const
			X4AR(+this->value)

		[[nodiscard]] constexpr auto operator-() const
			X4AR(-this->value)

		[[nodiscard]] constexpr auto operator!() const
			X4AR(!this->value)

		[[nodiscard]] constexpr auto operator~() const
			X4AR(~this->value)

		template<typename U>
		[[nodiscard]] explicit constexpr operator U() const
			X4ARRET(static_cast<U>(this->value))

		[[nodiscard]] constexpr auto operator*() const
			X4AR(*this->value)

		[[nodiscard]] constexpr auto operator&() const
			X4AR(&this->value)

		[[nodiscard]] constexpr auto operator->*(auto&& x) const
			X4AR(this->value->*X4FWD(x))

		[[nodiscard]] constexpr auto operator*(auto&& x) const
			X4AR(this->value * X4FWD(x))

		[[nodiscard]] constexpr auto operator/(auto&& x) const
			X4AR(this->value / X4FWD(x))

		[[nodiscard]] constexpr auto operator%(auto&& x) const
			X4AR(this->value % X4FWD(x))

		[[nodiscard]] constexpr auto operator+(auto&& x) const
			X4AR(this->value + X4FWD(x))

		[[nodiscard]] constexpr auto operator-(auto&& x) const
			X4AR(this->value - X4FWD(x))

		[[nodiscard]] constexpr auto operator<<(auto&& x) const
			X4AR(this->value << X4FWD(x))

		[[nodiscard]] constexpr auto operator>>(auto&& x) const
			X4AR(this->value >> X4FWD(x))

		[[nodiscard]] constexpr auto operator<=>(auto&& x) const
			X4AR(this->value <=> X4FWD(x))

		[[nodiscard]] constexpr auto operator==(auto&& x) const
			X4AR(this->value == X4FWD(x))

		[[nodiscard]] constexpr auto operator&(auto&& x) const
			X4AR(this->value & X4FWD(x))

		[[nodiscard]] constexpr auto operator^(auto&& x) const
			X4AR(this->value ^ X4FWD(x))

		[[nodiscard]] constexpr auto operator|(auto&& x) const
			X4AR(this->value | X4FWD(x))

		[[nodiscard]] constexpr auto operator&&(auto&& x) const
			X4AR(this->value && X4FWD(x))

		[[nodiscard]] constexpr auto operator||(auto&& x) const
			X4AR(this->value || X4FWD(x))

		constexpr auto operator=(auto&& x)
			X4AR(this->value = X4FWD(x))

		constexpr auto operator*=(auto&& x)
			X4AR(this->value *= X4FWD(x))

		constexpr auto operator/=(auto&& x)
			X4AR(this->value /= X4FWD(x))

		constexpr auto operator%=(auto&& x)
			X4AR(this->value %= X4FWD(x))

		constexpr auto operator+=(auto&& x)
			X4AR(this->value += X4FWD(x))

		constexpr auto operator-=(auto&& x)
			X4AR(this->value -= X4FWD(x))

		constexpr auto operator<<=(auto&& x)
			X4AR(this->value <<= X4FWD(x))

		constexpr auto operator>>=(auto&& x)
			X4AR(this->value >>= X4FWD(x))

		constexpr auto operator&=(auto&& x)
			X4AR(this->value &= X4FWD(x))

		constexpr auto operator^=(auto&& x)
			X4AR(this->value ^= X4FWD(x))

		constexpr auto operator|=(auto&& x)
			X4AR(this->value |= X4FWD(x))

		[[nodiscard]] constexpr auto operator,(auto&& x)
			X4AR(this->value, X4FWD(x))
	};

	template<typename T>
	ref(T) -> ref<T>;
}
