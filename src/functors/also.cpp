module;

#include <xieite/arrow.hpp>
#include <xieite/forward.hpp>

export module xieite:functors.also;

import std;
import :concepts.CopyConstructible;

export namespace xieite::functors {
	template<xieite::concepts::CopyConstructible Type, std::invocable<Type&&> Functor>
	[[nodiscard]] constexpr Type also(Type&& value, Functor&& functor)
	noexcept(std::is_nothrow_copy_constructible_v<Type> && std::is_nothrow_invocable_v<Functor, Type&&>) {
		const Type copy = value;
		std::invoke(XIEITE_FORWARD(functor), value);
		return copy;
	}

	template<xieite::concepts::CopyConstructible Type, std::invocable<> Functor>
	[[nodiscard]] constexpr auto also(Type&& value, Functor&& functor)
	XIEITE_ARROW(xieite::functors::also(
		XIEITE_FORWARD(value),
		[&functor](auto&&) {
			std::invoke(XIEITE_FORWARD(functor));
		}
	))
}
