module;

#include <xieite/fwd.hpp>

export module xieite:thread_timeout;

import std;
import :is_dur;
import :thread_interval;

export namespace xieite {
	struct thread_timeout {
	public:
		template<std::invocable<> F, xieite::is_dur Dur>
		[[nodiscard]] thread_timeout(F&& callback, Dur dur) noexcept
		: interval([this, &callback] -> void {
			this->stop();
			std::invoke(XIEITE_FWD(callback));
		}, dur) {}

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
