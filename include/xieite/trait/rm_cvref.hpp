#ifndef DETAIL_XIEITE_HEADER_TRAIT_RM_CVREF
#	define DETAIL_XIEITE_HEADER_TRAIT_RM_CVREF
#
#	include "../trait/rm_cv.hpp"
#	include "../trait/rm_ref.hpp"

namespace xieite {
	template<typename T>
	using rm_cvref = xieite::rm_cv<xieite::rm_ref<T>>;
}

#endif
