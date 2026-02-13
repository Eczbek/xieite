#ifndef DETAIL_XTE_HEADER_TRAIT_IS_REF
#	define DETAIL_XTE_HEADER_TRAIT_IS_REF
#
#	include "../trait/is_lref.hpp"
#	include "../trait/is_rref.hpp"

namespace xte {
	template<typename T>
	concept is_ref = xte::is_lref<T> || xte::is_rref<T>;
}

#endif
