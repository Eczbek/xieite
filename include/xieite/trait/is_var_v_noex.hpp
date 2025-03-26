#ifndef DETAIL_XIEITE_HEADER_TRAIT_IS_VAR_V_NOEX
#	define DETAIL_XIEITE_HEADER_TRAIT_IS_VAR_V_NOEX
#
#	include "../trait/is_noex.hpp"
#	include "../trait/is_var_v.hpp"

namespace xieite {
	template<typename T>
	concept is_var_v_noex = xieite::is_var_v<T> && xieite::is_noex<T>;
}

#endif
