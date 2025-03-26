#ifndef DETAIL_XIEITE_HEADER_TRAIT_IS_VAR_CREF_NOEX
#	define DETAIL_XIEITE_HEADER_TRAIT_IS_VAR_CREF_NOEX
#
#	include "../trait/is_noex.hpp"
#	include "../trait/is_var_cref.hpp"

namespace xieite {
	template<typename T>
	concept is_var_cref_noex = xieite::is_var_cref<T> && xieite::is_noex<T>;
}

#endif
