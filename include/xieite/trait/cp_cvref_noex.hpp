#ifndef DETAIL_XIEITE_HEADER_TRAIT_CP_CVREF_NOEX
#	define DETAIL_XIEITE_HEADER_TRAIT_CP_CVREF_NOEX
#
#	include "../trait/cp_cvref_referent.hpp"
#	include "../trait/cp_noex.hpp"

namespace xieite {
	template<typename T, typename U>
	using cp_cvref_noex = xieite::set_cvref_referent<T, xieite::cp_noex<T, U>>;
}

#endif
