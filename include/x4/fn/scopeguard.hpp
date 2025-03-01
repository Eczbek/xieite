#pragma once

#include <concepts>
#include "../fn/fn.hpp"
#include "../pp/fwd.hpp"

namespace x4 {
	struct scopeguard {
	public:
		template<std::invocable<> F>
		[[nodiscard]] constexpr scopeguard(F&& fn) noexcept
		: fn(X4FWD(fn)) {}

		constexpr ~scopeguard() {
			if (!this->released) {
				this->fn();
			}
		}

		constexpr void release() noexcept {
			this->released = true;
		}

	private:
		x4::fn<void()> fn;
		bool released = false;
	};
}
