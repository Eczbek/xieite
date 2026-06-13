#ifndef DETAIL_XTE_HEADER_TRAIT_IS_NOEX_MOVE_CONSTRUCTIBLE
#	define DETAIL_XTE_HEADER_TRAIT_IS_NOEX_MOVE_CONSTRUCTIBLE
#
#	include "../trait/drop_ref.hpp"
#	include "../trait/is_noex_constructible.hpp"

namespace xte {
	template<typename T>
	concept is_noex_move_constructible = xte::is_noex_constructible<T, xte::drop_ref<T>>;
}

#endif
