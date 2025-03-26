#ifndef DETAIL_XIEITE_HEADER_TRAIT_RM_CVLREF
#	define DETAIL_XIEITE_HEADER_TRAIT_RM_CVLREF
#
#	include "../trait/rm_cv.hpp"
#	include "../trait/rm_lref.hpp"

namespace xieite {
	template<typename T>
	using rm_cvlref = xieite::rm_cv<xieite::rm_lref<T>>;
}

#endif
