#ifndef DETAIL_XTE_HEADER_TRAIT_DROP_CREF_FUNC
#	define DETAIL_XTE_HEADER_TRAIT_DROP_CREF_FUNC
#
#	include "../trait/drop_const_func.hpp"
#	include "../trait/drop_ref_func.hpp"

namespace xte {
	template<typename T>
	using drop_cref_func = xte::drop_ref_func<xte::drop_const_func<T>>;
}

#endif
