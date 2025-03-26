#ifndef DETAIL_XIEITE_HEADER_TRAIT_SET_VAR_VLREF_NOEX
#	define DETAIL_XIEITE_HEADER_TRAIT_SET_VAR_VLREF_NOEX
#
#	include "../trait/set_noex.hpp"
#	include "../trait/set_var_vlref.hpp"

namespace xieite {
	template<bool qual, typename T>
	using set_var_vlref_noex = xieite::set_var_vlref<qual, xieite::set_noex<qual, T>>;
}

#endif
