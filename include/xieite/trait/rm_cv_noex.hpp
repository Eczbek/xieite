#ifndef DETAIL_XIEITE_HEADER_TRAIT_RM_CV_NOEX
#	define DETAIL_XIEITE_HEADER_TRAIT_RM_CV_NOEX
#
#	include "../trait/rm_cv_referent.hpp"
#	include "../trait/rm_noex.hpp"

namespace xieite {
	template<typename T>
	using rm_cv_noex = xieite::rm_cv_referent<xieite::rm_noex<T>>;
}

#endif
