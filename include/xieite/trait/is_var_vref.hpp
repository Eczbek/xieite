#ifndef DETAIL_XIEITE_HEADER_TRAIT_IS_VAR_VREF
#	define DETAIL_XIEITE_HEADER_TRAIT_IS_VAR_VREF
#
#	include "../trait/is_ref_referent.hpp"
#	include "../trait/is_var_v.hpp"

namespace xieite {
	template<typename T>
	concept is_var_vref = xieite::is_var_v<T> && xieite::is_ref_referent<T>;
}

#endif
