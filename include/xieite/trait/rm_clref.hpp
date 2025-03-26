#ifndef DETAIL_XIEITE_HEADER_TRAIT_RM_CLREF
#	define DETAIL_XIEITE_HEADER_TRAIT_RM_CLREF
#
#	include "../trait/rm_c.hpp"
#	include "../trait/rm_lref.hpp"

namespace xieite {
	template<typename T>
	using rm_clref = xieite::rm_c<xieite::rm_lref<T>>;
}

#endif
