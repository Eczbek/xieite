#ifndef DETAIL_XTE_HEADER_TRAIT_IS_CV_FUNC
#	define DETAIL_XTE_HEADER_TRAIT_IS_CV_FUNC
#
#	include "../trait/is_const_func.hpp"
#	include "../trait/is_volatile_func.hpp"

namespace xte {
	template<typename T>
	concept is_cv_func = xte::is_const_func<T> && xte::is_volatile_func<T>;
}

#endif
