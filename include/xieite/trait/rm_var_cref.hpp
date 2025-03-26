#ifndef DETAIL_XIEITE_HEADER_TRAIT_RM_VAR_CREF
#	define DETAIL_XIEITE_HEADER_TRAIT_RM_VAR_CREF
#
#	include "../trait/rm_cref_referent.hpp"
#	include "../trait/rm_var.hpp"

namespace xieite {
	template<typename T>
	using rm_var_cref = xieite::rm_var<xieite::rm_cref_referent<T>>;
}

#endif
