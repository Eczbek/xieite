#ifndef DETAIL_XIEITE_HEADER_TRAIT_CP_VAR_LREF_NOEX
#	define DETAIL_XIEITE_HEADER_TRAIT_CP_VAR_LREF_NOEX
#
#	include "../trait/cp_var_lref.hpp"
#	include "../trait/cp_noex.hpp"

namespace xieite {
	template<typename T, typename U>
	using cp_var_lref_noex = xieite::cp_var_lref<T, xieite::cp_noex<T, U>>;
}

#endif
