#ifndef DETAIL_XTE_HEADER_DEFER
#	define DETAIL_XTE_HEADER_DEFER
#
#	include "./data/non_movable.hpp"
#	include "./preproc/fwd.hpp"
#	include "./trait/drop_cvref.hpp"
#	include "./trait/is_callable.hpp"
#	include "./trait/is_move_constructible_noex.hpp"

namespace xte {
	template<xte::is_callable<void()> func_type>
	struct defer : xte::non_movable {
	private:
		func_type _func;

	public:
		[[nodiscard]] explicit(false) constexpr defer(func_type&& func)
		noexcept(xte::is_move_constructible_noex<func_type>)
		: _func(XTE_FWD(func)) {}

		constexpr ~defer() {
			XTE_FWD(this->_func)();
		}
	};

	template<typename func_type>
	defer(func_type&&) -> defer<xte::drop_cvref<func_type>>;
}

#endif
