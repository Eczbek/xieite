#ifndef DETAIL_XIEITE_HEADER_TRAIT_IS_VAR_CLREF_NOEX
#	define DETAIL_XIEITE_HEADER_TRAIT_IS_VAR_CLREF_NOEX
#
#	include "../trait/is_noex.hpp"
#	include "../trait/is_var_clref.hpp"

namespace xieite {
	template<typename T>
	concept is_var_clref_noex = xieite::is_var_clref<T> && xieite::is_noex<T>;
}

#endif
