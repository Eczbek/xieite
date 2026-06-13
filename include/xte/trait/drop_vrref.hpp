#ifndef DETAIL_XTE_HEADER_TRAIT_DROP_VRREF
#	define DETAIL_XTE_HEADER_TRAIT_DROP_VRREF
#
#	include "../trait/drop_rref.hpp"
#	include "../trait/drop_v.hpp"

namespace xte {
	template<typename T>
	using drop_vrref = xte::drop_rref<xte::drop_v<T>>;
}

#endif
