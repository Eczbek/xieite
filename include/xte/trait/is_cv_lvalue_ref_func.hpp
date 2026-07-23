#ifndef DETAIL_XTE_HEADER_TRAIT_IS_CV_LVALUE_REF_FUNC
#	define DETAIL_XTE_HEADER_TRAIT_IS_CV_LVALUE_REF_FUNC
#
#	include "../trait/is_cv_func.hpp"
#	include "../trait/is_lvalue_ref_func.hpp"

namespace xte {
	template<typename T>
	concept is_cv_lvalue_ref_func = xte::is_cv_func<T> && xte::is_lvalue_ref_func<T>;
}

#endif
