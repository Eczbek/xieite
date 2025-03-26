#ifndef DETAIL_XIEITE_HEADER_TRAIT_IS_CREF_REFERENT
#	define DETAIL_XIEITE_HEADER_TRAIT_IS_CREF_REFERENT
#
#	include "../trait/is_clref_referent.hpp"
#	include "../trait/is_crref_referent.hpp"

namespace xieite {
	template<typename T>
	concept is_cref_referent = xieite::is_clref_referent<T> || xieite::is_crref_referent<T>;
}

#endif
