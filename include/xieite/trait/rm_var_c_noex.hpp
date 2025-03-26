#ifndef DETAIL_XIEITE_HEADER_TRAIT_RM_VAR_C_NOEX
#	define DETAIL_XIEITE_HEADER_TRAIT_RM_VAR_C_NOEX
#
#	include "../trait/rm_noex.hpp"
#	include "../trait/rm_var_c.hpp"

namespace xieite {
	template<typename T>
	using rm_var_c_noex = xieite::rm_var_c<xieite::rm_noex<T>>;
}

#endif
