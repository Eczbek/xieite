#ifndef DETAIL_XIEITE_HEADER_TRAIT_CP_VAR_REF
#	define DETAIL_XIEITE_HEADER_TRAIT_CP_VAR_REF
#
#	include "../trait/cp_ref_referent.hpp"
#	include "../trait/cp_var.hpp"

namespace xieite {
	template<typename T, typename U>
	using cp_var_ref = xieite::cp_var<T, xieite::cp_ref_referent<T, U>>;
}

#endif
