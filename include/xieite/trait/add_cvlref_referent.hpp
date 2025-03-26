#ifndef DETAIL_XIEITE_HEADER_TRAIT_ADD_CVLREF_REFERENT
#	define DETAIL_XIEITE_HEADER_TRAIT_ADD_CVLREF_REFERENT
#
#	include "../trait/add_cv_referent.hpp"
#	include "../trait/add_lref_referent.hpp"

namespace xieite {
	template<typename T>
	using add_cvlref_referent = xieite::add_cv_referent<xieite::add_lref_referent<T>>;
}

#endif
