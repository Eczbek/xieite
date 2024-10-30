module;

#include <xieite/arrow.hpp>
#include <xieite/fwd.hpp>

export module xieite:repeat;

import std;

export namespace xieite {
	template<std::integral auto n>
	constexpr auto repeat(auto&& fn, auto&&... args)
	XIEITE_ARROW((
		[&args...]<auto... i>(std::integer_sequence<decltype(n), i...>)
		XIEITE_ARROW((..., fn.template operator()<i>(XIEITE_FWD(args)...)))
	)(std::make_integer_sequence<decltype(n), n>()))

	template<typename... Ts>
	constexpr auto repeat(auto&& fn, auto&&... args)
	XIEITE_ARROW((..., fn.template operator()<Ts>(XIEITE_FWD(args)...)))
}
