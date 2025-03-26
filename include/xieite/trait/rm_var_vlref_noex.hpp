#ifndef DETAIL_XIEITE_HEADER_TRAIT_RM_VAR_VLREF_NOEX
#	define DETAIL_XIEITE_HEADER_TRAIT_RM_VAR_VLREF_NOEX
#
#	include "../trait/rm_noex.hpp"
#	include "../trait/rm_var_vlref.hpp"

namespace xieite {
	template<typename T>
	using rm_var_vlref_noex = xieite::rm_var_vlref<xieite::rm_noex<T>>;
}

#endif
