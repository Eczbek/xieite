#ifndef DETAIL_XTE_HEADER_TRAIT_IS_MOVE_CONSTRUCTIBLE_IMPLICIT
#	define DETAIL_XTE_HEADER_TRAIT_IS_MOVE_CONSTRUCTIBLE_IMPLICIT
#
#	include "../trait/drop_ref.hpp"
#	include "../trait/is_constructible_implicit.hpp"

namespace xte {
	template<typename T>
	concept is_move_constructible_implicit = xte::is_constructible_implicit<T, xte::drop_ref<T>>;
}

#endif
