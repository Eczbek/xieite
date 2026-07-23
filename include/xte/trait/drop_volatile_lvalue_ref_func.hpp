#ifndef DETAIL_XTE_HEADER_TRAIT_DROP_VOLATILE_LVALUE_REF_FUNC
#	define DETAIL_XTE_HEADER_TRAIT_DROP_VOLATILE_LVALUE_REF_FUNC
#
#	include "../trait/drop_lvalue_ref_func.hpp"
#	include "../trait/drop_volatile_func.hpp"

namespace xte {
	template<typename T>
	using drop_volatile_lvalue_ref_func = xte::drop_lvalue_ref_func<xte::drop_volatile_func<T>>;
}

#endif
