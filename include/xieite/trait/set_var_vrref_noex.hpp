#ifndef DETAIL_XIEITE_HEADER_TRAIT_SET_VAR_VRREF_NOEX
#	define DETAIL_XIEITE_HEADER_TRAIT_SET_VAR_VRREF_NOEX
#
#	include "../trait/set_noex.hpp"
#	include "../trait/set_var_vrref.hpp"

namespace xieite {
	template<bool qual, typename T>
	using set_var_vrref_noex = xieite::set_var_vrref<qual, xieite::set_noex<qual, T>>;
}

#endif
