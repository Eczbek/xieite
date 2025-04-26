#ifndef DETAIL_XIEITE_HEADER_FN_TIME
#	define DETAIL_XIEITE_HEADER_FN_TIME
#
#	include <chrono>
#	include <concepts>
#	include <functional>
#	include <type_traits>
#	include "../pp/fwd.hpp"
#	include "../sys/stopwatch.hpp"
#	include "../trait/is_clock.hpp"
#	include "../trait/is_duration.hpp"

namespace xieite {
	template<xieite::is_duration Duration = std::chrono::nanoseconds, xieite::is_clock Clock = std::chrono::steady_clock, typename Fn, typename... Args>
	requires(std::invocable<Fn, Args...>)
	[[nodiscard]] Duration time(Fn&& fn, Args&&... args)
	noexcept(std::is_nothrow_invocable_v<Fn, Args...>) {
		xieite::stopwatch<Clock> stopwatch;
		stopwatch.start();
		std::invoke(XIEITE_FWD(fn), XIEITE_FWD(args)...);
		return stopwatch.template total<Duration>();
	}
}

#endif
