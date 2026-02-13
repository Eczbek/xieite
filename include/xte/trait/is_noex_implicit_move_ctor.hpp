#ifndef DETAIL_XTE_HEADER_TRAIT_IS_NOEX_IMPLICIT_MOVE_CTOR
#	define DETAIL_XTE_HEADER_TRAIT_IS_NOEX_IMPLICIT_MOVE_CTOR
#
#	include "../trait/is_noex_implicit_ctor.hpp"
#	include "../trait/remove_ref.hpp"

namespace xte {
	template<typename T>
	concept is_noex_implicit_move_ctor = xte::is_noex_implicit_ctor<T, xte::remove_ref<T>>;
}

#endif
