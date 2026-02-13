#ifndef DETAIL_XTE_HEADER_TRAIT_IS_SAME_ANY_IGNORE_CVREF
#	define DETAIL_XTE_HEADER_TRAIT_IS_SAME_ANY_IGNORE_CVREF
#
#	include "../trait/is_same_ignore_cvref.hpp"

namespace xte {
	template<typename T, typename... Us>
	concept is_same_any_ignore_cvref = (... || xte::is_same_ignore_cvref<T, Us>);
}

#endif
