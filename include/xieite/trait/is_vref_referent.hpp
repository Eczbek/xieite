#ifndef DETAIL_XIEITE_HEADER_TRAIT_IS_VREF_REFERENT
#	define DETAIL_XIEITE_HEADER_TRAIT_IS_VREF_REFERENT
#
#	include "../trait/is_ref_referent.hpp"
#	include "../trait/is_v_referent.hpp"

namespace xieite {
	template<typename T>
	concept is_vref_referent = xieite::is_v_referent<T> && xieite::is_ref_referent<T>;
}

#endif
