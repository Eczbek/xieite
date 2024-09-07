module;

#include <xieite/forward.hpp>

export module xieite:time.Stopwatch;

import std;
import :concepts.Clock;
import :concepts.Duration;

export namespace xieite::time {
	template<xieite::concepts::Clock Clock>
	struct Stopwatch {
	public:
		Stopwatch() noexcept {
			this->reset();
		}

		void start() noexcept {
			this->running = true;
			this->started = Clock::now();
		}

		void stop() noexcept {
			const std::chrono::time_point<Clock> ended = Clock::now();
			if (this->running) {
				this->lapDuration = std::chrono::nanoseconds(0);
				this->totalDuration += ended - this->started;
			}
			this->running = false;
		}

		void reset() noexcept {
			this->running = false;
			this->totalDuration = std::chrono::nanoseconds(0);
			this->lapDuration = std::chrono::nanoseconds(0);
		}

		template<xieite::concepts::Duration Duration = std::chrono::nanoseconds>
		Duration lap() const noexcept {
			std::chrono::nanoseconds lapDuration = this->lapDuration;
			if (this->running) {
				lapDuration += Clock::now() - this->started;
			}
			return std::chrono::duration_cast<Duration>(lapDuration);
		}

		template<xieite::concepts::Duration Duration = std::chrono::nanoseconds>
		Duration total() const noexcept {
			std::chrono::nanoseconds totalDuration = this->totalDuration;
			if (this->running) {
				totalDuration += Clock::now() - this->started;
			}
			return std::chrono::duration_cast<Duration>(totalDuration);
		}

	private:
		bool running;
		std::chrono::time_point<Clock> started;
		std::chrono::nanoseconds lapDuration;
		std::chrono::nanoseconds totalDuration;
	};
}
