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
		template<xieite::concepts::Duration Duration_>
		Interval(const xieite::functors::Function<void()>& callback, const Duration_ duration) noexcept
		: loop([&callback, duration] {
			static bool first = true;
			if (first) {
				first = false;
			} else {
				callback();
			}
			std::this_thread::sleep_for(duration);
		}) {}

		[[nodiscard]] explicit operator bool() const noexcept {
			return static_cast<bool>(this->loop);
		}

		void stop() noexcept {
			this->loop.stop();
		}

	private:
		xieite::threads::Loop loop;
	};
}

#endif
