#ifndef DETAIL_XTE_HEADER_TRAIT_IS_CONST_RVALUE_REF_FUNC
#	define DETAIL_XTE_HEADER_TRAIT_IS_CONST_RVALUE_REF_FUNC
#
#	include "../trait/is_const_func.hpp"
#	include "../trait/is_rvalue_ref_func.hpp"

namespace xte {
	template<typename T>
	concept is_const_rvalue_ref_func = xte::is_const_func<T> && xte::is_rvalue_ref_func<T>;
}

#endif
