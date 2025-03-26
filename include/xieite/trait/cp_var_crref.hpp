#ifndef DETAIL_XIEITE_HEADER_TRAIT_CP_VAR_CRREF
#	define DETAIL_XIEITE_HEADER_TRAIT_CP_VAR_CRREF
#
#	include "../trait/cp_crref_referent.hpp"
#	include "../trait/cp_var.hpp"

namespace xieite {
	template<typename T, typename U>
	using cp_var_crref = xieite::cp_var<T, xieite::cp_crref_referent<T, U>>;
}

#endif
