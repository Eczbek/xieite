#ifndef XIEITE_HEADER_FUNCTORS_TIME
#	define XIEITE_HEADER_FUNCTORS_TIME

#	include <chrono>
#	include <concepts>
#	include <functional>
#	include "../concepts/clock.hpp"
#	include "../concepts/duration.hpp"
#	include "../concepts/no_throw_invocable.hpp"
#	include "../time/stopwatch.hpp"

namespace xieite::functors {
	template<xieite::concepts::Duration Duration = std::chrono::nanoseconds, xieite::concepts::Clock Clock = std::chrono::steady_clock, std::invocable<> Functor>
	Duration time(Functor&& functor)
	noexcept(xieite::concepts::NoThrowInvocable<Functor>) {
		xieite::time::Stopwatch<Clock> stopwatch;
		stopwatch.start();
		std::invoke(XIEITE_FORWARD(functor));
		return stopwatch.template total<Duration>();
	}
}

#endif
