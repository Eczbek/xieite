#ifndef DETAIL_XIEITE_HEADER_TRAIT_RM_CVRREF
#	define DETAIL_XIEITE_HEADER_TRAIT_RM_CVRREF
#
#	include "../trait/rm_cv.hpp"
#	include "../trait/rm_rref.hpp"

namespace xieite {
	template<typename T>
	using rm_cvrref = xieite::rm_cv<xieite::rm_rref<T>>;
}

#endif
