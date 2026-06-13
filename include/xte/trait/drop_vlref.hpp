#ifndef DETAIL_XTE_HEADER_TRAIT_DROP_VLREF
#	define DETAIL_XTE_HEADER_TRAIT_DROP_VLREF
#
#	include "../trait/drop_lref.hpp"
#	include "../trait/drop_v.hpp"

namespace xte {
	template<typename T>
	using drop_vlref = xte::drop_lref<xte::drop_v<T>>;
}

#endif
