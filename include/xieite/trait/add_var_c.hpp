#ifndef DETAIL_XIEITE_HEADER_TRAIT_ADD_VAR_C
#	define DETAIL_XIEITE_HEADER_TRAIT_ADD_VAR_C
#
#	include "../trait/add_c_referent.hpp"
#	include "../trait/add_var.hpp"

namespace xieite {
	template<typename T>
	using add_var_c = xieite::add_var<xieite::add_c_referent<T>>;
}

#endif
