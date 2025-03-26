#ifndef DETAIL_XIEITE_HEADER_TRAIT_CP_VRREF
#	define DETAIL_XIEITE_HEADER_TRAIT_CP_VRREF
#
#	include "../trait/cp_v.hpp"
#	include "../trait/cp_rref.hpp"

namespace xieite {
	template<typename T, typename U>
	using cp_vrref = xieite::cp_v<T, xieite::cp_rref<T, U>>;
}

#endif
