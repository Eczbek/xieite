#ifndef XIEITE_HEADER__THREADS__TIMEOUT
#	define XIEITE_HEADER__THREADS__TIMEOUT

#	include <concepts>
#	include <functional>
#	include "../concepts/ChronoDuration.hpp"
#	include "../threads/Interval.hpp"

namespace xieite::threads {
	class Timeout {
	public:
		template<std::invocable<> Functor, xieite::concepts::ChronoDuration ChronoDuration>
		Timeout(const Functor& callback, const ChronoDuration duration) noexcept
		: interval([this, &callback] {
			this->stop();
			std::invoke(callback);
		}, duration) {}

		[[nodiscard]] bool good() const noexcept {
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
