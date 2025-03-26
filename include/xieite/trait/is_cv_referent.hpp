#ifndef DETAIL_XIEITE_HEADER_TRAIT_IS_CV_REFERENT
#	define DETAIL_XIEITE_HEADER_TRAIT_IS_CV_REFERENT
#
#	include "../trait/is_c_referent.hpp"
#	include "../trait/is_v_referent.hpp"

namespace xieite {
	template<typename T>
	concept is_cv_referent = xieite::is_c_referent<T> && xieite::is_v_referent<T>;
}

#endif
