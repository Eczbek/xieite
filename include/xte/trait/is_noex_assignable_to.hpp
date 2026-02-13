#ifndef DETAIL_XTE_HEADER_TRAIT_IS_NOEX_ASSIGNABLE_TO
#	define DETAIL_XTE_HEADER_TRAIT_IS_NOEX_ASSIGNABLE_TO
#
#	include "../trait/is_noex_assignable.hpp"

namespace xte {
	template<typename T, typename U>
	concept is_noex_assignable_to = xte::is_noex_assignable<U, T>;
}

#endif
