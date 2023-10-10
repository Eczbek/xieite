#pragma once

#include <concepts>
#include <functional>
#include "../concepts/temporal_duration.hpp"
#include "../threads/interval.hpp"

namespace xieite::threads {
	class Timeout {
	public:
		template<std::invocable<> Functor, xieite::concepts::TemporalDuration TemporalDuration>
		Timeout(const Functor& callback, const TemporalDuration duration) noexcept
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
