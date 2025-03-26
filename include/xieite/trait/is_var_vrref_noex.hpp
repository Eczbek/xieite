#ifndef DETAIL_XIEITE_HEADER_TRAIT_IS_VAR_VRREF_NOEX
#	define DETAIL_XIEITE_HEADER_TRAIT_IS_VAR_VRREF_NOEX
#
#	include "../trait/is_noex.hpp"
#	include "../trait/is_var_vrref.hpp"

namespace xieite {
	template<typename T>
	concept is_var_vrref_noex = xieite::is_var_vrref<T> && xieite::is_noex<T>;
}

#endif
