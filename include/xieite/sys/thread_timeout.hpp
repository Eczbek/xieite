#ifndef DETAIL_XIEITE_HEADER_SYS_THREAD_TIMEOUT
#	define DETAIL_XIEITE_HEADER_SYS_THREAD_TIMEOUT
#
#	include <concepts>
#	include <functional>
#	include "../pp/fwd.hpp"
#	include "../sys/thread_interval.hpp"
#	include "../trait/is_dur.hpp"

namespace xieite {
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

#endif
