#ifndef DETAIL_XIEITE_HEADER_TRAIT_ADD_VAR_CVRREF
#	define DETAIL_XIEITE_HEADER_TRAIT_ADD_VAR_CVRREF
#
#	include "../trait/add_rref_referent.hpp"
#	include "../trait/add_var_cv.hpp"

namespace xieite {
	template<typename T>
	using add_var_cvrref = xieite::add_var_cv<xieite::add_rref_referent<T>>;
}

#endif
