#ifndef DETAIL_XIEITE_HEADER_TRAIT_IS_VAR_REF
#	define DETAIL_XIEITE_HEADER_TRAIT_IS_VAR_REF
#
#	include "../trait/is_ref_referent.hpp"
#	include "../trait/is_var.hpp"

namespace xieite {
	template<typename T>
	concept is_var_ref = xieite::is_var<T> && xieite::is_ref_referent<T>;
}

#endif
