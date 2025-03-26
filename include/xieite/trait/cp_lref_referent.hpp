#ifndef DETAIL_XIEITE_HEADER_TRAIT_CP_LREF_REFERENT
#	define DETAIL_XIEITE_HEADER_TRAIT_CP_LREF_REFERENT
#
#	include "../trait/is_lref_referent.hpp"
#	include "../trait/set_lref_referent.hpp"

namespace xieite {
	template<typename T, typename U>
	using cp_lref_referent = xieite::set_lref_referent<xieite::is_lref_referent<T>, U>;
}

#endif
