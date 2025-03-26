#ifndef DETAIL_XIEITE_HEADER_TRAIT_ADD_VAR_CVREF_NOEX
#	define DETAIL_XIEITE_HEADER_TRAIT_ADD_VAR_CVREF_NOEX
#
#	include "../trait/add_noex.hpp"
#	include "../trait/add_var_cvref.hpp"

namespace xieite {
	template<typename T, typename U>
	using add_var_cvref_noex = xieite::add_var_cvref<T, xieite::add_noex<U>>;
}

#endif
