#ifndef DETAIL_XIEITE_HEADER_TRAIT_CP_VAR
#	define DETAIL_XIEITE_HEADER_TRAIT_CP_VAR
#
#	include "../trait/is_var.hpp"
#	include "../trait/set_var.hpp"

namespace xieite {
	template<typename T, typename U>
	using cp_var = xieite::set_var<xieite::is_var<T>, U>;
}

#endif
