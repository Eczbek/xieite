#ifndef DETAIL_XTE_HEADER_TRAIT_IS_CV
#	define DETAIL_XTE_HEADER_TRAIT_IS_CV
#
#	include "../trait/is_const.hpp"
#	include "../trait/is_volatile.hpp"

namespace xte {
	template<typename T>
	concept is_cv = xte::is_const<T> && xte::is_volatile<T>;
}

#endif
