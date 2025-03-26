#ifndef DETAIL_XIEITE_HEADER_TRAIT_ADD_VAR_CREF
#	define DETAIL_XIEITE_HEADER_TRAIT_ADD_VAR_CREF
#
#	include "../trait/add_ref_referent.hpp"
#	include "../trait/add_var_c.hpp"

namespace xieite {
	template<typename T, typename U>
	using add_var_cref = xieite::add_var_c<xieite::add_ref_referent<T, U>>;
}

#endif
