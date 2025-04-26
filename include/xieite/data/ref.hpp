#ifndef DETAIL_XIEITE_HEADER_DATA_REF
#	define DETAIL_XIEITE_HEADER_DATA_REF
#
#	include <memory>
#	include "../pp/arrow.hpp"
#	include "../pp/fwd.hpp"

namespace xieite {
	template<typename Value>
	struct ref {
		Value& value;

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

		[[nodiscard]] constexpr Value* operator->() const noexcept {
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

		template<typename T>
		[[nodiscard]] explicit constexpr operator T() const
			XIEITE_ARROW_RET(static_cast<T>(this->value))

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

	template<typename Value>
	ref(Value) -> ref<Value>;
}

#endif
