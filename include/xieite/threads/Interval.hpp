#pragma once
#include <concepts> // std::invocable
#include <thread> // std::this_thread::sleep_for
#include <utility> // std::forward
#include <xieite/concepts/TemporalDuration.hpp>
#include <xieite/threads/Loop.hpp>

namespace xieite::threads {
	struct Interval
	: xieite::threads::Loop {
		template<std::invocable<> C, xieite::concepts::TemporalDuration D>
		Interval(C&& callback, const D duration) noexcept
		: xieite::threads::Loop([callback = std::forward<C>(callback), duration]() -> void {
			static bool first = true;
			if (first)
				first = false;
			else
				callback();
			std::this_thread::sleep_for(duration);
		}) {}
	};
}
