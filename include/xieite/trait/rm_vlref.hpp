#ifndef DETAIL_XIEITE_HEADER_TRAIT_RM_VLREF
#	define DETAIL_XIEITE_HEADER_TRAIT_RM_VLREF
#
#	include "../trait/rm_lref.hpp"
#	include "../trait/rm_v.hpp"

namespace xieite {
	template<typename T>
	using rm_vlref = xieite::rm_v<xieite::rm_lref<T>>;
}

#endif
