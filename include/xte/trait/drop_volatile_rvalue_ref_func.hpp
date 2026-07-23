#ifndef DETAIL_XTE_HEADER_TRAIT_DROP_VOLATILE_RVALUE_REF_FUNC
#	define DETAIL_XTE_HEADER_TRAIT_DROP_VOLATILE_RVALUE_REF_FUNC
#
#	include "../trait/drop_rvalue_ref_func.hpp"
#	include "../trait/drop_volatile_func.hpp"

namespace xte {
	template<typename T>
	using drop_volatile_rvalue_ref_func = xte::drop_rvalue_ref_func<xte::drop_volatile_func<T>>;
}

#endif
