#ifndef DETAIL_XIEITE_HEADER_TRAIT_CP_VAR_CRREF_NOEX
#	define DETAIL_XIEITE_HEADER_TRAIT_CP_VAR_CRREF_NOEX
#
#	include "../trait/cp_var_crref.hpp"
#	include "../trait/cp_noex.hpp"

namespace xieite {
	template<typename T, typename U>
	using cp_var_crref_noex = xieite::cp_var_crref<T, xieite::cp_noex<T, U>>;
}

#endif
