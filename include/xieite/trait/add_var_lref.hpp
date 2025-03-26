#ifndef DETAIL_XIEITE_HEADER_TRAIT_ADD_VAR_LREF
#	define DETAIL_XIEITE_HEADER_TRAIT_ADD_VAR_LREF
#
#	include "../trait/add_lref_referent.hpp"
#	include "../trait/add_var.hpp"

namespace xieite {
	template<typename T>
	using add_var_lref = xieite::add_var<xieite::add_lref_referent<T>>;
}

#endif
