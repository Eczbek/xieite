#ifndef XIEITE_HEADER_THREADS_INTERVAL
#	define XIEITE_HEADER_THREADS_INTERVAL

#	include <concepts>
#	include <functional>
#	include <thread>
#	include "../concepts/duration.hpp"
#	include "../threads/loop.hpp"

namespace xieite::threads {
	struct Interval {
	public:
		template<std::invocable<> Functor, xieite::concepts::Duration Duration>
		Interval(Functor&& callback, const Duration duration) noexcept
		: loop([&callback, duration] -> void {
			static bool first = true;
			if (first) {
				first = false;
			} else {
				std::invoke(callback);
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
