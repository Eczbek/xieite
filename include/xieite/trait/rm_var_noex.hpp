#ifndef DETAIL_XIEITE_HEADER_TRAIT_RM_VAR_NOEX
#	define DETAIL_XIEITE_HEADER_TRAIT_RM_VAR_NOEX
#
#	include "../trait/rm_noex.hpp"
#	include "../trait/rm_var.hpp"

namespace xieite {
	template<typename T>
	using rm_var_noex = xieite::rm_var<xieite::rm_noex<T>>;
}

#endif
