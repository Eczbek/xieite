#ifndef DETAIL_XIEITE_HEADER_TRAIT_CP_LREF_NOEX
#	define DETAIL_XIEITE_HEADER_TRAIT_CP_LREF_NOEX
#
#	include "../trait/set_lref_noex.hpp"
#	include "../trait/is_lref_noex.hpp"

namespace xieite {
	template<typename T, typename U>
	using cp_lref_noex = xieite::set_lref_noex<xieite::is_lref_noex<T>, U>;
}

#endif
