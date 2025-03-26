#ifndef DETAIL_XIEITE_HEADER_TRAIT_CP_VREF_REFERENT
#	define DETAIL_XIEITE_HEADER_TRAIT_CP_VREF_REFERENT
#
#	include "../trait/cp_v_referent.hpp"
#	include "../trait/cp_ref_referent.hpp"

namespace xieite {
	template<typename T, typename U>
	using cp_vref_referent = xieite::cp_v_referent<T, xieite::cp_ref_referent<T, U>>;
}

#endif
