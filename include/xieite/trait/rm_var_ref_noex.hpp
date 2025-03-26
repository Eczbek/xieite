#ifndef DETAIL_XIEITE_HEADER_TRAIT_RM_VAR_REF_NOEX
#	define DETAIL_XIEITE_HEADER_TRAIT_RM_VAR_REF_NOEX
#
#	include "../trait/rm_noex.hpp"
#	include "../trait/rm_var_ref.hpp"

namespace xieite {
	template<typename T>
	using rm_var_ref_noex = xieite::rm_var_ref<xieite::rm_noex<T>>;
}

#endif
