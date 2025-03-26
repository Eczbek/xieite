#ifndef DETAIL_XIEITE_HEADER_TRAIT_CP_RREF_REFERENT
#	define DETAIL_XIEITE_HEADER_TRAIT_CP_RREF_REFERENT
#
#	include "../trait/is_rref_referent.hpp"
#	include "../trait/set_rref_referent.hpp"

namespace xieite {
	template<typename T, typename U>
	using cp_rref_referent = xieite::set_rref_referent<xieite::is_rref_referent<T>, U>;
}

#endif
