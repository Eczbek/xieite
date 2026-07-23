#ifndef DETAIL_XTE_HEADER_TRAIT_DROP_CONST_LVALUE_REF_FUNC
#	define DETAIL_XTE_HEADER_TRAIT_DROP_CONST_LVALUE_REF_FUNC
#
#	include "../trait/drop_const_func.hpp"
#	include "../trait/drop_lvalue_ref_func.hpp"

namespace xte {
	template<typename T>
	using drop_const_lvalue_ref_func = xte::drop_lvalue_ref_func<xte::drop_const_func<T>>;
}

#endif
