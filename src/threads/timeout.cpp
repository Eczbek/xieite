module;

#include <xieite/forward.hpp>

export module xieite:threads.Timeout;

import std;
import :concepts.Duration;
import :threads.Interval;

export namespace xieite::threads {
	struct Timeout {
	public:
		template<std::invocable<> Functor, xieite::concepts::Duration Duration>
		Timeout(Functor&& callback, const Duration duration) noexcept
		: interval([this, &callback] {
			this->stop();
			std::invoke(XIEITE_FORWARD(callback));
		}, duration) {}

		[[nodiscard]] explicit operator bool() const noexcept {
			return static_cast<bool>(this->interval);
		}

		void stop() noexcept {
			this->interval.stop();
		}

	private:
		xieite::threads::Interval interval;
	};
}
