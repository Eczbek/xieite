#ifndef DETAIL_XIEITE_HEADER_TRAIT_CP_VAR_NOEX
#	define DETAIL_XIEITE_HEADER_TRAIT_CP_VAR_NOEX
#
#	include "../trait/cp_noex.hpp"
#	include "../trait/cp_var.hpp"

namespace xieite {
	template<typename T, typename U>
	using cp_var_noex = xieite::cp_var<T, xieite::cp_noex<T, U>>;
}

#endif
