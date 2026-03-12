#ifndef DETAIL_XTE_HEADER_TRAIT_IS_NOEX_IMPLICIT_MOVE_CONSTRUCTIBLE
#	define DETAIL_XTE_HEADER_TRAIT_IS_NOEX_IMPLICIT_MOVE_CONSTRUCTIBLE
#
#	include "../trait/is_noex_implicit_constructible.hpp"
#	include "../trait/remove_ref.hpp"

namespace xte {
	template<typename T>
	concept is_noex_implicit_move_constructible = xte::is_noex_implicit_constructible<T, xte::remove_ref<T>>;
}

#endif
