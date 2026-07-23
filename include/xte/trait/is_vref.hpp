#ifndef DETAIL_XTE_HEADER_TRAIT_IS_VREF
#	define DETAIL_XTE_HEADER_TRAIT_IS_VREF
#
#	include "../trait/is_ref.hpp"
#	include "../trait/is_volatile.hpp"

namespace xte {
	template<typename T>
	concept is_vref = xte::is_volatile<T> && xte::is_ref<T>;
}

#endif
