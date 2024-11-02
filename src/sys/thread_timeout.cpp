module;

#include <xieite/fwd.hpp>

export module xieite:thread_timeout;

import std;
import :is_duration;
import :thread_interval;

export namespace xieite {
	struct thread_timeout {
	public:
		template<std::invocable<> F, xieite::is_duration Duration>
		thread_timeout(F&& callback, Duration duration) noexcept
		: interval([this, &callback] {
			this->stop();
			std::invoke(XIEITE_FWD(callback));
		}, duration) {}

		[[nodiscard]] explicit operator bool() const noexcept {
			return static_cast<bool>(this->interval);
		}

		void stop() noexcept {
			this->interval.stop();
		}

	private:
		xieite::thread_interval interval;
	};
}
