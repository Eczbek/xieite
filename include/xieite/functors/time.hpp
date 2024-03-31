#ifndef XIEITE_HEADER_FUNCTORS_TIME
#	define XIEITE_HEADER_FUNCTORS_TIME

#	include <chrono>
#	include <concepts>
#	include <functional>
#	include "../concepts/clock.hpp"
#	include "../concepts/duration.hpp"
#	include "../concepts/no_throw_invocable.hpp"
#	include "../macros/forward.hpp"
#	include "../time/stopwatch.hpp"

namespace xieite::functors {
	template<xieite::concepts::Duration Duration = std::chrono::nanoseconds, xieite::concepts::Clock Clock = std::chrono::steady_clock, typename... Arguments, std::invocable<Arguments...> Functor>
	Duration time(Functor&& functor, Arguments&&... arguments)
	noexcept(xieite::concepts::NoThrowInvocable<Functor, Arguments...>) {
		xieite::time::Stopwatch<Clock> stopwatch;
		stopwatch.start();
		static_cast<void>(std::invoke(XIEITE_FORWARD(functor), XIEITE_FORWARD(arguments)...));
		return stopwatch.template total<Duration>();
	}
}

#endif
