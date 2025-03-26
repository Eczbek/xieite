#ifndef DETAIL_XIEITE_HEADER_TRAIT_SET_CVRREF_REFERENT
#	define DETAIL_XIEITE_HEADER_TRAIT_SET_CVRREF_REFERENT
#
#	include "../trait/set_cv_referent.hpp"
#	include "../trait/set_rref_referent.hpp"

namespace xieite {
	template<bool qual, typename T>
	using set_cvrref_referent = xieite::set_cv_referent<qual, xieite::set_rref_referent<qual, T>>;
}

#endif
