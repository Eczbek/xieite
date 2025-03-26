#ifndef DETAIL_XIEITE_HEADER_TRAIT_RM_CVRREF_REFERENT
#	define DETAIL_XIEITE_HEADER_TRAIT_RM_CVRREF_REFERENT
#
#	include "../trait/rm_cv_referent.hpp"
#	include "../trait/rm_rref_referent.hpp"

namespace xieite {
	template<typename T>
	using rm_cvrref_referent = xieite::rm_cv_referent<xieite::rm_rref_referent<T>>;
}

#endif
