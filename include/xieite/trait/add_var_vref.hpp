#ifndef DETAIL_XIEITE_HEADER_TRAIT_ADD_VAR_VREF
#	define DETAIL_XIEITE_HEADER_TRAIT_ADD_VAR_VREF
#
#	include "../trait/add_ref_referent.hpp"
#	include "../trait/add_var_v.hpp"

namespace xieite {
	template<typename T, typename U>
	using add_var_vref = xieite::add_var_v<xieite::add_ref_referent<T, U>>;
}

#endif
