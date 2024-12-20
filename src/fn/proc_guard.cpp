module;

#include <xieite/fwd.hpp>

export module xieite:proc_guard;

import std;
import :fn;

export namespace xieite {
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
