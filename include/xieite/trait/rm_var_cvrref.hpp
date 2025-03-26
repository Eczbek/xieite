#ifndef DETAIL_XIEITE_HEADER_TRAIT_RM_VAR_CVRREF
#	define DETAIL_XIEITE_HEADER_TRAIT_RM_VAR_CVRREF
#
#	include "../trait/rm_cvrref_referent.hpp"
#	include "../trait/rm_var.hpp"

namespace xieite {
	template<typename T>
	using rm_var_cvrref = xieite::rm_var<xieite::rm_cvrref_referent<T>>;
}

#endif
