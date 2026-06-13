#ifndef DETAIL_XTE_HEADER_TRAIT_DROP_CVRREF
#	define DETAIL_XTE_HEADER_TRAIT_DROP_CVRREF
#
#	include "../trait/drop_cv.hpp"
#	include "../trait/drop_rref.hpp"

namespace xte {
	template<typename T>
	using drop_cvrref = xte::drop_rref<xte::drop_cv<T>>;
}

#endif
