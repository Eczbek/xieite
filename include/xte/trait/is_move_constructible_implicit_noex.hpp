#ifndef DETAIL_XTE_HEADER_TRAIT_IS_MOVE_CONSTRUCTIBLE_IMPLICIT_NOEX
#	define DETAIL_XTE_HEADER_TRAIT_IS_MOVE_CONSTRUCTIBLE_IMPLICIT_NOEX
#
#	include "../trait/drop_ref.hpp"
#	include "../trait/is_constructible_implicit_noex.hpp"

namespace xte {
	template<typename T>
	concept is_move_constructible_implicit_noex = xte::is_constructible_implicit_noex<T, xte::drop_ref<T>>;
}

#endif
