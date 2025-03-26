#ifndef DETAIL_XIEITE_HEADER_TRAIT_CP_CVLREF_NOEX
#	define DETAIL_XIEITE_HEADER_TRAIT_CP_CVLREF_NOEX
#
#	include "../trait/cp_cvlref_referent.hpp"
#	include "../trait/cp_noex.hpp"

namespace xieite {
	template<typename T, typename U>
	using cp_cvlref_noex = xieite::set_cvlref_referent<T, xieite::cp_noex<T, U>>;
}

#endif
