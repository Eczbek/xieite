#ifndef DETAIL_XTE_HEADER_TRAIT_IS_CASTABLE_NOEX
#	define DETAIL_XTE_HEADER_TRAIT_IS_CASTABLE_NOEX
#
#	include "../trait/is_constructible_noex.hpp"

namespace xte {
	template<typename T, typename U>
	concept is_castable_noex = xte::is_constructible_noex<U, T>;
}

#endif
