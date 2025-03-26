#ifndef DETAIL_XIEITE_HEADER_TRAIT_IS_VAR_CV_NOEX
#	define DETAIL_XIEITE_HEADER_TRAIT_IS_VAR_CV_NOEX
#
#	include "../trait/is_noex.hpp"
#	include "../trait/is_var_cv.hpp"

namespace xieite {
	template<typename T>
	concept is_var_cv_noex = xieite::is_var_cv<T> && xieite::is_noex<T>;
}

#endif
