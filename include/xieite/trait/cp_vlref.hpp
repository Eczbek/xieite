#ifndef DETAIL_XIEITE_HEADER_TRAIT_CP_VLREF
#	define DETAIL_XIEITE_HEADER_TRAIT_CP_VLREF
#
#	include "../trait/cp_v.hpp"
#	include "../trait/cp_lref.hpp"

namespace xieite {
	template<typename T, typename U>
	using cp_vlref = xieite::cp_v<T, xieite::cp_lref<T, U>>;
}

#endif
