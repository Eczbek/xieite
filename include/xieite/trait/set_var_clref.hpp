#ifndef DETAIL_XIEITE_HEADER_TRAIT_SET_VAR_CLREF
#	define DETAIL_XIEITE_HEADER_TRAIT_SET_VAR_CLREF
#
#	include "../trait/set_lref_referent.hpp"
#	include "../trait/set_var_c.hpp"

namespace xieite {
	template<bool qual, typename T>
	using set_var_clref = xieite::set_var_c<qual, xieite::set_lref_referent<qual, T>>;
}

#endif
