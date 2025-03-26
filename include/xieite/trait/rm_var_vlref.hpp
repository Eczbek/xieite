#ifndef DETAIL_XIEITE_HEADER_TRAIT_RM_VAR_VLREF
#	define DETAIL_XIEITE_HEADER_TRAIT_RM_VAR_VLREF
#
#	include "../trait/rm_var.hpp"
#	include "../trait/rm_vlref_referent.hpp"

namespace xieite {
	template<typename T>
	using rm_var_vlref = xieite::rm_var<xieite::rm_vlref_referent<T>>;
}

#endif
