#ifndef DETAIL_XIEITE_HEADER_TRAIT_IS_CLREF
#	define DETAIL_XIEITE_HEADER_TRAIT_IS_CLREF
#
#	include "../trait/is_c.hpp"
#	include "../trait/is_lref.hpp"

namespace xieite {
	template<typename T>
	concept is_clref = xieite::is_c<T> && xieite::is_lref<T>;
}

#endif
