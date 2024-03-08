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
		template<xieite::concepts::Duration Duration>
		Timeout(const xieite::functors::Function<void()>& callback, const Duration duration) noexcept
		: interval([this, &callback] -> void {
			this->stop();
			callback();
		}, duration) {}

		[[nodiscard]] operator bool() const noexcept {
			return this->interval;
		}

		void stop() noexcept {
			this->interval.stop();
		}

	private:
		xieite::threads::Interval interval;
	};
}

#endif
