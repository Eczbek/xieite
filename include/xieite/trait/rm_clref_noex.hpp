#ifndef DETAIL_XIEITE_HEADER_TRAIT_RM_CLREF_NOEX
#	define DETAIL_XIEITE_HEADER_TRAIT_RM_CLREF_NOEX
#
#	include "../trait/rm_clref_referent.hpp"
#	include "../trait/rm_noex.hpp"

namespace xieite {
	template<typename T>
	using rm_clref_noex = xieite::rm_clref_referent<xieite::rm_noex<T>>;
}

#endif
