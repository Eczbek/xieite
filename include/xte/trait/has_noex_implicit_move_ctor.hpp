#ifndef DETAIL_XTE_HEADER_TRAIT_HAS_NOEX_IMPLICIT_MOVE_CTOR
#	define DETAIL_XTE_HEADER_TRAIT_HAS_NOEX_IMPLICIT_MOVE_CTOR
#
#	include "../trait/has_noex_implicit_ctor.hpp"

namespace xte {
	template<typename T>
	concept has_noex_implicit_move_ctor = xte::has_noex_implicit_ctor<T, T>;
}

#endif
