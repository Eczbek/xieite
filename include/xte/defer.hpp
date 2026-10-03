#ifndef DETAIL_XTE_HEADER_DEFER
#	define DETAIL_XTE_HEADER_DEFER
#
#	include "./class_traits.hpp"
#	include "./macros.hpp"
#	include "./qual_traits.hpp"

namespace xte {
	template<xte::is_callable<void()> func_type>
	struct defer : xte::non_movable {
	private:
		func_type _func;

	public:
		[[nodiscard]] constexpr explicit(false) defer(func_type&& func)
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
