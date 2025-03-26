#ifndef DETAIL_XIEITE_HEADER_TRAIT_IS_VAR_CVREF_NOEX
#	define DETAIL_XIEITE_HEADER_TRAIT_IS_VAR_CVREF_NOEX
#
#	include "../trait/is_noex.hpp"
#	include "../trait/is_var_cvref.hpp"

namespace xieite {
	template<typename T>
	concept is_var_cvref_noex = xieite::is_var_cvref<T> && xieite::is_noex<T>;
}

#endif
