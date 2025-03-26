#ifndef DETAIL_XIEITE_HEADER_TRAIT_IS_CREF
#	define DETAIL_XIEITE_HEADER_TRAIT_IS_CREF
#
#	include "../trait/is_clref.hpp"
#	include "../trait/is_crref.hpp"

namespace xieite {
	template<typename T>
	concept is_cref = xieite::is_clref<T> || xieite::is_crref<T>;
}

#endif
