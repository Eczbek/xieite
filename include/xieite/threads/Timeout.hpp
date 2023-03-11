#pragma once
#include <concepts> // std::invocable
#include <utility> // std::forward
#include <xieite/concepts/TemporalDuration.hpp>
#include <xieite/threads/Interval.hpp>

namespace xieite::threads {
	struct Timeout
	: xieite::threads::Interval {
		template<std::invocable<> C, xieite::concepts::TemporalDuration D>
		Timeout(C&& callback, const D duration) noexcept
		: xieite::threads::Interval([this, callback = std::forward<C>(callback)]() -> void {
			this->cancel();
			callback();
		}, duration) {}
	};
}
