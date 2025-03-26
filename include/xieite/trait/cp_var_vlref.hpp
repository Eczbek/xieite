#ifndef DETAIL_XIEITE_HEADER_TRAIT_CP_VAR_VLREF
#	define DETAIL_XIEITE_HEADER_TRAIT_CP_VAR_VLREF
#
#	include "../trait/cp_var.hpp"
#	include "../trait/cp_vlref_referent.hpp"

namespace xieite {
	template<typename T, typename U>
	using cp_var_vlref = xieite::cp_var<T, xieite::cp_vlref_referent<T, U>>;
}

#endif
