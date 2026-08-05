#ifndef DETAIL_XTE_HEADER_TRAIT_IS_ASSIGNABLE_TO_NOEX
#	define DETAIL_XTE_HEADER_TRAIT_IS_ASSIGNABLE_TO_NOEX
#
#	include "../trait/is_assignable_noex.hpp"

namespace xte {
	template<typename T, typename U>
	concept is_assignable_to_noex = xte::is_assignable_noex<U, T>;
}

#endif
