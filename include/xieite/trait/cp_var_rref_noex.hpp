#ifndef DETAIL_XIEITE_HEADER_TRAIT_CP_VAR_RREF_NOEX
#	define DETAIL_XIEITE_HEADER_TRAIT_CP_VAR_RREF_NOEX
#
#	include "../trait/cp_var_rref.hpp"
#	include "../trait/cp_noex.hpp"

namespace xieite {
	template<typename T, typename U>
	using cp_var_rref_noex = xieite::cp_var_rref<T, xieite::cp_noex<T, U>>;
}

#endif
