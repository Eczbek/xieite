#ifndef DETAIL_XTE_HEADER_TRAIT_DROP_CLREF
#	define DETAIL_XTE_HEADER_TRAIT_DROP_CLREF
#
#	include "../trait/drop_c.hpp"
#	include "../trait/drop_lref.hpp"

namespace xte {
	template<typename T>
	using drop_clref = xte::drop_lref<xte::drop_c<T>>;
}

#endif
