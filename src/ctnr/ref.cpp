module;

#include <xieite/arrow.hpp>
#include <xieite/fwd.hpp>

export module xieite:ref;

import std;
import :is_conv_from;
import :is_noex_conv;

export namespace xieite {
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
		[[nodiscard]] constexpr operator U() const
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

		[[nodiscard]] constexpr T&& get() const noexcept {
			return this->value;
		}
	};

	template<typename T>
	ref(T) -> ref<T>;
}
