#ifndef XIEITE_HEADER_FUNCTORS_SCOPE_GUARD
#	define XIEITE_HEADER_FUNCTORS_SCOPE_GUARD

#	include "../concepts/functable.hpp"
#	include "../functors/function.hpp"
#	include "../macros/forward.hpp"

namespace xieite::functors {
	struct ScopeGuard {
	public:
		template<xieite::concepts::Functable<void()> Functor_>
		constexpr ScopeGuard(Functor_&& callback) noexcept
		: callback(XIEITE_FORWARD(callback)) {}

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
