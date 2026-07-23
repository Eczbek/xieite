#ifndef DETAIL_XTE_HEADER_TRAIT_IS_CV_RVALUE_REF_FUNC
#	define DETAIL_XTE_HEADER_TRAIT_IS_CV_RVALUE_REF_FUNC
#
#	include "../trait/is_cv_func.hpp"
#	include "../trait/is_rvalue_ref_func.hpp"

namespace xte {
	template<typename T>
	concept is_cv_rvalue_ref_func = xte::is_cv_func<T> && xte::is_rvalue_ref_func<T>;
}

#endif
