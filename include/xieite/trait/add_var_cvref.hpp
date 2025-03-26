#ifndef DETAIL_XIEITE_HEADER_TRAIT_ADD_VAR_CVREF
#	define DETAIL_XIEITE_HEADER_TRAIT_ADD_VAR_CVREF
#
#	include "../trait/add_ref_referent.hpp"
#	include "../trait/add_var_cv.hpp"

namespace xieite {
	template<typename T, typename U>
	using add_var_cvref = xieite::add_var_cv<xieite::add_ref_referent<T, U>>;
}

#endif
