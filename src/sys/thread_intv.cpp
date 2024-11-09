export module xieite:thread_interval;

import std;
import :is_duration;
import :thread_loop;

export namespace xieite {
	struct thread_interval {
	public:
		template<std::invocable<> F, xieite::is_duration Duration>
		thread_interval(F&& fn, Duration duration) noexcept
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
