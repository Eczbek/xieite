#pragma once

#include <cstddef>
#include <functional>
#include "../fn/unroll.hpp"
#include "../pp/arrow.hpp"
#include "../pp/fwd.hpp"
#include "../pp/lift.hpp"

namespace xieite {
	template<std::size_t n, typename F, typename... Args>
	[[nodiscard]] constexpr auto rot_args(F&& fn, Args&&... args)
		XIEITE_ARROW(xieite::unroll<Args...>(
			[]<std::size_t... i>(F&& fn, Args&&... args) static
				XIEITE_ARROW(std::invoke(XIEITE_FWD(fn), XIEITE_FWD(args...[(i + n % sizeof...(Args)) % sizeof...(Args)])...)),
			XIEITE_FWD(fn),
			XIEITE_FWD(args)...
		))

	template<std::size_t n, typename T, typename... Args>
	[[nodiscard]] constexpr T rot_args(Args&&... args)
		XIEITE_ARROW_RET(xieite::rot_args<n>(XIEITE_LIFT(T), XIEITE_FWD(args)...))
}
