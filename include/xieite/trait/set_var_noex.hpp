#ifndef DETAIL_XIEITE_HEADER_TRAIT_SET_VAR_NOEX
#	define DETAIL_XIEITE_HEADER_TRAIT_SET_VAR_NOEX
#
#	include "../trait/set_noex.hpp"
#	include "../trait/set_var.hpp"

namespace xieite {
	template<bool qual, typename T>
	using set_var_noex = xieite::set_var<qual, xieite::set_noex<qual, T>>;
}

#endif
