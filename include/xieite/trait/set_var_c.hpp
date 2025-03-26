#ifndef DETAIL_XIEITE_HEADER_TRAIT_SET_VAR_C
#	define DETAIL_XIEITE_HEADER_TRAIT_SET_VAR_C
#
#	include "../trait/set_c_referent.hpp"
#	include "../trait/set_var.hpp"

namespace xieite {
	template<bool qual, typename T>
	using set_var_c = xieite::set_var<qual, xieite::set_c_referent<qual, T>>;
}

#endif
