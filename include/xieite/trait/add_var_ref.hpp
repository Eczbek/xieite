#ifndef DETAIL_XIEITE_HEADER_TRAIT_ADD_VAR_REF
#	define DETAIL_XIEITE_HEADER_TRAIT_ADD_VAR_REF
#
#	include "../trait/add_ref_referent.hpp"
#	include "../trait/add_var.hpp"

namespace xieite {
	template<typename T, typename U>
	using add_var_ref = xieite::add_var<xieite::add_ref_referent<T, U>>;
}

#endif
