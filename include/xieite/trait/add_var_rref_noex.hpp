#ifndef DETAIL_XIEITE_HEADER_TRAIT_ADD_VAR_RREF_NOEX
#	define DETAIL_XIEITE_HEADER_TRAIT_ADD_VAR_RREF_NOEX
#
#	include "../trait/add_noex.hpp"
#	include "../trait/add_var_rref.hpp"

namespace xieite {
	template<typename T>
	using add_var_rref_noex = xieite::add_var_rref<xieite::add_noex<T>>;
}

#endif
