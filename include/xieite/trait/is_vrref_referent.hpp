#ifndef DETAIL_XIEITE_HEADER_TRAIT_IS_VRREF_REFERENT
#	define DETAIL_XIEITE_HEADER_TRAIT_IS_VRREF_REFERENT
#
#	include "../trait/is_rref_referent.hpp"
#	include "../trait/is_v_referent.hpp"

namespace xieite {
	template<typename T>
	concept is_vrref_referent = xieite::is_v_referent<T> && xieite::is_rref_referent<T>;
}

#endif
