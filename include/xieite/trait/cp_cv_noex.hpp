#ifndef DETAIL_XIEITE_HEADER_TRAIT_CP_CV_NOEX
#	define DETAIL_XIEITE_HEADER_TRAIT_CP_CV_NOEX
#
#	include "../trait/cp_cv_referent.hpp"
#	include "../trait/cp_noex.hpp"

namespace xieite {
	template<typename T, typename U>
	using cp_cv_noex = xieite::set_cv_referent<T, xieite::cp_noex<T, U>>;
}

#endif
