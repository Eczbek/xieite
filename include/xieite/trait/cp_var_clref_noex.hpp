#ifndef DETAIL_XIEITE_HEADER_TRAIT_CP_VAR_CLREF_NOEX
#	define DETAIL_XIEITE_HEADER_TRAIT_CP_VAR_CLREF_NOEX
#
#	include "../trait/cp_var_clref.hpp"
#	include "../trait/cp_noex.hpp"

namespace xieite {
	template<typename T, typename U>
	using cp_var_clref_noex = xieite::cp_var_clref<T, xieite::cp_noex<T, U>>;
}

#endif
