#ifndef DETAIL_XIEITE_HEADER_TRAIT_ADD_REF
#	define DETAIL_XIEITE_HEADER_TRAIT_ADD_REF
#
#	include "../trait/cp_lref.hpp"
#	include "../trait/cp_rref.hpp"

namespace xieite {
	template<typename T, typename U>
	using add_ref = xieite::cp_lref<T, xieite::cp_rref<T, U>>;
}

#endif
