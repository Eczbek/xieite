#ifndef DETAIL_XTE_HEADER_TRAIT_IS_NOEX_COPY_CTOR
#	define DETAIL_XTE_HEADER_TRAIT_IS_NOEX_COPY_CTOR
#
#	include "../trait/is_noex_ctor.hpp"

namespace xte {
	template<typename T>
	concept is_noex_copy_ctor = xte::is_noex_ctor<T, const T&>;
}

#endif
