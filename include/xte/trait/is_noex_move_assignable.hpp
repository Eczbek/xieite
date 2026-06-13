#ifndef DETAIL_XTE_HEADER_TRAITS_IS_NOEX_MOVE_ASSIGNABLE
#	define DETAIL_XTE_HEADER_TRAITS_IS_NOEX_MOVE_ASSIGNABLE
#
#	include "../trait/drop_ref.hpp"
#	include "../trait/is_noex_assignable.hpp"

namespace xte {
	template<typename T>
	concept is_noex_move_assignable = xte::is_noex_assignable<T&, xte::drop_ref<T>>;
}

#endif
