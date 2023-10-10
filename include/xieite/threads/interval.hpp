#pragma once

#include <concepts>
#include <functional>
#include <thread>
#include "../concepts/temporal_duration.hpp"
#include "../threads/loop.hpp"

namespace xieite::threads {
	class Interval {
	public:
		template<std::invocable<> Functor, xieite::concepts::TemporalDuration TemporalDuration>
		Interval(const Functor& callback, const TemporalDuration duration) noexcept
		: loop([&callback, duration] {
			static bool first = true;
			if (first) {
				first = false;
			} else {
				std::invoke(callback);
			}
			std::this_thread::sleep_for(duration);
		}) {}

		[[nodiscard]] bool good() const noexcept {
			return this->loop.good();
		}

		void stop() noexcept {
			this->loop.stop();
		}

	private:
		xieite::threads::Loop loop;
	};
}
