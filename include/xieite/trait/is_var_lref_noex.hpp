#ifndef DETAIL_XIEITE_HEADER_TRAIT_IS_VAR_LREF_NOEX
#	define DETAIL_XIEITE_HEADER_TRAIT_IS_VAR_LREF_NOEX
#
#	include "../trait/is_noex.hpp"
#	include "../trait/is_var_lref.hpp"

namespace xieite {
	template<typename T>
	concept is_var_lref_noex = xieite::is_var_lref<T> && xieite::is_noex<T>;
}

#endif
