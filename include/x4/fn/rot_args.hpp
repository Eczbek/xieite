#pragma once

#include <cstddef>
#include <functional>
#include "../fn/unroll.hpp"
#include "../pp/ar.hpp"
#include "../pp/fwd.hpp"
#include "../pp/lift.hpp"

namespace x4 {
	template<std::size_t n, typename F, typename... Args>
	[[nodiscard]] constexpr auto rot_args(F&& fn, Args&&... args)
		X4AR(x4::unroll<Args...>(
			[]<std::size_t... i>(F&& fn, Args&&... args) static
				X4AR(std::invoke(X4FWD(fn), X4FWD(args...[(i + n % sizeof...(Args)) % sizeof...(Args)])...)),
			X4FWD(fn),
			X4FWD(args)...
		))

	template<std::size_t n, typename T, typename... Args>
	[[nodiscard]] constexpr T rot_args(Args&&... args)
		X4ARRET(x4::rot_args<n>(X4LIFT(T), X4FWD(args)...))
}
