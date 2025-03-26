#ifndef DETAIL_XIEITE_HEADER_TRAIT_CP_VAR_VREF
#	define DETAIL_XIEITE_HEADER_TRAIT_CP_VAR_VREF
#
#	include "../trait/cp_var.hpp"
#	include "../trait/cp_vref_referent.hpp"

namespace xieite {
	template<typename T, typename U>
	using cp_var_vref = xieite::cp_var<T, xieite::cp_vref_referent<T, U>>;
}

#endif
