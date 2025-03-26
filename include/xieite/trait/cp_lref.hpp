#ifndef DETAIL_XIEITE_HEADER_TRAIT_CP_LREF
#	define DETAIL_XIEITE_HEADER_TRAIT_CP_LREF
#
#	include "../trait/is_lref.hpp"
#	include "../trait/set_lref.hpp"

namespace xieite {
	template<typename T, typename U>
	using cp_lref = xieite::set_lref<xieite::is_lref<T>, U>;
}

#endif
