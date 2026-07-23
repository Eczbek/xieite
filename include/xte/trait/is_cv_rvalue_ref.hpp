#ifndef DETAIL_XTE_HEADER_TRAIT_IS_CV_RVALUE_REF
#	define DETAIL_XTE_HEADER_TRAIT_IS_CV_RVALUE_REF
#
#	include "../trait/is_cv.hpp"
#	include "../trait/is_rvalue_ref.hpp"

namespace xte {
	template<typename T>
	concept is_cv_rvalue_ref = xte::is_cv<T> && xte::is_rvalue_ref<T>;
}

#endif
