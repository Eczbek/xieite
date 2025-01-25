#pragma once

#include <chrono>
#include <concepts>
#include <functional>
#include <type_traits>
#include "../pp/fwd.hpp"
#include "../sys/stopwatch.hpp"
#include "../trait/is_clock.hpp"
#include "../trait/is_dur.hpp"

namespace xieite {
	template<xieite::is_dur Dur = std::chrono::nanoseconds, xieite::is_clock Clock = std::chrono::steady_clock, typename F, typename... Args>
	requires(std::invocable<F, Args...>)
	[[nodiscard]] Dur time(F&& fn, Args&&... args)
	noexcept(std::is_nothrow_invocable_v<F, Args...>) {
		xieite::stopwatch<Clock> stopwatch;
		stopwatch.start();
		std::invoke(XIEITE_FWD(fn), XIEITE_FWD(args)...);
		return stopwatch.template total<Dur>();
	}
}
