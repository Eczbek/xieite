#ifndef DETAIL_XIEITE_HEADER_TRAIT_CP_CREF
#	define DETAIL_XIEITE_HEADER_TRAIT_CP_CREF
#
#	include "../trait/cp_c.hpp"
#	include "../trait/cp_ref.hpp"

namespace xieite {
	template<typename T, typename U>
	using cp_cref = xieite::cp_c<T, xieite::cp_ref<T, U>>;
}

#endif
