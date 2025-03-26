#ifndef DETAIL_XIEITE_HEADER_TRAIT_RM_VAR_CVREF
#	define DETAIL_XIEITE_HEADER_TRAIT_RM_VAR_CVREF
#
#	include "../trait/rm_cvref_referent.hpp"
#	include "../trait/rm_var.hpp"

namespace xieite {
	template<typename T>
	using rm_var_cvref = xieite::rm_var<xieite::rm_cvref_referent<T>>;
}

#endif
