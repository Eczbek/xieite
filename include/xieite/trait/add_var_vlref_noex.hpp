#ifndef DETAIL_XIEITE_HEADER_TRAIT_ADD_VAR_VLREF_NOEX
#	define DETAIL_XIEITE_HEADER_TRAIT_ADD_VAR_VLREF_NOEX
#
#	include "../trait/add_noex.hpp"
#	include "../trait/add_var_vlref.hpp"

namespace xieite {
	template<typename T>
	using add_var_vlref_noex = xieite::add_var_vlref<xieite::add_noex<T>>;
}

#endif
