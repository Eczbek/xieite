#ifndef DETAIL_XIEITE_HEADER_TRAIT_SET_VAR_CVRREF_NOEX
#	define DETAIL_XIEITE_HEADER_TRAIT_SET_VAR_CVRREF_NOEX
#
#	include "../trait/set_noex.hpp"
#	include "../trait/set_var_cvrref.hpp"

namespace xieite {
	template<bool qual, typename T>
	using set_var_cvrref_noex = xieite::set_var_cvrref<qual, xieite::set_noex<qual, T>>;
}

#endif
