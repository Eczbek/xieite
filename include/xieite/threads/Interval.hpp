#pragma once

#include <concepts>
#include <utility>
#include <xieite/concepts/TemporalDuration.hpp>
#include <xieite/threads/Loop.hpp>

namespace xieite::threads {
	class Interval {
	private:
		xieite::threads::Loop loop;

	public:
		template<std::invocable<> Invocable>
		Interval(Invocable&& callback, const xieite::concepts::TemporalDuration auto duration) noexcept
		: loop([callback = std::forward<Invocable>(callback), duration]() noexcept -> void {
			static bool first = true;
			if (first)
				first = false;
			else
				callback();
			std::this_thread::sleep_for(duration);
		}) {}

		bool good() const noexcept {
			return this->loop.good();
		}

		void stop() noexcept {
			this->loop.stop();
		}
	};
}
