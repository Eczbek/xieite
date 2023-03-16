#pragma once
#include <concepts> // std::invocable
#include <thread> // std::this_thread::sleep_for
#include <utility> // std::forward
#include <xieite/concepts/TemporalDuration.hpp>
#include <xieite/threads/Loop.hpp>

namespace xieite::threads {
	struct Interval
	: xieite::threads::Loop {
		template<std::invocable<> Invocable>
		Interval(Invocable&& callback, const xieite::concepts::TemporalDuration auto duration) noexcept
		: xieite::threads::Loop([callback = std::forward<Invocable>(callback), duration]() noexcept -> void {
			static bool first = true;
			if (first)
				first = false;
			else
				callback();
			std::this_thread::sleep_for(duration);
		}) {}
	};
}
