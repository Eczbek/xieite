#ifndef DETAIL_XTE_HEADER_TRAIT_IS_IMPLICIT_MOVE_CONSTRUCTIBLE
#	define DETAIL_XTE_HEADER_TRAIT_IS_IMPLICIT_MOVE_CONSTRUCTIBLE
#
#	include "../trait/drop_ref.hpp"
#	include "../trait/is_implicit_constructible.hpp"

namespace xte {
	template<typename T>
	concept is_implicit_move_constructible = xte::is_implicit_constructible<T, xte::drop_ref<T>>;
}

#endif
