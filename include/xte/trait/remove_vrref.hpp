#ifndef DETAIL_XTE_HEADER_TRAIT_REMOVE_VRREF
#	define DETAIL_XTE_HEADER_TRAIT_REMOVE_VRREF
#
#	include "../trait/remove_rref.hpp"
#	include "../trait/remove_v.hpp"

namespace xte {
	template<typename T>
	using remove_vrref = xte::remove_rref<xte::remove_v<T>>;
}

#endif
