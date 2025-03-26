#ifndef DETAIL_XIEITE_HEADER_TRAIT_CP_VAR_CVREF
#	define DETAIL_XIEITE_HEADER_TRAIT_CP_VAR_CVREF
#
#	include "../trait/cp_cvref_referent.hpp"
#	include "../trait/cp_var.hpp"

namespace xieite {
	template<typename T, typename U>
	using cp_var_cvref = xieite::cp_var<T, xieite::cp_cvref_referent<T, U>>;
}

#endif
