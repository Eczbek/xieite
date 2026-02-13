#ifndef DETAIL_XTE_HEADER_FUNC_DEFER
#	define DETAIL_XTE_HEADER_FUNC_DEFER
#
#	include "../preproc/fwd.hpp"
#	include "../trait/is_callable.hpp"
#	include "../trait/is_noex_ctor.hpp"
#	include "../trait/non_copyable.hpp"
#	include "../trait/non_movable.hpp"

namespace xte {
	template<xte::is_callable<void()> Func>
	struct defer : xte::non_copyable, xte::non_movable {
	private:
		Func _func;
		bool _released = false;

	public:
		[[nodiscard]] explicit(false) constexpr defer(Func&& func)
		noexcept(xte::is_noex_ctor<Func, Func&&>)
		: _func(XTE_FWD(func)) {}

		constexpr ~defer() {
			if (!this->_released) {
				XTE_FWD(this->_func)();
			}
		}

		constexpr void release() noexcept {
			this->_released = true;
		}
	};

	template<typename Func>
	defer(Func&&) -> defer<Func>;
}

#endif
