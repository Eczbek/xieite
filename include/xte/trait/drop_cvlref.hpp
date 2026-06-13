#ifndef DETAIL_XTE_HEADER_TRAIT_DROP_CVLREF
#	define DETAIL_XTE_HEADER_TRAIT_DROP_CVLREF
#
#	include "../trait/drop_cv.hpp"
#	include "../trait/drop_lref.hpp"

namespace xte {
	template<typename T>
	using drop_cvlref = xte::drop_lref<xte::drop_cv<T>>;
}

#endif
