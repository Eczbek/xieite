#ifndef DETAIL_XIEITE_HEADER_TRAIT_RM_VAR_VRREF_NOEX
#	define DETAIL_XIEITE_HEADER_TRAIT_RM_VAR_VRREF_NOEX
#
#	include "../trait/rm_noex.hpp"
#	include "../trait/rm_var_vrref.hpp"

namespace xieite {
	template<typename T>
	using rm_var_vrref_noex = xieite::rm_var_vrref<xieite::rm_noex<T>>;
}

#endif
