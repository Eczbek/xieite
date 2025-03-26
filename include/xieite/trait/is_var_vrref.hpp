#ifndef DETAIL_XIEITE_HEADER_TRAIT_IS_VAR_VRREF
#	define DETAIL_XIEITE_HEADER_TRAIT_IS_VAR_VRREF
#
#	include "../trait/is_rref_referent.hpp"
#	include "../trait/is_var_v.hpp"

namespace xieite {
	template<typename T>
	concept is_var_vrref = xieite::is_var_v<T> && xieite::is_rref_referent<T>;
}

#endif
