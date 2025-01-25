#pragma once

#include <concepts>
#include <utility>
#include "../meta/make_seq.hpp"
#include "../meta/seq.hpp"
#include "../pp/arrow.hpp"
#include "../pp/fwd.hpp"

namespace xieite {
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
