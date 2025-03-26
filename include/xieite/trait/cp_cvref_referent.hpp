#ifndef DETAIL_XIEITE_HEADER_TRAIT_CP_CVREF_REFERENT
#	define DETAIL_XIEITE_HEADER_TRAIT_CP_CVREF_REFERENT
#
#	include "../trait/cp_cv_referent.hpp"
#	include "../trait/cp_ref_referent.hpp"

namespace xieite {
	template<typename T, typename U>
	using cp_cvref_referent = xieite::cp_cv_referent<T, xieite::cp_ref_referent<T, U>>;
}

#endif
