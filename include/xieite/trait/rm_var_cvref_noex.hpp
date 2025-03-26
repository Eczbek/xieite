#ifndef DETAIL_XIEITE_HEADER_TRAIT_RM_VAR_CVREF_NOEX
#	define DETAIL_XIEITE_HEADER_TRAIT_RM_VAR_CVREF_NOEX
#
#	include "../trait/rm_noex.hpp"
#	include "../trait/rm_var_cvref.hpp"

namespace xieite {
	template<typename T>
	using rm_var_cvref_noex = xieite::rm_var_cvref<xieite::rm_noex<T>>;
}

#endif
