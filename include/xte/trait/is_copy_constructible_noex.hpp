#ifndef DETAIL_XTE_HEADER_TRAIT_IS_COPY_CONSTRUCTIBLE_NOEX
#	define DETAIL_XTE_HEADER_TRAIT_IS_COPY_CONSTRUCTIBLE_NOEX
#
#	include "../trait/is_constructible_noex.hpp"

namespace xte {
	template<typename T>
	concept is_copy_constructible_noex = xte::is_constructible_noex<T, const T&>;
}

#endif
