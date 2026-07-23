#ifndef DETAIL_XTE_HEADER_TRAIT_IS_CONST_LVALUE_REF
#	define DETAIL_XTE_HEADER_TRAIT_IS_CONST_LVALUE_REF
#
#	include "../trait/is_const.hpp"
#	include "../trait/is_lvalue_ref.hpp"

namespace xte {
	template<typename T>
	concept is_const_lvalue_ref = xte::is_const<T> && xte::is_lvalue_ref<T>;
}

#endif
