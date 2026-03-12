#ifndef DETAIL_XTE_HEADER_TRAIT_IS_MOVE_CONSTRUCTIBLE
#	define DETAIL_XTE_HEADER_TRAIT_IS_MOVE_CONSTRUCTIBLE
#
#	include "../trait/is_constructible.hpp"
#	include "../trait/remove_ref.hpp"

namespace xte {
	template<typename T>
	concept is_move_constructible = xte::is_constructible<T, xte::remove_ref<T>>;
}

#endif
