#ifndef DETAIL_XIEITE_HEADER_TRAIT_IS_VAR_CVLREF_NOEX
#	define DETAIL_XIEITE_HEADER_TRAIT_IS_VAR_CVLREF_NOEX
#
#	include "../trait/is_noex.hpp"
#	include "../trait/is_var_cvlref.hpp"

namespace xieite {
	template<typename T>
	concept is_var_cvlref_noex = xieite::is_var_cvlref<T> && xieite::is_noex<T>;
}

#endif
