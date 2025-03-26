#ifndef DETAIL_XIEITE_HEADER_TRAIT_RM_VAR_REF
#	define DETAIL_XIEITE_HEADER_TRAIT_RM_VAR_REF
#
#	include "../trait/rm_ref_referent.hpp"
#	include "../trait/rm_var.hpp"

namespace xieite {
	template<typename T>
	using rm_var_ref = xieite::rm_var<xieite::rm_ref_referent<T>>;
}

#endif
