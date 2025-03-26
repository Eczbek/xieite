#ifndef DETAIL_XIEITE_HEADER_TRAIT_RM_CRREF
#	define DETAIL_XIEITE_HEADER_TRAIT_RM_CRREF
#
#	include "../trait/rm_c.hpp"
#	include "../trait/rm_rref.hpp"

namespace xieite {
	template<typename T>
	using rm_crref = xieite::rm_c<xieite::rm_rref<T>>;
}

#endif
