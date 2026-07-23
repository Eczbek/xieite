#ifndef DETAIL_XTE_HEADER_TRAIT_IS_VREF_FUNC
#	define DETAIL_XTE_HEADER_TRAIT_IS_VREF_FUNC
#
#	include "../trait/is_ref_func.hpp"
#	include "../trait/is_volatile_func.hpp"

namespace xte {
	template<typename T>
	concept is_vref_func = xte::is_volatile_func<T> && xte::is_ref_func<T>;
}

#endif
