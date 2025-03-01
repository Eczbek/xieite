#pragma once

#include <tuple>
#include "../meta/rvstup.hpp"
#include "../pp/ar.hpp"
#include "../pp/fwd.hpp"
#include "../pp/lift.hpp"

namespace x4 {
	template<typename F, typename... Args>
	[[nodiscard]] constexpr auto rvsargs(F&& fn, Args&&... args)
		X4AR(std::apply(X4FWD(fn), x4::rvstup(std::forward_as_tuple(X4FWD(args)...))))

	template<typename T, typename... Args>
	[[nodiscard]] constexpr T rvsargs(Args&&... args)
		X4ARRET(x4::rvsargs(X4LIFT(T), X4FWD(args)...))
}
