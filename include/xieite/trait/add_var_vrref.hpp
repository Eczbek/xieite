#ifndef DETAIL_XIEITE_HEADER_TRAIT_ADD_VAR_VRREF
#	define DETAIL_XIEITE_HEADER_TRAIT_ADD_VAR_VRREF
#
#	include "../trait/add_rref_referent.hpp"
#	include "../trait/add_var_v.hpp"

namespace xieite {
	template<typename T>
	using add_var_vrref = xieite::add_var_v<xieite::add_rref_referent<T>>;
}

#endif
