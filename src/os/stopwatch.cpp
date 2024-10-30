module;

#include <xieite/fwd.hpp>

export module xieite:stopwatch;

import std;
import :is_clock;
import :is_duration;

export namespace xieite {
	template<xieite::is_clock Clock>
	struct stopwatch {
	public:
		stopwatch() noexcept {
			this->reset();
		}

		void start() noexcept {
			this->running = true;
			this->started = Clock::now();
		}

		void stop() noexcept {
			const std::chrono::time_point<Clock> ended = Clock::now();
			if (this->running) {
				this->lap_duration = std::chrono::nanoseconds(0);
				this->total_duration += ended - this->started;
			}
			this->running = false;
		}

		void reset() noexcept {
			this->running = false;
			this->total_duration = std::chrono::nanoseconds(0);
			this->lap_duration = std::chrono::nanoseconds(0);
		}

		template<xieite::is_duration T = std::chrono::nanoseconds>
		T lap() const noexcept {
			std::chrono::nanoseconds lap_duration = this->lap_duration;
			if (this->running) {
				lap_duration += Clock::now() - this->started;
			}
			return std::chrono::duration_cast<T>(lap_duration);
		}

		template<xieite::is_duration T = std::chrono::nanoseconds>
		T total() const noexcept {
			std::chrono::nanoseconds total_duration = this->total_duration;
			if (this->running) {
				total_duration += Clock::now() - this->started;
			}
			return std::chrono::duration_cast<T>(total_duration);
		}

	private:
		bool running;
		std::chrono::time_point<Clock> started;
		std::chrono::nanoseconds lap_duration;
		std::chrono::nanoseconds total_duration;
	};
}
