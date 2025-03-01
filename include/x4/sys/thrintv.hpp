#pragma once

#include <concepts>
#include <functional>
#include <thread>
#include "../sys/thrloop.hpp"
#include "../trait/isdur.hpp"

namespace x4 {
	struct thrintv {
	public:
		template<std::invocable<> F, x4::isdur Dur>
		[[nodiscard]] thrintv(F&& fn, Dur dur) noexcept
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
		x4::thrloop loop;
	};
}
