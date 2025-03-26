#ifndef DETAIL_XIEITE_HEADER_TRAIT_RM_CREF_NOEX
#	define DETAIL_XIEITE_HEADER_TRAIT_RM_CREF_NOEX
#
#	include "../trait/rm_cref_referent.hpp"
#	include "../trait/rm_noex.hpp"

namespace xieite {
	template<typename T>
	using rm_cref_noex = xieite::rm_cref_referent<xieite::rm_noex<T>>;
}

#endif
