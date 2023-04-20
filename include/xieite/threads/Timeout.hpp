#pragma once

#include <concepts>
#include <utility>
#include <xieite/concepts/TemporalDuration.hpp>
#include <xieite/threads/Interval.hpp>

namespace xieite::threads {
	class Timeout {
	private:
		xieite::threads::Interval interval;

	public:
		template<std::invocable<> Invocable>
		Timeout(Invocable&& callback, const xieite::concepts::TemporalDuration auto duration) noexcept
		: interval([this, callback = std::forward<Invocable>(callback)]() -> void {
			this->stop();
			callback();
		}, duration) {}

		bool good() const noexcept {
			return this->interval.good();
		}

		void stop() noexcept {
			this->interval.stop();
		}
	};
}
