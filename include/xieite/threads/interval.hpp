#ifndef XIEITE_HEADER_THREADS_INTERVAL
#	define XIEITE_HEADER_THREADS_INTERVAL

#	include <concepts>
#	include <thread>
#	include "../concepts/duration.hpp"
#	include "../functors/function.hpp"
#	include "../threads/loop.hpp"

namespace xieite::threads {
	struct Interval {
	public:
		template<xieite::concepts::Duration Duration>
		Interval(const xieite::functors::Function<void()>& callback, const Duration duration) noexcept
		: loop([&callback, duration] -> void {
			static bool first = true;
			if (first) {
				first = false;
			} else {
				callback();
			}
			std::this_thread::sleep_for(duration);
		}) {}

		[[nodiscard]] operator bool() const noexcept {
			return this->loop;
		}

		void stop() noexcept {
			this->loop.stop();
		}

	private:
		xieite::threads::Loop loop;
	};
}

#endif
