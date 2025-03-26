#ifndef DETAIL_XIEITE_HEADER_TRAIT_IS_VAR_C_NOEX
#	define DETAIL_XIEITE_HEADER_TRAIT_IS_VAR_C_NOEX
#
#	include "../trait/is_noex.hpp"
#	include "../trait/is_var_c.hpp"

namespace xieite {
	template<typename T>
	concept is_var_c_noex = xieite::is_var_c<T> && xieite::is_noex<T>;
}

#endif
