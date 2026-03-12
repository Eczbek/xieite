#ifndef DETAIL_XTE_HEADER_TRAIT_IS_COPY_CONSTRUCTIBLE
#	define DETAIL_XTE_HEADER_TRAIT_IS_COPY_CONSTRUCTIBLE
#
#	include "../trait/add_lref.hpp"
#	include "../trait/is_constructible.hpp"

namespace xte {
	template<typename T>
	concept is_copy_constructible = xte::is_constructible<T, const T&>;
}

#endif
