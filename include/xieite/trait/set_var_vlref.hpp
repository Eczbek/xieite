#ifndef DETAIL_XIEITE_HEADER_TRAIT_SET_VAR_VLREF
#	define DETAIL_XIEITE_HEADER_TRAIT_SET_VAR_VLREF
#
#	include "../trait/set_lref_referent.hpp"
#	include "../trait/set_var_v.hpp"

namespace xieite {
	template<bool qual, typename T>
	using set_var_vlref = xieite::set_var_v<qual, xieite::set_lref_referent<qual, T>>;
}

#endif
