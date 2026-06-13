#ifndef DETAIL_XTE_HEADER_TRAIT_DROP_CV
#	define DETAIL_XTE_HEADER_TRAIT_DROP_CV
#
#	include "../trait/drop_c.hpp"
#	include "../trait/drop_v.hpp"

namespace xte {
	template<typename T>
	using drop_cv = xte::drop_v<xte::drop_c<T>>;
}

#endif
