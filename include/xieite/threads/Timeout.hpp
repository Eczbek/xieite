#pragma once
#include <concepts> // std::invocable
#include <utility> // std::forward
#include <xieite/concepts/TemporalDuration.hpp>
#include <xieite/threads/Interval.hpp>

namespace xieite::threads {
	struct Timeout
	: xieite::threads::Interval {
		template<std::invocable<> Invocable>
		Timeout(Invocable&& callback, const xieite::concepts::TemporalDuration auto duration) noexcept
		: xieite::threads::Interval([this, callback = std::forward<Invocable>(callback)]() -> void {
			this->cancel();
			callback();
		}, duration) {}
	};
}
