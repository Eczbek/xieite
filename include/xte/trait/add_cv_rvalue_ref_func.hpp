#ifndef DETAIL_XTE_HEADER_TRAIT_ADD_CV_RVALUE_REF_FUNC
#	define DETAIL_XTE_HEADER_TRAIT_ADD_CV_RVALUE_REF_FUNC
#
#	include "../trait/add_cv_func.hpp"
#	include "../trait/add_rvalue_ref_func.hpp"

namespace xte {
	template<typename T>
	using add_cv_rvalue_ref_func = xte::add_rvalue_ref_func<xte::add_cv_func<T>>;
}

#endif
