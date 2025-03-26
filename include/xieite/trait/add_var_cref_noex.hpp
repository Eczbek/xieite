#ifndef DETAIL_XIEITE_HEADER_TRAIT_ADD_VAR_CREF_NOEX
#	define DETAIL_XIEITE_HEADER_TRAIT_ADD_VAR_CREF_NOEX
#
#	include "../trait/add_noex.hpp"
#	include "../trait/add_var_cref.hpp"

namespace xieite {
	template<typename T, typename U>
	using add_var_cref_noex = xieite::add_var_cref<T, xieite::add_noex<U>>;
}

#endif
