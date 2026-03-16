#ifndef DETAIL_XTE_HEADER_TRAIT_IS_CASTABLE
#	define DETAIL_XTE_HEADER_TRAIT_IS_CASTABLE
#
#	include "../trait/is_constructible.hpp"

namespace xte {
	template<typename T, typename U>
	concept is_castable = xte::is_constructible<U, T>;
}

#endif
