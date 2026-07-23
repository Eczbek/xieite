#ifndef DETAIL_XTE_HEADER_TRAIT_IS_VOLATILE_LVALUE_REF
#	define DETAIL_XTE_HEADER_TRAIT_IS_VOLATILE_LVALUE_REF
#
#	include "../trait/is_lvalue_ref.hpp"
#	include "../trait/is_volatile.hpp"

namespace xte {
	template<typename T>
	concept is_volatile_lvalue_ref = xte::is_volatile<T> && xte::is_lvalue_ref<T>;
}

#endif
