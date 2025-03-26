#ifndef DETAIL_XIEITE_HEADER_TRAIT_SET_CV_NOEX
#	define DETAIL_XIEITE_HEADER_TRAIT_SET_CV_NOEX
#
#	include "../trait/set_cv_referent.hpp"
#	include "../trait/set_noex.hpp"

namespace xieite {
	template<bool qual, typename T>
	using set_cv_noex = xieite::set_cv_referent<qual, xieite::set_noex<qual, T>>;
}

#endif
