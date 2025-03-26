#ifndef DETAIL_XIEITE_HEADER_TRAIT_SET_VAR_CVLREF
#	define DETAIL_XIEITE_HEADER_TRAIT_SET_VAR_CVLREF
#
#	include "../trait/set_lref_referent.hpp"
#	include "../trait/set_var_cv.hpp"

namespace xieite {
	template<bool qual, typename T>
	using set_var_cvlref = xieite::set_var_cv<qual, xieite::set_lref_referent<qual, T>>;
}

#endif
