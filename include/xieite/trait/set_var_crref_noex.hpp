#ifndef DETAIL_XIEITE_HEADER_TRAIT_SET_VAR_CRREF_NOEX
#	define DETAIL_XIEITE_HEADER_TRAIT_SET_VAR_CRREF_NOEX
#
#	include "../trait/set_noex.hpp"
#	include "../trait/set_var_crref.hpp"

namespace xieite {
	template<bool qual, typename T>
	using set_var_crref_noex = xieite::set_var_crref<qual, xieite::set_noex<qual, T>>;
}

#endif
