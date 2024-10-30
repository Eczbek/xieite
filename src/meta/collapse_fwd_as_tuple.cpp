module;

#include <xieite/fwd.hpp>

export module xieite:collapse_fwd_as_tuple;

import :collapse_fwd;
import :decay_as_tuple;

export namespace xieite {
	template<typename T>
	[[nodiscard]] constexpr auto collapse_fwd_as_tuple(auto&&... args)
	XIEITE_ARROW(xieite::decay_as_tuple(xieite::collapse_fwd<T>(XIEITE_FWD(args))...))
}
