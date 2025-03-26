#ifndef DETAIL_XIEITE_HEADER_TRAIT_CP_VRREF_REFERENT
#	define DETAIL_XIEITE_HEADER_TRAIT_CP_VRREF_REFERENT
#
#	include "../trait/cp_v_referent.hpp"
#	include "../trait/cp_rref_referent.hpp"

namespace xieite {
	template<typename T, typename U>
	using cp_vrref_referent = xieite::cp_v_referent<T, xieite::cp_rref_referent<T, U>>;
}

#endif
