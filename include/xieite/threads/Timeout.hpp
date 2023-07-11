#ifndef XIEITE_HEADER_THREADS_TIMEOUT
#	define XIEITE_HEADER_THREADS_TIMEOUT

#	include <concepts>
#	include <xieite/concepts/TemporalDuration.hpp>
#	include <xieite/threads/Interval.hpp>

namespace xieite::threads {
	class Timeout {
	public:
		Timeout(const std::invocable auto& callback, const xieite::concepts::TemporalDuration auto duration) noexcept
		: interval([this, &callback] -> void {
			this->stop();
			callback();
		}, duration) {}

		bool good() const noexcept {
			return this->interval.good();
		}

		void stop() noexcept {
			this->interval.stop();
		}

	private:
		xieite::threads::Interval interval;
	};
}

#endif
