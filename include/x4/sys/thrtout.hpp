#pragma once

#include <concepts>
#include <functional>
#include "../pp/fwd.hpp"
#include "../sys/thrintv.hpp"
#include "../trait/isdur.hpp"

namespace x4 {
	struct thrtout {
	public:
		template<std::invocable<> F, x4::isdur Dur>
		[[nodiscard]] thrtout(F&& callback, Dur dur) noexcept
		: interval([this, &callback] -> void {
			this->stop();
			std::invoke(X4FWD(callback));
		}, dur) {}

		[[nodiscard]] explicit operator bool() const noexcept {
			return static_cast<bool>(this->interval);
		}

		void stop() noexcept {
			this->interval.stop();
		}

	private:
		x4::thrintv interval;
	};
}
