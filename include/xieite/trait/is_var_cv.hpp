#ifndef DETAIL_XIEITE_HEADER_TRAIT_IS_VAR_CV
#	define DETAIL_XIEITE_HEADER_TRAIT_IS_VAR_CV
#
#	include "../trait/is_v_referent.hpp"
#	include "../trait/is_var_c.hpp"

namespace xieite {
	template<typename T>
	concept is_var_cv = xieite::is_var_c<T> && xieite::is_v_referent<T>;
}

#endif
