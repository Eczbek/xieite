module;

#include <xieite/arrow.hpp>
#include <xieite/forward.hpp>

export module xieite:functors.unroll;

import std;

export namespace xieite::functors {
	template<std::integral auto count>
	/* discardable */ constexpr auto unroll(auto&& functor, auto&&... arguments)
	XIEITE_ARROW((
		[&functor, &arguments...]<auto... i>(std::integer_sequence<decltype(count), i...>)
		XIEITE_ARROW(XIEITE_FORWARD(functor).template operator()<i...>(XIEITE_FORWARD(arguments)...))
	)(std::make_integer_sequence<decltype(count), count>()))

	template<typename... Types>
	/* discardable */ constexpr auto unroll(auto&& functor, auto&&... arguments)
	XIEITE_ARROW(xieite::functors::unroll<sizeof...(Types)>(XIEITE_FORWARD(functor), XIEITE_FORWARD(arguments)...))
}
