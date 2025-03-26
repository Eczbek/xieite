#ifndef DETAIL_XIEITE_HEADER_TRAIT_RM_CRREF_NOEX
#	define DETAIL_XIEITE_HEADER_TRAIT_RM_CRREF_NOEX
#
#	include "../trait/rm_crref_referent.hpp"
#	include "../trait/rm_noex.hpp"

namespace xieite {
	template<typename T>
	using rm_crref_noex = xieite::rm_crref_referent<xieite::rm_noex<T>>;
}

#endif
