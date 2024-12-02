module;

#include <xieite/arrow.hpp>
#include <xieite/fwd.hpp>

export module xieite:rot_args;

import std;
import :unroll;

export namespace xieite {
	template<std::size_t n, typename F, typename... Args>
	constexpr auto rot_args(F&& fn, Args&&... args)
	XIEITE_ARROW(xieite::unroll<Args...>(
		[&fn, &args...]<std::size_t... i>
		XIEITE_ARROW(std::invoke(
			XIEITE_FWD(fn),
			XIEITE_FWD(args...[(i + n % sizeof...(Args)) % sizeof...(Args)])...
		))
	))
}

// Note: the `std::move` is necessary
