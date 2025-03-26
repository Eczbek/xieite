#ifndef DETAIL_XIEITE_HEADER_TRAIT_IS_CVLREF_REFERENT
#	define DETAIL_XIEITE_HEADER_TRAIT_IS_CVLREF_REFERENT
#
#	include "../trait/is_cv_referent.hpp"
#	include "../trait/is_lref_referent.hpp"

namespace xieite {
	template<typename T>
	concept is_cvlref_referent = xieite::is_cv_referent<T> && xieite::is_lref_referent<T>;
}

#endif
