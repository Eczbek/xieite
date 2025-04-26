#ifndef DETAIL_XIEITE_HEADER_SYS_THREAD_TIMEOUT
#	define DETAIL_XIEITE_HEADER_SYS_THREAD_TIMEOUT
#
#	include <concepts>
#	include <functional>
#	include "../pp/fwd.hpp"
#	include "../sys/thread_interval.hpp"
#	include "../trait/is_duration.hpp"

namespace xieite {
	struct thread_timeout {
	public:
		[[nodiscard]] thread_timeout(std::invocable<> auto&& callback, xieite::is_duration auto duration) noexcept
		: interval([this, &callback] -> void {
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

#endif
