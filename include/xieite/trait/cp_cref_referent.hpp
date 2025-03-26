#ifndef DETAIL_XIEITE_HEADER_TRAIT_CP_CREF_REFERENT
#	define DETAIL_XIEITE_HEADER_TRAIT_CP_CREF_REFERENT
#
#	include "../trait/cp_c_referent.hpp"
#	include "../trait/cp_ref_referent.hpp"

namespace xieite {
	template<typename T, typename U>
	using cp_cref_referent = xieite::cp_c_referent<T, xieite::cp_ref_referent<T, U>>;
}

#endif
