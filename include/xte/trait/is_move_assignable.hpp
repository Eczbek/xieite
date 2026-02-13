#ifndef DETAIL_XTE_HEADER_TRAITS_IS_MOVE_ASSIGNABLE
#	define DETAIL_XTE_HEADER_TRAITS_IS_MOVE_ASSIGNABLE
#
#	include "../trait/is_assignable.hpp"
#	include "../trait/remove_ref.hpp"

namespace xte {
	template<typename T>
	concept is_move_assignable = xte::is_assignable<T&, xte::remove_ref<T>>;
}

#endif
