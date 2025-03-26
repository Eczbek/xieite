#ifndef DETAIL_XIEITE_HEADER_TRAIT_CP_CVLREF_REFERENT
#	define DETAIL_XIEITE_HEADER_TRAIT_CP_CVLREF_REFERENT
#
#	include "../trait/cp_cv_referent.hpp"
#	include "../trait/cp_lref_referent.hpp"

namespace xieite {
	template<typename T, typename U>
	using cp_cvlref_referent = xieite::cp_cv_referent<T, xieite::cp_lref_referent<T, U>>;
}

#endif
