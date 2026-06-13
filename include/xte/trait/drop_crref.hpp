#ifndef DETAIL_XTE_HEADER_TRAIT_DROP_CRREF
#	define DETAIL_XTE_HEADER_TRAIT_DROP_CRREF
#
#	include "../trait/drop_c.hpp"
#	include "../trait/drop_rref.hpp"

namespace xte {
	template<typename T>
	using drop_crref = xte::drop_rref<xte::drop_c<T>>;
}

#endif
