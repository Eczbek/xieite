#pragma once

#include <concepts>
#include "../fn/fn.hpp"
#include "../pp/fwd.hpp"

namespace xieite {
	struct proc_guard {
	public:
		template<std::invocable<> F, auto = [] {}>
		[[nodiscard]] proc_guard(F&& fn) noexcept {
			struct guard {
				const xieite::fn<void()> fn;
				bool released = false;

				~guard() {
					if (!this->released) {
						this->fn();
					}
				}
			};

			static guard guard = guard(XIEITE_FWD(fn));
			this->released = &guard.released;
		}

		void release() noexcept {
			*this->released = true;
		}

	private:
		bool* released;
	};
}
