#ifndef DETAIL_XTE_HEADER_TRAITS_IS_MOVE_ASSIGNABLE_NOEX
#	define DETAIL_XTE_HEADER_TRAITS_IS_MOVE_ASSIGNABLE_NOEX
#
#	include "../trait/drop_ref.hpp"
#	include "../trait/is_assignable_noex.hpp"

namespace xte {
	template<typename T>
	concept is_move_assignable_noex = xte::is_assignable_noex<T&, xte::drop_ref<T>>;
}

#endif
