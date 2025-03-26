#ifndef DETAIL_XIEITE_HEADER_TRAIT_CP_CRREF
#	define DETAIL_XIEITE_HEADER_TRAIT_CP_CRREF
#
#	include "../trait/cp_c.hpp"
#	include "../trait/cp_rref.hpp"

namespace xieite {
	template<typename T, typename U>
	using cp_crref = xieite::cp_c<T, xieite::cp_rref<T, U>>;
}

#endif
