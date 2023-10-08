#ifndef XIEITE_HEADER__FUNCTORS__SCOPE_GUARD
#	define XIEITE_HEADER__FUNCTORS__SCOPE_GUARD

#	include <concepts>
#	include <functional>
#	include <utility>

namespace xieite::functors {
	template<std::invocable<> Functor>
	class ScopeGuard {
	public:
		constexpr ScopeGuard(Functor&& callback) noexcept
		: callback(std::forward<Functor>(callback)), released(false) {}

		constexpr ~ScopeGuard() {
			if (!this->released) {
				std::invoke(this->callback);
			}
		}

		constexpr void release() noexcept {
			this->released = true;
		}

	private:
		const Functor callback;
		bool released;
	};
}

#endif
