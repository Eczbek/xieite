#ifndef DETAIL_XIEITE_HEADER_TRAIT_RM_CV
#	define DETAIL_XIEITE_HEADER_TRAIT_RM_CV
#
#	include "../trait/rm_c.hpp"
#	include "../trait/rm_v.hpp"

namespace xieite {
	template<typename T>
	using rm_cv = xieite::rm_c<xieite::rm_v<T>>;
}

#endif
