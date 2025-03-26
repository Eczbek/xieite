#ifndef DETAIL_XIEITE_HEADER_TRAIT_RM_RREF_NOEX
#	define DETAIL_XIEITE_HEADER_TRAIT_RM_RREF_NOEX
#
#	include "../trait/rm_rref_referent.hpp"
#	include "../trait/rm_noex.hpp"

namespace xieite {
	template<typename T>
	using rm_rref_noex = xieite::rm_rref_referent<xieite::rm_noex<T>>;
}

#endif
