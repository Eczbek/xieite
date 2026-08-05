#ifndef DETAIL_XTE_HEADER_TRAIT_IS_IMPLICIT_MOVE_CONSTRUCTIBLE_NOEX
#	define DETAIL_XTE_HEADER_TRAIT_IS_IMPLICIT_MOVE_CONSTRUCTIBLE_NOEX
#
#	include "../trait/drop_ref.hpp"
#	include "../trait/is_implicit_constructible_noex.hpp"

namespace xte {
	template<typename T>
	concept is_implicit_move_constructible_noex = xte::is_implicit_constructible_noex<T, xte::drop_ref<T>>;
}

#endif
