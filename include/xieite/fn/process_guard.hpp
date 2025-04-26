#ifndef DETAIL_XIEITE_HEADER_FN_PROCESS_GUARD
#	define DETAIL_XIEITE_HEADER_FN_PROCESS_GUARD
#
#	include <concepts>
#	include "../fn/fn.hpp"
#	include "../pp/fwd.hpp"

namespace xieite {
	struct process_guard {
	public:
		template<std::invocable<> Fn, auto = [] {}>
		[[nodiscard]] process_guard(Fn&& fn) noexcept {
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

#endif
