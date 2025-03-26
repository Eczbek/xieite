#ifndef DETAIL_XIEITE_HEADER_TRAIT_CP_VAR_CV_NOEX
#	define DETAIL_XIEITE_HEADER_TRAIT_CP_VAR_CV_NOEX
#
#	include "../trait/cp_var_cv.hpp"
#	include "../trait/cp_noex.hpp"

namespace xieite {
	template<typename T, typename U>
	using cp_var_cv_noex = xieite::cp_var_cv<T, xieite::cp_noex<T, U>>;
}

#endif
