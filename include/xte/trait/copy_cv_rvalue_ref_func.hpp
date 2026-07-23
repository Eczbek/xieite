#ifndef DETAIL_XTE_HEADER_TRAIT_COPY_CV_RVALUE_REF_FUNC
#	define DETAIL_XTE_HEADER_TRAIT_COPY_CV_RVALUE_REF_FUNC
#
#	include "../trait/copy_cv_func.hpp"
#	include "../trait/copy_rvalue_ref_func.hpp"

namespace xte {
	template<typename T, typename U>
	using copy_cv_rvalue_ref_func = xte::copy_rvalue_ref_func<T, xte::copy_cv_func<T, U>>;
}

#endif
