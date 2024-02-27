#ifndef XIEITE_HEADER_FUNCTORS_SCOPE_GUARD
#	define XIEITE_HEADER_FUNCTORS_SCOPE_GUARD

#	include <functional>
#	include <memory>
#	include <utility>
#	include "../functors/function.hpp"

namespace xieite::functors {
	struct ScopeGuard {
	public:
		constexpr ScopeGuard(const xieite::functors::Function<void()>& callback) noexcept
		: callback(callback) {}

		constexpr ~ScopeGuard() {
			if (!this->released) {
				this->callback();
			}
		}

		constexpr void release() noexcept {
			this->released = true;
		}

	private:
		xieite::functors::Function<void()> callback;
		bool released = false;
	};
}

#endif
