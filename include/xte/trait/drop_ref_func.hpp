#ifndef DETAIL_XTE_HEADER_TRAIT_DROP_REF_FUNC
#	define DETAIL_XTE_HEADER_TRAIT_DROP_REF_FUNC
#
#	include "../trait/drop_lvalue_ref_func.hpp"
#	include "../trait/drop_rvalue_ref_func.hpp"

namespace xte {
	template<typename T>
	using drop_ref_func = xte::drop_rvalue_ref_func<xte::drop_lvalue_ref_func<T>>;
}

#endif
