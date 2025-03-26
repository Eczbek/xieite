#ifndef DETAIL_XIEITE_HEADER_TRAIT_ADD_VAR_CLREF_NOEX
#	define DETAIL_XIEITE_HEADER_TRAIT_ADD_VAR_CLREF_NOEX
#
#	include "../trait/add_noex.hpp"
#	include "../trait/add_var_clref.hpp"

namespace xieite {
	template<typename T>
	using add_var_clref_noex = xieite::add_var_clref<xieite::add_noex<T>>;
}

#endif
