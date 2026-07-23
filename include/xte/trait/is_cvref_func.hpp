#ifndef DETAIL_XTE_HEADER_TRAIT_IS_CVREF_FUNC
#	define DETAIL_XTE_HEADER_TRAIT_IS_CVREF_FUNC
#
#	include "../trait/is_cv_func.hpp"
#	include "../trait/is_ref_func.hpp"

namespace xte {
	template<typename T>
	concept is_cvref_func = xte::is_cv_func<T> && xte::is_ref_func<T>;
}

#endif
