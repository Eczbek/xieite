#ifndef DETAIL_XIEITE_HEADER_TRAIT_RM_VLREF_REFERENT
#	define DETAIL_XIEITE_HEADER_TRAIT_RM_VLREF_REFERENT
#
#	include "../trait/rm_lref_referent.hpp"
#	include "../trait/rm_v_referent.hpp"

namespace xieite {
	template<typename T>
	using rm_vlref_referent = xieite::rm_v_referent<xieite::rm_lref_referent<T>>;
}

#endif
