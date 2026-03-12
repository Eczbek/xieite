#ifndef DETAIL_XTE_HEADER_TRAIT_IS_NOEX_COPY_CONSTRUCTIBLE
#	define DETAIL_XTE_HEADER_TRAIT_IS_NOEX_COPY_CONSTRUCTIBLE
#
#	include "../trait/is_noex_constructible.hpp"

namespace xte {
	template<typename T>
	concept is_noex_copy_constructible = xte::is_noex_constructible<T, const T&>;
}

#endif
