#ifndef DETAIL_XTE_HEADER_TRAIT_IS_CV_LVALUE_REF
#	define DETAIL_XTE_HEADER_TRAIT_IS_CV_LVALUE_REF
#
#	include "../trait/is_cv.hpp"
#	include "../trait/is_lvalue_ref.hpp"

namespace xte {
	template<typename T>
	concept is_cv_lvalue_ref = xte::is_cv<T> && xte::is_lvalue_ref<T>;
}

#endif
