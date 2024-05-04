#ifndef XIEITE_HEADER_TIME_STOPWATCH
#	define XIEITE_HEADER_TIME_STOPWATCH

#	include <chrono>
#	include <concepts>
#	include <functional>
#	include "../concepts/clock.hpp"
#	include "../concepts/duration.hpp"
#	include "../macros/forward.hpp"

namespace xieite::time {
	template<xieite::concepts::Clock Clock_>
	struct Stopwatch {
	public:
		Stopwatch() noexcept {
			this->reset();
		}

		void start() noexcept {
			this->running = true;
			this->started = Clock_::now();
		}

		void stop() noexcept {
			const std::chrono::time_point<Clock_> ended = Clock_::now();
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

		template<xieite::concepts::Duration Duration_ = std::chrono::nanoseconds>
		Duration_ lap() const noexcept {
			std::chrono::nanoseconds lapDuration = this->lapDuration;
			if (this->running) {
				lapDuration += Clock_::now() - this->started;
			}
			return std::chrono::duration_cast<Duration_>(lapDuration);
		}

		template<xieite::concepts::Duration Duration_ = std::chrono::nanoseconds>
		Duration_ total() const noexcept {
			std::chrono::nanoseconds totalDuration = this->totalDuration;
			if (this->running) {
				totalDuration += Clock_::now() - this->started;
			}
			return std::chrono::duration_cast<Duration_>(totalDuration);
		}

	private:
		bool running;
		std::chrono::time_point<Clock_> started;
		std::chrono::nanoseconds lapDuration;
		std::chrono::nanoseconds totalDuration;
	};
}

#endif
