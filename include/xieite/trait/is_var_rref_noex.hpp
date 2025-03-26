#ifndef DETAIL_XIEITE_HEADER_TRAIT_IS_VAR_RREF_NOEX
#	define DETAIL_XIEITE_HEADER_TRAIT_IS_VAR_RREF_NOEX
#
#	include "../trait/is_noex.hpp"
#	include "../trait/is_var_rref.hpp"

namespace xieite {
	template<typename T>
	concept is_var_rref_noex = xieite::is_var_rref<T> && xieite::is_noex<T>;
}

#endif
