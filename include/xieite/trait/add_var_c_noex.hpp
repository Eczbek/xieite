#ifndef DETAIL_XIEITE_HEADER_TRAIT_ADD_VAR_C_NOEX
#	define DETAIL_XIEITE_HEADER_TRAIT_ADD_VAR_C_NOEX
#
#	include "../trait/add_noex.hpp"
#	include "../trait/add_var_c.hpp"

namespace xieite {
	template<typename T>
	using add_var_c_noex = xieite::add_var_c<xieite::add_noex<T>>;
}

#endif
