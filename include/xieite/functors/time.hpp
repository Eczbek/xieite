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
	template<xieite::concepts::Duration Duration_ = std::chrono::nanoseconds, xieite::concepts::Clock Clock_ = std::chrono::steady_clock, typename... Arguments_, std::invocable<Arguments_...> Functor_>
	Duration_ time(Functor_&& functor, Arguments_&&... arguments)
	noexcept(xieite::concepts::NoThrowInvocable<Functor_, Arguments_...>) {
		xieite::time::Stopwatch<Clock_> stopwatch;
		stopwatch.start();
		static_cast<void>(std::invoke(XIEITE_FORWARD(functor), XIEITE_FORWARD(arguments)...));
		return stopwatch.template total<Duration_>();
	}
}

#endif
