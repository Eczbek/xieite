#ifndef DETAIL_XTE_HEADER_TRAIT_IS_ASSIGNABLE_TO
#	define DETAIL_XTE_HEADER_TRAIT_IS_ASSIGNABLE_TO
#
#	include "../trait/is_assignable.hpp"

namespace xte {
	template<typename T, typename U>
	concept is_assignable_to = xte::is_assignable<U, T>;
}

#endif
