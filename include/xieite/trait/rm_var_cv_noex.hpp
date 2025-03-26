#ifndef DETAIL_XIEITE_HEADER_TRAIT_RM_VAR_CV_NOEX
#	define DETAIL_XIEITE_HEADER_TRAIT_RM_VAR_CV_NOEX
#
#	include "../trait/rm_noex.hpp"
#	include "../trait/rm_var_cv.hpp"

namespace xieite {
	template<typename T>
	using rm_var_cv_noex = xieite::rm_var_cv<xieite::rm_noex<T>>;
}

#endif
