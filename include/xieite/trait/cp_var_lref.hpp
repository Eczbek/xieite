#ifndef DETAIL_XIEITE_HEADER_TRAIT_CP_VAR_LREF
#	define DETAIL_XIEITE_HEADER_TRAIT_CP_VAR_LREF
#
#	include "../trait/cp_lref_referent.hpp"
#	include "../trait/cp_var.hpp"

namespace xieite {
	template<typename T, typename U>
	using cp_var_lref = xieite::cp_var<T, xieite::cp_lref_referent<T, U>>;
}

#endif
