#ifndef DETAIL_XIEITE_HEADER_TRAIT_ADD_VAR_VREF_NOEX
#	define DETAIL_XIEITE_HEADER_TRAIT_ADD_VAR_VREF_NOEX
#
#	include "../trait/add_noex.hpp"
#	include "../trait/add_var_vref.hpp"

namespace xieite {
	template<typename T, typename U>
	using add_var_vref_noex = xieite::add_var_vref<T, xieite::add_noex<U>>;
}

#endif
