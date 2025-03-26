#ifndef DETAIL_XIEITE_HEADER_TRAIT_SET_VAR_VRREF
#	define DETAIL_XIEITE_HEADER_TRAIT_SET_VAR_VRREF
#
#	include "../trait/set_rref_referent.hpp"
#	include "../trait/set_var_v.hpp"

namespace xieite {
	template<bool qual, typename T>
	using set_var_vrref = xieite::set_var_v<qual, xieite::set_rref_referent<qual, T>>;
}

#endif
