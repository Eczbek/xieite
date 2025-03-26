#ifndef DETAIL_XIEITE_HEADER_TRAIT_ADD_VAR_RREF
#	define DETAIL_XIEITE_HEADER_TRAIT_ADD_VAR_RREF
#
#	include "../trait/add_rref_referent.hpp"
#	include "../trait/add_var.hpp"

namespace xieite {
	template<typename T>
	using add_var_rref = xieite::add_var<xieite::add_rref_referent<T>>;
}

#endif
