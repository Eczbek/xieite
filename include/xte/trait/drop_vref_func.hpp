#ifndef DETAIL_XTE_HEADER_TRAIT_DROP_VREF_FUNC
#	define DETAIL_XTE_HEADER_TRAIT_DROP_VREF_FUNC
#
#	include "../trait/drop_ref_func.hpp"
#	include "../trait/drop_volatile_func.hpp"

namespace xte {
	template<typename T>
	using drop_vref_func = xte::drop_ref_func<xte::drop_volatile_func<T>>;
}

#endif
