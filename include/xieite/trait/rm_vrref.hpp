#ifndef DETAIL_XIEITE_HEADER_TRAIT_RM_VRREF
#	define DETAIL_XIEITE_HEADER_TRAIT_RM_VRREF
#
#	include "../trait/rm_rref.hpp"
#	include "../trait/rm_v.hpp"

namespace xieite {
	template<typename T>
	using rm_vrref = xieite::rm_v<xieite::rm_rref<T>>;
}

#endif
