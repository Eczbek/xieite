#ifndef DETAIL_XTE_HEADER_TRAITS_IS_NOEX_MOVE_ASSIGNABLE
#	define DETAIL_XTE_HEADER_TRAITS_IS_NOEX_MOVE_ASSIGNABLE
#
#	include "../trait/is_noex_assignable.hpp"
#	include "../trait/remove_ref.hpp"

namespace xte {
	template<typename T>
	concept is_noex_move_assignable = xte::is_noex_assignable<T&, xte::remove_ref<T>>;
}

#endif
