module;

#include <xieite/fwd.hpp>

export module xieite:scope_guard;

import std;
import :fn;

export namespace xieite {
	struct scope_guard {
	public:
		template<std::invocable<> F>
		[[nodiscard]] explicit(false) constexpr scope_guard(F&& fn) noexcept
		: fn(XIEITE_FWD(fn)) {}

		constexpr ~scope_guard() {
			if (!this->released) {
				this->fn();
			}
		}

		constexpr void release() noexcept {
			this->released = true;
		}

	private:
		xieite::fn<void()> fn;
		bool released = false;
	};
}
