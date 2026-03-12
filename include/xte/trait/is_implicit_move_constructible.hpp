#ifndef DETAIL_XTE_HEADER_TRAIT_IS_IMPLICIT_MOVE_CONSTRUCTIBLE
#	define DETAIL_XTE_HEADER_TRAIT_IS_IMPLICIT_MOVE_CONSTRUCTIBLE
#
#	include "../trait/is_implicit_constructible.hpp"
#	include "../trait/remove_ref.hpp"

namespace xte {
	template<typename T>
	concept is_implicit_move_constructible = xte::is_implicit_constructible<T, xte::remove_ref<T>>;
}

#endif
