#pragma once

#include <concepts>
#include <thread>
#include <utility>
#include <xieite/concepts/TemporalDuration.hpp>
#include <xieite/threads/Loop.hpp>

namespace xieite::threads {
	class Interval {
	private:
		xieite::threads::Loop loop;

	public:
		template<std::invocable<> Invocable>
		Interval(Invocable&& callback, const xieite::concepts::TemporalDuration auto duration) noexcept
		: loop([callback = std::forward<Invocable>(callback), duration]() noexcept -> void {
			std::this_thread::sleep_for(duration);
			callback();
		}) {}

		operator bool() const noexcept {
			return static_cast<bool>(this->loop);
		}

		void cancel() noexcept {
			this->loop.cancel();
		}
	};
}
