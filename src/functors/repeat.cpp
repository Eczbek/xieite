module;

#include <xieite/arrow.hpp>
#include <xieite/forward.hpp>

export module xieite:functors.repeat;

import std;

export namespace xieite::functors {
	template<std::integral auto count>
	constexpr auto repeat(auto&& functor, auto&&... arguments)
	XIEITE_ARROW(([&arguments...]<auto... i>(std::integer_sequence<decltype(count), i...>) XIEITE_ARROW((..., functor.template operator()<i>(XIEITE_FORWARD(arguments)...)))))

	template<typename... Types>
	constexpr auto repeat(auto&& functor, auto&&... arguments)
	XIEITE_ARROW((..., functor.template operator()<Types>(XIEITE_FORWARD(arguments)...)))
}
