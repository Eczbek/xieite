#ifndef DETAIL_XIEITE_HEADER_TRAIT_ADD_CVREF_REFERENT
#	define DETAIL_XIEITE_HEADER_TRAIT_ADD_CVREF_REFERENT
#
#	include "../trait/add_cv_referent.hpp"
#	include "../trait/add_ref_referent.hpp"

namespace xieite {
	template<typename T, typename U>
	using add_cvref_referent = xieite::add_cv_referent<xieite::add_ref_referent<T, U>>;
}

#endif
