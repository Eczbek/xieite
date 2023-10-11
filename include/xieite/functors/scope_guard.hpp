#ifndef XIEITE_HEADER_FUNCTORS_SCOPE_GUARD
#	define XIEITE_HEADER_FUNCTORS_SCOPE_GUARD

#	include <concepts>
#	include <functional>
#	include <utility>

namespace xieite::functors {
	template<std::invocable<> Functor>
	class ScopeGuard {
	public:
		constexpr ScopeGuard(const Functor& callback) noexcept
		: callback(callback), released(false) {}

		constexpr ScopeGuard(Functor&& callback) noexcept
		: callback(std::move(callback)), released(false) {}

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
