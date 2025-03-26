#ifndef DETAIL_XIEITE_HEADER_TRAIT_RM_VRREF_REFERENT
#	define DETAIL_XIEITE_HEADER_TRAIT_RM_VRREF_REFERENT
#
#	include "../trait/rm_rref_referent.hpp"
#	include "../trait/rm_v_referent.hpp"

namespace xieite {
	template<typename T>
	using rm_vrref_referent = xieite::rm_v_referent<xieite::rm_rref_referent<T>>;
}

#endif
