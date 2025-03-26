#ifndef DETAIL_XIEITE_HEADER_TRAIT_CP_CLREF
#	define DETAIL_XIEITE_HEADER_TRAIT_CP_CLREF
#
#	include "../trait/cp_c.hpp"
#	include "../trait/cp_lref.hpp"

namespace xieite {
	template<typename T, typename U>
	using cp_clref = xieite::cp_c<T, xieite::cp_lref<T, U>>;
}

#endif
