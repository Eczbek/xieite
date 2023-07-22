#ifndef XIEITE_HEADER_FUNCTIONS_SCOPEGUARD
#	define XIEITE_HEADER_FUNCTIONS_SCOPEGUARD

#	include <concepts>

namespace xieite::functions {
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
