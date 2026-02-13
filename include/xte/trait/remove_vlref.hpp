#ifndef DETAIL_XTE_HEADER_TRAIT_REMOVE_VLREF
#	define DETAIL_XTE_HEADER_TRAIT_REMOVE_VLREF
#
#	include "../trait/remove_lref.hpp"
#	include "../trait/remove_v.hpp"

namespace xte {
	template<typename T>
	using remove_vlref = xte::remove_lref<xte::remove_v<T>>;
}

#endif
