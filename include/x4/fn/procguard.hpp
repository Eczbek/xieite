#pragma once

#include <concepts>
#include "../fn/fn.hpp"
#include "../pp/fwd.hpp"

namespace x4 {
	struct procguard {
	public:
		template<std::invocable<> F, auto = [] {}>
		[[nodiscard]] procguard(F&& fn) noexcept {
			struct guard {
				const x4::fn<void()> fn;
				bool released = false;

				~guard() {
					if (!this->released) {
						this->fn();
					}
				}
			};

			static guard guard = guard(X4FWD(fn));
			this->released = &guard.released;
		}

		void release() noexcept {
			*this->released = true;
		}

	private:
		bool* released;
	};
}
