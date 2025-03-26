#ifndef DETAIL_XIEITE_HEADER_TRAIT_CP_VAR_REF_NOEX
#	define DETAIL_XIEITE_HEADER_TRAIT_CP_VAR_REF_NOEX
#
#	include "../trait/cp_var_ref.hpp"
#	include "../trait/cp_noex.hpp"

namespace xieite {
	template<typename T, typename U>
	using cp_var_ref_noex = xieite::cp_var_ref<T, xieite::cp_noex<T, U>>;
}

#endif
