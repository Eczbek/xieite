#ifndef DETAIL_XTE_HEADER_FUNC_DEFER
#	define DETAIL_XTE_HEADER_FUNC_DEFER
#
#	include "../data/non_copyable.hpp"
#	include "../data/non_movable.hpp"
#	include "../preproc/fwd.hpp"
#	include "../trait/is_callable.hpp"
#	include "../trait/is_noex_move_constructible.hpp"

namespace xte {
	template<xte::is_callable<void()> func_type>
	struct defer : xte::non_copyable, xte::non_movable {
	private:
		func_type _func;
		bool _released = false;

	public:
		[[nodiscard]] explicit(false) constexpr defer(func_type&& func)
		noexcept(xte::is_noex_move_constructible<func_type>)
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

	template<typename func_type>
	defer(func_type&&) -> defer<func_type>;
}

#endif
