#ifndef DETAIL_XIEITE_HEADER_TRAIT_CP_VAR_CREF_NOEX
#	define DETAIL_XIEITE_HEADER_TRAIT_CP_VAR_CREF_NOEX
#
#	include "../trait/cp_var_cref.hpp"
#	include "../trait/cp_noex.hpp"

namespace xieite {
	template<typename T, typename U>
	using cp_var_cref_noex = xieite::cp_var_cref<T, xieite::cp_noex<T, U>>;
}

#endif
