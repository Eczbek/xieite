#ifndef DETAIL_XIEITE_HEADER_TRAIT_IS_VAR_CVLREF
#	define DETAIL_XIEITE_HEADER_TRAIT_IS_VAR_CVLREF
#
#	include "../trait/is_lref_referent.hpp"
#	include "../trait/is_var_cv.hpp"

namespace xieite {
	template<typename T>
	concept is_var_cvlref = xieite::is_var_cv<T> && xieite::is_lref_referent<T>;
}

#endif
