#ifndef DETAIL_XIEITE_HEADER_TRAIT_SET_VAR_CVRREF
#	define DETAIL_XIEITE_HEADER_TRAIT_SET_VAR_CVRREF
#
#	include "../trait/set_rref_referent.hpp"
#	include "../trait/set_var_cv.hpp"

namespace xieite {
	template<bool qual, typename T>
	using set_var_cvrref = xieite::set_var_cv<qual, xieite::set_rref_referent<qual, T>>;
}

#endif
