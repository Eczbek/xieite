#ifndef DETAIL_XIEITE_HEADER_TRAIT_RM_VLREF_NOEX
#	define DETAIL_XIEITE_HEADER_TRAIT_RM_VLREF_NOEX
#
#	include "../trait/rm_noex.hpp"
#	include "../trait/rm_vlref_referent.hpp"

namespace xieite {
	template<typename T>
	using rm_vlref_noex = xieite::rm_vlref_referent<xieite::rm_noex<T>>;
}

#endif
