module;

#include <xieite/fwd.hpp>

export module xieite:thread_timeout;

import std;
import :is_dur;
import :thread_intv;

export namespace xieite {
	struct thread_timeout {
	public:
		template<std::invocable<> F, xieite::is_dur Dur>
		thread_timeout(F&& callback, Dur dur) noexcept
		: intv([this, &callback] -> void {
			this->stop();
			std::invoke(XIEITE_FWD(callback));
		}, dur) {}

		[[nodiscard]] explicit operator bool() const noexcept {
			return static_cast<bool>(this->intv);
		}

		void stop() noexcept {
			this->intv.stop();
		}

	private:
		xieite::thread_intv intv;
	};
}
