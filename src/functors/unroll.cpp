module;

#include <xieite/arrow.hpp>
#include <xieite/forward.hpp>

export module xieite:functors.unroll;

import std;

export namespace xieite::functors {
	template<std::integral auto count>
	/* discardable */ constexpr auto unroll(auto&& lambda)
	XIEITE_ARROW(([&lambda]<auto... i>(std::integer_sequence<decltype(count), i...>) XIEITE_ARROW(XIEITE_FORWARD(lambda).template operator()<i...>()))(std::make_integer_sequence<decltype(count), count>()))

	template<typename... Types>
	/* discardable */ constexpr auto unroll(auto&& lambda)
	XIEITE_ARROW(xieite::functors::unroll<sizeof...(Types)>(XIEITE_FORWARD(lambda)))

	template<auto... values>
	/* discardable */ constexpr auto unroll(auto&& lambda)
	XIEITE_ARROW(xieite::functors::unroll<sizeof...(values)>(XIEITE_FORWARD(lambda)))
}
