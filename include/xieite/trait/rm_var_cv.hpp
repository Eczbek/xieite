#ifndef DETAIL_XIEITE_HEADER_TRAIT_RM_VAR_CV
#	define DETAIL_XIEITE_HEADER_TRAIT_RM_VAR_CV
#
#	include "../trait/rm_cv_referent.hpp"
#	include "../trait/rm_var.hpp"

namespace xieite {
	template<typename T>
	using rm_var_cv = xieite::rm_var<xieite::rm_cv_referent<T>>;
}

#endif
