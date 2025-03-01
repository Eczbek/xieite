#pragma once

#include <chrono>
#include <concepts>
#include <functional>
#include <type_traits>
#include "../pp/fwd.hpp"
#include "../sys/stopwatch.hpp"
#include "../trait/isclock.hpp"
#include "../trait/isdur.hpp"

namespace x4 {
	template<x4::isdur Dur = std::chrono::nanoseconds, x4::isclock Clock = std::chrono::steady_clock, typename F, typename... Args>
	requires(std::invocable<F, Args...>)
	[[nodiscard]] Dur time(F&& fn, Args&&... args)
	noexcept(std::is_nothrow_invocable_v<F, Args...>) {
		x4::stopwatch<Clock> stopwatch;
		stopwatch.start();
		std::invoke(X4FWD(fn), X4FWD(args)...);
		return stopwatch.template total<Dur>();
	}
}
