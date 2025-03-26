#ifndef DETAIL_XIEITE_HEADER_TRAIT_IS_REF
#	define DETAIL_XIEITE_HEADER_TRAIT_IS_REF
#
#	include "../trait/is_lref.hpp"
#	include "../trait/is_rref.hpp"

namespace xieite {
	template<typename T>
	concept is_ref = xieite::is_lref<T> || xieite::is_rref<T>;
}

#endif
