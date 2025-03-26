#ifndef DETAIL_XIEITE_HEADER_TRAIT_RM_VAR_RREF
#	define DETAIL_XIEITE_HEADER_TRAIT_RM_VAR_RREF
#
#	include "../trait/rm_rref_referent.hpp"
#	include "../trait/rm_var.hpp"

namespace xieite {
	template<typename T>
	using rm_var_rref = xieite::rm_var<xieite::rm_rref_referent<T>>;
}

#endif
