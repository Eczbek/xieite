#ifndef DETAIL_XIEITE_HEADER_TRAIT_IS_VLREF_REFERENT
#	define DETAIL_XIEITE_HEADER_TRAIT_IS_VLREF_REFERENT
#
#	include "../trait/is_lref_referent.hpp"
#	include "../trait/is_v_referent.hpp"

namespace xieite {
	template<typename T>
	concept is_vlref_referent = xieite::is_v_referent<T> && xieite::is_lref_referent<T>;
}

#endif
