#ifndef DETAIL_XIEITE_HEADER_TRAIT_RM_CVLREF_REFERENT
#	define DETAIL_XIEITE_HEADER_TRAIT_RM_CVLREF_REFERENT
#
#	include "../trait/rm_cv_referent.hpp"
#	include "../trait/rm_lref_referent.hpp"

namespace xieite {
	template<typename T>
	using rm_cvlref_referent = xieite::rm_cv_referent<xieite::rm_lref_referent<T>>;
}

#endif
