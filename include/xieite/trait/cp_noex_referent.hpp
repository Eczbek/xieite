#ifndef DETAIL_XIEITE_HEADER_TRAIT_CP_NOEX_REFERENT
#	define DETAIL_XIEITE_HEADER_TRAIT_CP_NOEX_REFERENT
#
#	include "../trait/is_noex_referent.hpp"
#	include "../trait/set_noex_referent.hpp"

namespace xieite {
	template<typename T, typename U>
	using cp_noex_referent = xieite::set_noex_referent<xieite::is_noex_referent<T>, U>;
}

#endif
