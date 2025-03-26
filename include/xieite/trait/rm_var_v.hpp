#ifndef DETAIL_XIEITE_HEADER_TRAIT_RM_VAR_V
#	define DETAIL_XIEITE_HEADER_TRAIT_RM_VAR_V
#
#	include "../trait/rm_v_referent.hpp"
#	include "../trait/rm_var.hpp"

namespace xieite {
	template<typename T>
	using rm_var_v = xieite::rm_var<xieite::rm_v_referent<T>>;
}

#endif
