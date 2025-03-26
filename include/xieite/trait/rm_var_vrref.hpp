#ifndef DETAIL_XIEITE_HEADER_TRAIT_RM_VAR_VRREF
#	define DETAIL_XIEITE_HEADER_TRAIT_RM_VAR_VRREF
#
#	include "../trait/rm_var.hpp"
#	include "../trait/rm_vrref_referent.hpp"

namespace xieite {
	template<typename T>
	using rm_var_vrref = xieite::rm_var<xieite::rm_vrref_referent<T>>;
}

#endif
