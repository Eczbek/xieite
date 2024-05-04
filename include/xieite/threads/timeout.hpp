#ifndef XIEITE_HEADER_THREADS_TIMEOUT
#	define XIEITE_HEADER_THREADS_TIMEOUT

#	include <concepts>
#	include <utility>
#	include "../concepts/duration.hpp"
#	include "../functors/function.hpp"
#	include "../threads/interval.hpp"

namespace xieite::threads {
	struct Timeout {
	public:
		template<xieite::concepts::Duration Duration_>
		Timeout(const xieite::functors::Function<void()>& callback, const Duration_ duration) noexcept
		: interval([this, &callback] {
			this->stop();
			callback();
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

#endif
