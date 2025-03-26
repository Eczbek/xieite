#ifndef DETAIL_XIEITE_HEADER_TRAIT_SET_VAR_V
#	define DETAIL_XIEITE_HEADER_TRAIT_SET_VAR_V
#
#	include "../trait/set_v_referent.hpp"
#	include "../trait/set_var.hpp"

namespace xieite {
	template<bool qual, typename T>
	using set_var_v = xieite::set_var<qual, xieite::set_v_referent<qual, T>>;
}

#endif
