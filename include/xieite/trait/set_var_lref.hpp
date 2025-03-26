#ifndef DETAIL_XIEITE_HEADER_TRAIT_SET_VAR_LREF
#	define DETAIL_XIEITE_HEADER_TRAIT_SET_VAR_LREF
#
#	include "../trait/set_lref_referent.hpp"
#	include "../trait/set_var.hpp"

namespace xieite {
	template<bool qual, typename T>
	using set_var_lref = xieite::set_var<qual, xieite::set_lref_referent<qual, T>>;
}

#endif
