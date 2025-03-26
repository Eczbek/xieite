#ifndef DETAIL_XIEITE_HEADER_TRAIT_SET_VAR_CV_NOEX
#	define DETAIL_XIEITE_HEADER_TRAIT_SET_VAR_CV_NOEX
#
#	include "../trait/set_noex.hpp"
#	include "../trait/set_var_cv.hpp"

namespace xieite {
	template<bool qual, typename T>
	using set_var_cv_noex = xieite::set_var_cv<qual, xieite::set_noex<qual, T>>;
}

#endif
