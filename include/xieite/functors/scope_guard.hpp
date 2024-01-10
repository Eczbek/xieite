#ifndef XIEITE_HEADER_FUNCTORS_SCOPE_GUARD
#	define XIEITE_HEADER_FUNCTORS_SCOPE_GUARD

#	include <concepts>
#	include <functional>
#	include <memory>
#	include <utility>

namespace xieite::functors {
	template<std::invocable<> Functor>
	class ScopeGuard {
	public:
		constexpr ScopeGuard(const Functor& callback) noexcept
		: callback(std::make_shared<Functor>(callback)) {}

		constexpr ScopeGuard(Functor& callback) noexcept
		: callback(std::make_shared<Functor>(callback)) {}

		constexpr ScopeGuard(Functor&& callback) noexcept
		: callback(std::make_shared<Functor>(std::move(callback))) {}

		constexpr ~ScopeGuard() {
			if (!this->released) {
				std::invoke(std::forward<Functor>(*this->callback));
			}
		}

		constexpr void release() noexcept {
			this->released = true;
		}

	private:
		std::shared_ptr<Functor> callback;
		bool released = false;
	};
}

#endif
