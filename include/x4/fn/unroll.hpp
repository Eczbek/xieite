#pragma once

#include <concepts>
#include "../meta/mkseq.hpp"
#include "../meta/seq.hpp"
#include "../pp/ar.hpp"
#include "../pp/fwd.hpp"

namespace x4 {
	template<std::integral auto n>
	[[nodiscard]] constexpr auto unroll(auto&& fn, auto&&... args)
		X4AR((
			[]<auto... i>(x4::seq<i...>, auto&& fn, auto&&... args) static
				X4AR(X4FWD(fn).template operator()<i...>(X4FWD(args)...))
		)(x4::mkseq<n>, X4FWD(fn), X4FWD(args)...))

	template<typename... Ts>
	[[nodiscard]] constexpr auto unroll(auto&& fn, auto&&... args)
		X4AR(x4::unroll<sizeof...(Ts)>(X4FWD(fn), X4FWD(args)...))
}
