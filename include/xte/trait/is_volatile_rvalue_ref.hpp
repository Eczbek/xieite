#ifndef DETAIL_XTE_HEADER_TRAIT_IS_VOLATILE_RVALUE_REF
#	define DETAIL_XTE_HEADER_TRAIT_IS_VOLATILE_RVALUE_REF
#
#	include "../trait/is_rvalue_ref.hpp"
#	include "../trait/is_volatile.hpp"

namespace xte {
	template<typename T>
	concept is_volatile_rvalue_ref = xte::is_volatile<T> && xte::is_rvalue_ref<T>;
}

#endif
