#ifndef DETAIL_XTE_HEADER_TRAIT_COPY_CV_RVALUE_REF
#	define DETAIL_XTE_HEADER_TRAIT_COPY_CV_RVALUE_REF
#
#	include "../trait/copy_cv.hpp"
#	include "../trait/copy_rvalue_ref.hpp"

namespace xte {
	template<typename T, typename U>
	using copy_cv_rvalue_ref = xte::copy_rvalue_ref<T, xte::copy_cv<T, U>>;
}

#endif
