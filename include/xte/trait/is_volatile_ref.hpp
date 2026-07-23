#ifndef DETAIL_XTE_HEADER_TRAIT_IS_VOLATILE_REF
#	define DETAIL_XTE_HEADER_TRAIT_IS_VOLATILE_REF
#
#	include "../trait/is_ref.hpp"
#	include "../trait/is_volatile.hpp"

namespace xte {
	template<typename T>
	concept is_volatile_ref = xte::is_volatile<T> && xte::is_ref<T>;
}

#endif
