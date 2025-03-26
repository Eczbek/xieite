#ifndef DETAIL_XIEITE_HEADER_TRAIT_IS_VAR_V
#	define DETAIL_XIEITE_HEADER_TRAIT_IS_VAR_V
#
#	include "../trait/is_v_referent.hpp"
#	include "../trait/is_var.hpp"

namespace xieite {
	template<typename T>
	concept is_var_v = xieite::is_var<T> && xieite::is_v_referent<T>;
}

#endif
