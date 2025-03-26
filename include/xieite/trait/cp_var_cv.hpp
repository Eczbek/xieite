#ifndef DETAIL_XIEITE_HEADER_TRAIT_CP_VAR_CV
#	define DETAIL_XIEITE_HEADER_TRAIT_CP_VAR_CV
#
#	include "../trait/cp_cv_referent.hpp"
#	include "../trait/cp_var.hpp"

namespace xieite {
	template<typename T, typename U>
	using cp_var_cv = xieite::cp_var<T, xieite::cp_cv_referent<T, U>>;
}

#endif
