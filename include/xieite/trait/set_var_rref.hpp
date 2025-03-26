#ifndef DETAIL_XIEITE_HEADER_TRAIT_SET_VAR_RREF
#	define DETAIL_XIEITE_HEADER_TRAIT_SET_VAR_RREF
#
#	include "../trait/set_rref_referent.hpp"
#	include "../trait/set_var.hpp"

namespace xieite {
	template<bool qual, typename T>
	using set_var_rref = xieite::set_var<qual, xieite::set_rref_referent<qual, T>>;
}

#endif
