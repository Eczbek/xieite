#ifndef DETAIL_XIEITE_HEADER_TRAIT_ADD_CVRREF_REFERENT
#	define DETAIL_XIEITE_HEADER_TRAIT_ADD_CVRREF_REFERENT
#
#	include "../trait/add_cv_referent.hpp"
#	include "../trait/add_rref_referent.hpp"

namespace xieite {
	template<typename T>
	using add_cvrref_referent = xieite::add_cv_referent<xieite::add_rref_referent<T>>;
}

#endif
