#ifndef DETAIL_XIEITE_HEADER_TRAIT_IS_CLREF_REFERENT
#	define DETAIL_XIEITE_HEADER_TRAIT_IS_CLREF_REFERENT
#
#	include "../trait/is_c_referent.hpp"
#	include "../trait/is_lref_referent.hpp"

namespace xieite {
	template<typename T>
	concept is_clref_referent = xieite::is_c_referent<T> && xieite::is_lref_referent<T>;
}

#endif
