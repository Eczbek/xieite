module;

#include <xieite/arrow.hpp>
#include <xieite/fwd.hpp>
#include <xieite/lift.hpp>

export module xieite:rot_args;

import std;
import :unroll;

export namespace xieite {
	template<std::size_t n, typename F, typename... Args>
	constexpr auto rot_args(F&& fn, Args&&... args)
		XIEITE_ARROW(xieite::unroll<Args...>(
			[]<std::size_t... i>(F&& fn, Args&&... args)
				XIEITE_ARROW(std::invoke(XIEITE_FWD(fn), XIEITE_FWD(args...[(i + n % sizeof...(Args)) % sizeof...(Args)])...)),
			XIEITE_FWD(fn),
			XIEITE_FWD(args)...
		))

	template<std::size_t n, typename T, typename... Args>
	[[nodiscard]] constexpr T rot_args(Args&&... args)
		XIEITE_ARROW_RET(xieite::rot_args<n>(XIEITE_LIFT(T), XIEITE_FWD(args)...))
}

// NOTE: The `std::move` is necessary
// NOTE: What std::move? 2024-12-05
