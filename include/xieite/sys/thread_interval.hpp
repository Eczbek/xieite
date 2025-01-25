#pragma once

#include <concepts>
#include <functional>
#include <thread>
#include "../sys/thread_loop.hpp"
#include "../trait/is_dur.hpp"

namespace xieite {
	struct thread_interval {
	public:
		template<std::invocable<> F, xieite::is_dur Dur>
		[[nodiscard]] thread_interval(F&& fn, Dur dur) noexcept
		: loop([&fn, dur] -> void {
			static bool first = true;
			if (first) {
				first = false;
			} else {
				std::invoke(fn);
			}
			std::this_thread::sleep_for(dur);
		}) {}

		[[nodiscard]] explicit operator bool() const noexcept {
			return static_cast<bool>(this->loop);
		}

		void stop() noexcept {
			this->loop.stop();
		}

	private:
		xieite::thread_loop loop;
	};
}
