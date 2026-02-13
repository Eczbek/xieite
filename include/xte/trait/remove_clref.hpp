#ifndef DETAIL_XTE_HEADER_TRAIT_REMOVE_CLREF
#	define DETAIL_XTE_HEADER_TRAIT_REMOVE_CLREF
#
#	include "../trait/remove_c.hpp"
#	include "../trait/remove_lref.hpp"

namespace xte {
	template<typename T>
	using remove_clref = xte::remove_lref<xte::remove_c<T>>;
}

#endif
