#pragma once

#include <compare>
#include <functional>
#include <memory>
#include "../pp/arrow.hpp"
#include "../pp/fwd.hpp"
#include "../trait/is_conv_from.hpp"
#include "../trait/is_noex_conv.hpp"

namespace xieite {
	template<typename T>
	struct ref {
		T& value;

		constexpr auto operator++(int) const
			XIEITE_ARROW(this->value++)

		constexpr auto operator--(int) const
			XIEITE_ARROW(this->value--)

		template<typename... Args>
		[[nodiscard]] constexpr auto operator()(Args&&... args)
			XIEITE_ARROW(this->value(XIEITE_FWD(args)...))

		template<typename... Args>
		[[nodiscard]] constexpr auto operator[](Args&&... args)
			XIEITE_ARROW(this->value[XIEITE_FWD(args)...])

		[[nodiscard]] constexpr T* operator->() const noexcept {
			return std::addressof(this->value);
		}

		constexpr auto operator++() const
			XIEITE_ARROW(++this->value)

		constexpr auto operator--() const
			XIEITE_ARROW(--this->value)

		[[nodiscard]] constexpr auto operator+() const
			XIEITE_ARROW(+this->value)

		[[nodiscard]] constexpr auto operator-() const
			XIEITE_ARROW(-this->value)

		[[nodiscard]] constexpr auto operator!() const
			XIEITE_ARROW(!this->value)

		[[nodiscard]] constexpr auto operator~() const
			XIEITE_ARROW(~this->value)

		template<typename U>
		[[nodiscard]] explicit constexpr operator U() const
			XIEITE_ARROW_RET(static_cast<U>(this->value))

		[[nodiscard]] constexpr auto operator*() const
			XIEITE_ARROW(*this->value)

		[[nodiscard]] constexpr auto operator&() const
			XIEITE_ARROW(&this->value)

		[[nodiscard]] constexpr auto operator->*(auto&& x) const
			XIEITE_ARROW(this->value->*XIEITE_FWD(x))

		[[nodiscard]] constexpr auto operator*(auto&& x) const
			XIEITE_ARROW(this->value * XIEITE_FWD(x))

		[[nodiscard]] constexpr auto operator/(auto&& x) const
			XIEITE_ARROW(this->value / XIEITE_FWD(x))

		[[nodiscard]] constexpr auto operator%(auto&& x) const
			XIEITE_ARROW(this->value % XIEITE_FWD(x))

		[[nodiscard]] constexpr auto operator+(auto&& x) const
			XIEITE_ARROW(this->value + XIEITE_FWD(x))

		[[nodiscard]] constexpr auto operator-(auto&& x) const
			XIEITE_ARROW(this->value - XIEITE_FWD(x))

		[[nodiscard]] constexpr auto operator<<(auto&& x) const
			XIEITE_ARROW(this->value << XIEITE_FWD(x))

		[[nodiscard]] constexpr auto operator>>(auto&& x) const
			XIEITE_ARROW(this->value >> XIEITE_FWD(x))

		[[nodiscard]] constexpr auto operator<=>(auto&& x) const
			XIEITE_ARROW(this->value <=> XIEITE_FWD(x))

		[[nodiscard]] constexpr auto operator==(auto&& x) const
			XIEITE_ARROW(this->value == XIEITE_FWD(x))

		[[nodiscard]] constexpr auto operator&(auto&& x) const
			XIEITE_ARROW(this->value & XIEITE_FWD(x))

		[[nodiscard]] constexpr auto operator^(auto&& x) const
			XIEITE_ARROW(this->value ^ XIEITE_FWD(x))

		[[nodiscard]] constexpr auto operator|(auto&& x) const
			XIEITE_ARROW(this->value | XIEITE_FWD(x))

		[[nodiscard]] constexpr auto operator&&(auto&& x) const
			XIEITE_ARROW(this->value && XIEITE_FWD(x))

		[[nodiscard]] constexpr auto operator||(auto&& x) const
			XIEITE_ARROW(this->value || XIEITE_FWD(x))

		constexpr auto operator=(auto&& x)
			XIEITE_ARROW(this->value = XIEITE_FWD(x))

		constexpr auto operator*=(auto&& x)
			XIEITE_ARROW(this->value *= XIEITE_FWD(x))

		constexpr auto operator/=(auto&& x)
			XIEITE_ARROW(this->value /= XIEITE_FWD(x))

		constexpr auto operator%=(auto&& x)
			XIEITE_ARROW(this->value %= XIEITE_FWD(x))

		constexpr auto operator+=(auto&& x)
			XIEITE_ARROW(this->value += XIEITE_FWD(x))

		constexpr auto operator-=(auto&& x)
			XIEITE_ARROW(this->value -= XIEITE_FWD(x))

		constexpr auto operator<<=(auto&& x)
			XIEITE_ARROW(this->value <<= XIEITE_FWD(x))

		constexpr auto operator>>=(auto&& x)
			XIEITE_ARROW(this->value >>= XIEITE_FWD(x))

		constexpr auto operator&=(auto&& x)
			XIEITE_ARROW(this->value &= XIEITE_FWD(x))

		constexpr auto operator^=(auto&& x)
			XIEITE_ARROW(this->value ^= XIEITE_FWD(x))

		constexpr auto operator|=(auto&& x)
			XIEITE_ARROW(this->value |= XIEITE_FWD(x))

		[[nodiscard]] constexpr auto operator,(auto&& x)
			XIEITE_ARROW(this->value, XIEITE_FWD(x))
	};

	template<typename T>
	ref(T) -> ref<T>;
}
