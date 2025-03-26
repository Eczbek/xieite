#ifndef DETAIL_XIEITE_HEADER_TRAIT_RM_CV_REFERENT
#	define DETAIL_XIEITE_HEADER_TRAIT_RM_CV_REFERENT
#
#	include "../trait/rm_c_referent.hpp"
#	include "../trait/rm_v_referent.hpp"

namespace xieite {
	template<typename T>
	using rm_cv_referent = xieite::rm_c_referent<xieite::rm_v_referent<T>>;
}

#endif
