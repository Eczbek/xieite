#ifndef DETAIL_XIEITE_HEADER_TRAIT_IS_VAR_CVRREF_NOEX
#	define DETAIL_XIEITE_HEADER_TRAIT_IS_VAR_CVRREF_NOEX
#
#	include "../trait/is_noex.hpp"
#	include "../trait/is_var_cvrref.hpp"

namespace xieite {
	template<typename T>
	concept is_var_cvrref_noex = xieite::is_var_cvrref<T> && xieite::is_noex<T>;
}

#endif
