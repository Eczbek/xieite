#ifndef DETAIL_XIEITE_HEADER_TRAIT_RM_VREF_REFERENT
#	define DETAIL_XIEITE_HEADER_TRAIT_RM_VREF_REFERENT
#
#	include "../trait/rm_ref_referent.hpp"
#	include "../trait/rm_v_referent.hpp"

namespace xieite {
	template<typename T>
	using rm_vref_referent = xieite::rm_v_referent<xieite::rm_ref_referent<T>>;
}

#endif
