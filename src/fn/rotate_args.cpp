module;

#include <xieite/arrow.hpp>
#include <xieite/fwd.hpp>

export module xieite:rotate_args;

import std;
import :unroll;

export namespace xieite {
	template<std::size_t n, typename F, typename... Args>
	constexpr auto rotate_args(F&& fn, Args&&... args)
	XIEITE_ARROW(xieite::unroll<Args...>(
		[&fn, args_tuple = std::forward_as_tuple(XIEITE_FWD(args)...)]<std::size_t... i>
		XIEITE_ARROW(std::invoke(
			XIEITE_FWD(fn),
			std::get<(i + n % sizeof...(Args)) % sizeof...(Args)>(std::move(args_tuple))...
		))
	))
}

// Note: the `std::move` is necessary
