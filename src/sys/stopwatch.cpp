module;

#include <xieite/fwd.hpp>

export module xieite:stopwatch;

import std;
import :is_clock;
import :is_dur;

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
				this->lap_dur = std::chrono::nanoseconds(0);
				this->total_dur += ended - this->started;
			}
			this->running = false;
		}

		void reset() noexcept {
			this->running = false;
			this->total_dur = std::chrono::nanoseconds(0);
			this->lap_dur = std::chrono::nanoseconds(0);
		}

		template<xieite::is_dur T = std::chrono::nanoseconds>
		T lap() const noexcept {
			std::chrono::nanoseconds lap_dur = this->lap_dur;
			if (this->running) {
				lap_dur += Clock::now() - this->started;
			}
			return std::chrono::duration_cast<T>(lap_dur);
		}

		template<xieite::is_dur T = std::chrono::nanoseconds>
		T total() const noexcept {
			std::chrono::nanoseconds total_dur = this->total_dur;
			if (this->running) {
				total_dur += Clock::now() - this->started;
			}
			return std::chrono::duration_cast<T>(total_dur);
		}

	private:
		bool running;
		std::chrono::time_point<Clock> started;
		std::chrono::nanoseconds lap_dur;
		std::chrono::nanoseconds total_dur;
	};
}
