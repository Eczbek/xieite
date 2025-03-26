#ifndef DETAIL_XIEITE_HEADER_TRAIT_IS_VAR_VLREF
#	define DETAIL_XIEITE_HEADER_TRAIT_IS_VAR_VLREF
#
#	include "../trait/is_lref_referent.hpp"
#	include "../trait/is_var_v.hpp"

namespace xieite {
	template<typename T>
	concept is_var_vlref = xieite::is_var_v<T> && xieite::is_lref_referent<T>;
}

#endif
