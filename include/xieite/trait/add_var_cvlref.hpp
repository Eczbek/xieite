#ifndef DETAIL_XIEITE_HEADER_TRAIT_ADD_VAR_CVLREF
#	define DETAIL_XIEITE_HEADER_TRAIT_ADD_VAR_CVLREF
#
#	include "../trait/add_lref_referent.hpp"
#	include "../trait/add_var_cv.hpp"

namespace xieite {
	template<typename T>
	using add_var_cvlref = xieite::add_var_cv<xieite::add_lref_referent<T>>;
}

#endif
