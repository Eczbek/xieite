#ifndef DETAIL_XTE_HEADER_TRAIT_IS_SAME_ANY_IGNORE_CV
#	define DETAIL_XTE_HEADER_TRAIT_IS_SAME_ANY_IGNORE_CV
#
#	include "../trait/is_same_ignore_cv.hpp"

namespace xte {
	template<typename T, typename... Us>
	concept is_same_any_ignore_cv = (... || xte::is_same_ignore_cv<T, Us>);
}

#endif
