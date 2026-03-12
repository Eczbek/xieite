#ifndef DETAIL_XTE_HEADER_TRAIT_IS_NOEX_MOVE_CONSTRUCTIBLE
#	define DETAIL_XTE_HEADER_TRAIT_IS_NOEX_MOVE_CONSTRUCTIBLE
#
#	include "../trait/is_noex_constructible.hpp"
#	include "../trait/remove_ref.hpp"

namespace xte {
	template<typename T>
	concept is_noex_move_constructible = xte::is_noex_constructible<T, xte::remove_ref<T>>;
}

#endif
