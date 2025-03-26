#ifndef DETAIL_XIEITE_HEADER_TRAIT_IS_VAR_CRREF_NOEX
#	define DETAIL_XIEITE_HEADER_TRAIT_IS_VAR_CRREF_NOEX
#
#	include "../trait/is_noex.hpp"
#	include "../trait/is_var_crref.hpp"

namespace xieite {
	template<typename T>
	concept is_var_crref_noex = xieite::is_var_crref<T> && xieite::is_noex<T>;
}

#endif
