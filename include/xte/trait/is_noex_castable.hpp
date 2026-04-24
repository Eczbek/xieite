#ifndef DETAIL_XTE_HEADER_TRAIT_IS_NOEX_CASTABLE
#	define DETAIL_XTE_HEADER_TRAIT_IS_NOEX_CASTABLE
#
#	include "../trait/is_noex_constructible.hpp"

namespace xte {
	template<typename T, typename U>
	concept is_noex_castable = xte::is_noex_constructible<U, T>;
}

#endif
