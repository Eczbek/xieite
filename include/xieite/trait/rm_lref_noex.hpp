#ifndef DETAIL_XIEITE_HEADER_TRAIT_RM_LREF_NOEX
#	define DETAIL_XIEITE_HEADER_TRAIT_RM_LREF_NOEX
#
#	include "../trait/rm_lref_referent.hpp"
#	include "../trait/rm_noex.hpp"

namespace xieite {
	template<typename T>
	using rm_lref_noex = xieite::rm_lref_referent<xieite::rm_noex<T>>;
}

#endif
