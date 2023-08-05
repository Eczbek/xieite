#ifndef XIEITE_HEADER__FUNCTORS__SCOPE_GUARD
#	define XIEITE_HEADER__FUNCTORS__SCOPE_GUARD

#	include <concepts>

namespace xieite::functors {
	template<std::invocable<> Invocable>
	class ScopeGuard {
	public:
		constexpr ScopeGuard(const Invocable& callback) noexcept
		: callback(callback), released(false) {}

		constexpr ~ScopeGuard() {
			if (!this->released) {
				this->callback();
			}
		}

		constexpr void release() noexcept {
			this->released = true;
		}

	private:
		const Invocable callback;
		bool released;
	};
}

#endif
