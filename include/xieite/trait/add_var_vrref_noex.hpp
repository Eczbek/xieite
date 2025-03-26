#ifndef DETAIL_XIEITE_HEADER_TRAIT_ADD_VAR_VRREF_NOEX
#	define DETAIL_XIEITE_HEADER_TRAIT_ADD_VAR_VRREF_NOEX
#
#	include "../trait/add_noex.hpp"
#	include "../trait/add_var_vrref.hpp"

namespace xieite {
	template<typename T>
	using add_var_vrref_noex = xieite::add_var_vrref<xieite::add_noex<T>>;
}

#endif
