#ifndef DETAIL_XIEITE_HEADER_TRAIT_CP_RREF
#	define DETAIL_XIEITE_HEADER_TRAIT_CP_RREF
#
#	include "../trait/is_rref.hpp"
#	include "../trait/set_rref.hpp"

namespace xieite {
	template<typename T, typename U>
	using cp_rref = xieite::set_rref<xieite::is_rref<T>, U>;
}

#endif
