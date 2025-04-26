#ifndef DETAIL_XIEITE_HEADER_SYS_THREAD_INTERVAL
#	define DETAIL_XIEITE_HEADER_SYS_THREAD_INTERVAL
#
#	include <concepts>
#	include <functional>
#	include <thread>
#	include "../sys/thread_loop.hpp"
#	include "../trait/is_duration.hpp"

namespace xieite {
	struct thread_interval {
	public:
		[[nodiscard]] thread_interval(std::invocable<> auto&& fn, xieite::is_duration auto duration) noexcept
		: loop([&fn, duration] -> void {
			static bool first = true;
			if (first) {
				first = false;
			} else {
				std::invoke(fn);
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
		xieite::thread_loop loop;
	};
}

#endif
