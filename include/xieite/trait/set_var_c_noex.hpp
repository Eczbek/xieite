#ifndef DETAIL_XIEITE_HEADER_TRAIT_SET_VAR_C_NOEX
#	define DETAIL_XIEITE_HEADER_TRAIT_SET_VAR_C_NOEX
#
#	include "../trait/set_noex.hpp"
#	include "../trait/set_var_c.hpp"

namespace xieite {
	template<bool qual, typename T>
	using set_var_c_noex = xieite::set_var_c<qual, xieite::set_noex<qual, T>>;
}

#endif
