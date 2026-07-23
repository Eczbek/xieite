#ifndef DETAIL_XTE_HEADER_TRAIT_IS_VOLATILE_LVALUE_REF_FUNC
#	define DETAIL_XTE_HEADER_TRAIT_IS_VOLATILE_LVALUE_REF_FUNC
#
#	include "../trait/is_lvalue_ref_func.hpp"
#	include "../trait/is_volatile_func.hpp"

namespace xte {
	template<typename T>
	concept is_volatile_lvalue_ref_func = xte::is_volatile_func<T> && xte::is_lvalue_ref_func<T>;
}

#endif
