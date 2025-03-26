#ifndef DETAIL_XIEITE_HEADER_TRAIT_ADD_VAR_CRREF_NOEX
#	define DETAIL_XIEITE_HEADER_TRAIT_ADD_VAR_CRREF_NOEX
#
#	include "../trait/add_noex.hpp"
#	include "../trait/add_var_crref.hpp"

namespace xieite {
	template<typename T>
	using add_var_crref_noex = xieite::add_var_crref<xieite::add_noex<T>>;
}

#endif
