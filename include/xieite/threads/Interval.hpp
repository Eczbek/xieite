#ifndef XIEITE_HEADER_THREADS_INTERVAL
#	define XIEITE_HEADER_THREADS_INTERVAL

#	include <concepts>
#	include <thread>
#	include "../concepts/TemporalDuration.hpp"
#	include "../threads/Loop.hpp"

namespace xieite::threads {
	class Interval {
	public:
		template<std::invocable<> Invocable, xieite::concepts::TemporalDuration TemporalDuration>
		Interval(const Invocable& callback, const TemporalDuration duration) noexcept
		: loop([&callback, duration] {
			static bool first = true;
			if (first) {
				first = false;
			} else {
				callback();
			}
			std::this_thread::sleep_for(duration);
		}) {}

		bool good() const noexcept {
			return this->loop.good();
		}

		void stop() noexcept {
			this->loop.stop();
		}

	private:
		xieite::threads::Loop loop;
	};
}

#endif
