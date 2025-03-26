#ifndef DETAIL_XIEITE_HEADER_TRAIT_CP_VAR_VRREF
#	define DETAIL_XIEITE_HEADER_TRAIT_CP_VAR_VRREF
#
#	include "../trait/cp_var.hpp"
#	include "../trait/cp_vrref_referent.hpp"

namespace xieite {
	template<typename T, typename U>
	using cp_var_vrref = xieite::cp_var<T, xieite::cp_vrref_referent<T, U>>;
}

#endif
