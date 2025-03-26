#ifndef DETAIL_XIEITE_HEADER_TRAIT_IS_CV_NOEX
#	define DETAIL_XIEITE_HEADER_TRAIT_IS_CV_NOEX
#
#	include "../trait/is_cv_referent.hpp"
#	include "../trait/is_m_fn_ptr.hpp"
#	include "../trait/is_noex.hpp"

namespace xieite {
	template<typename T>
	concept is_cv_noex = (!xieite::is_m_fn_ptr<T> || xieite::is_cv_referent<T>) && xieite::is_noex<T>;
}

#endif
