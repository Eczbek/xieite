#ifndef DETAIL_XIEITE_HEADER_TRAIT_RM_VAR_C
#	define DETAIL_XIEITE_HEADER_TRAIT_RM_VAR_C
#
#	include "../trait/rm_c_referent.hpp"
#	include "../trait/rm_var.hpp"

namespace xieite {
	template<typename T>
	using rm_var_c = xieite::rm_var<xieite::rm_c_referent<T>>;
}

#endif
