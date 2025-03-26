#ifndef DETAIL_XIEITE_HEADER_TRAIT_IS_CRREF_REFERENT
#	define DETAIL_XIEITE_HEADER_TRAIT_IS_CRREF_REFERENT
#
#	include "../trait/is_c_referent.hpp"
#	include "../trait/is_rref_referent.hpp"

namespace xieite {
	template<typename T>
	concept is_crref_referent = xieite::is_c_referent<T> && xieite::is_rref_referent<T>;
}

#endif
