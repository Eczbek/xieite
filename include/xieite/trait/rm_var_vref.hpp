#ifndef DETAIL_XIEITE_HEADER_TRAIT_RM_VAR_VREF
#	define DETAIL_XIEITE_HEADER_TRAIT_RM_VAR_VREF
#
#	include "../trait/rm_var.hpp"
#	include "../trait/rm_vref_referent.hpp"

namespace xieite {
	template<typename T>
	using rm_var_vref = xieite::rm_var<xieite::rm_vref_referent<T>>;
}

#endif
