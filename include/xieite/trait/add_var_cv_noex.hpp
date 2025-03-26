#ifndef DETAIL_XIEITE_HEADER_TRAIT_ADD_VAR_CV_NOEX
#	define DETAIL_XIEITE_HEADER_TRAIT_ADD_VAR_CV_NOEX
#
#	include "../trait/add_noex.hpp"
#	include "../trait/add_var_cv.hpp"

namespace xieite {
	template<typename T>
	using add_var_cv_noex = xieite::add_var_cv<xieite::add_noex<T>>;
}

#endif
