#ifndef DETAIL_XIEITE_HEADER_TRAIT_ADD_CV_REFERENT
#	define DETAIL_XIEITE_HEADER_TRAIT_ADD_CV_REFERENT
#
#	include "../trait/add_c_referent.hpp"
#	include "../trait/add_v_referent.hpp"

namespace xieite {
	template<typename T>
	using add_cv_referent = xieite::add_c_referent<xieite::add_v_referent<T>>;
}

#endif
