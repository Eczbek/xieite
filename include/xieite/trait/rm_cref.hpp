#ifndef DETAIL_XIEITE_HEADER_TRAIT_RM_CREF
#	define DETAIL_XIEITE_HEADER_TRAIT_RM_CREF
#
#	include "../trait/rm_c.hpp"
#	include "../trait/rm_ref.hpp"

namespace xieite {
	template<typename T>
	using rm_cref = xieite::rm_c<xieite::rm_ref<T>>;
}

#endif
