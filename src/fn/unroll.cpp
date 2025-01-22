module;

#include <xieite/arrow.hpp>
#include <xieite/fwd.hpp>

export module xieite:unroll;

import std;
import :make_seq;
import :seq;

export namespace xieite {
	template<std::integral auto n>
	constexpr auto unroll(auto&& fn, auto&&... args)
		XIEITE_ARROW((
			[]<auto... i>(xieite::seq<i...>, auto&& fn, auto&&... args)
				XIEITE_ARROW(XIEITE_FWD(fn).template operator()<i...>(XIEITE_FWD(args)...))
		)(xieite::make_seq<n>, XIEITE_FWD(fn), XIEITE_FWD(args)...))

	template<typename... Ts>
	constexpr auto unroll(auto&& fn, auto&&... args)
		XIEITE_ARROW(xieite::unroll<sizeof...(Ts)>(XIEITE_FWD(fn), XIEITE_FWD(args)...))
}
