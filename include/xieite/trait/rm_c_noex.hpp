#ifndef DETAIL_XIEITE_HEADER_TRAIT_RM_C_NOEX
#	define DETAIL_XIEITE_HEADER_TRAIT_RM_C_NOEX
#
#	include "../trait/rm_c_referent.hpp"
#	include "../trait/rm_noex.hpp"

namespace xieite {
	template<typename T>
	using rm_c_noex = xieite::rm_c_referent<xieite::rm_noex<T>>;
}

#endif
