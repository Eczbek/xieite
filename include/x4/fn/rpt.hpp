#pragma once

#include <concepts>
#include "../meta/mkseq.hpp"
#include "../meta/seq.hpp"
#include "../pp/ar.hpp"
#include "../pp/fwd.hpp"

namespace x4 {
	template<std::integral auto n>
	constexpr void rpt(auto&& fn, auto&&... args)
		X4ARRET((
			[]<auto... i>(x4::seq<i...>, auto&& fn, auto&&... args) static
				X4AR((..., fn.template operator()<i>(args...)))
		)(x4::mkseq<n>, X4FWD(fn), X4FWD(args)...))

	template<typename... Ts>
	constexpr void rpt(auto&& fn, auto&&... args)
		X4ARRET(x4::rpt<sizeof...(Ts)>(X4FWD(fn), X4FWD(args)...))
}
