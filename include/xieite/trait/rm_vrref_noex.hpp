#ifndef DETAIL_XIEITE_HEADER_TRAIT_RM_VRREF_NOEX
#	define DETAIL_XIEITE_HEADER_TRAIT_RM_VRREF_NOEX
#
#	include "../trait/rm_noex.hpp"
#	include "../trait/rm_vrref_referent.hpp"

namespace xieite {
	template<typename T>
	using rm_vrref_noex = xieite::rm_vrref_referent<xieite::rm_noex<T>>;
}

#endif
