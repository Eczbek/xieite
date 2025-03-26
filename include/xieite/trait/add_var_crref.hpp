#ifndef DETAIL_XIEITE_HEADER_TRAIT_ADD_VAR_CRREF
#	define DETAIL_XIEITE_HEADER_TRAIT_ADD_VAR_CRREF
#
#	include "../trait/add_rref_referent.hpp"
#	include "../trait/add_var_c.hpp"

namespace xieite {
	template<typename T>
	using add_var_crref = xieite::add_var_c<xieite::add_rref_referent<T>>;
}

#endif
