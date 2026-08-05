#ifndef DETAIL_XTE_HEADER_TRAIT_IS_COPY_ASSIGNABLE_NOEX
#	define DETAIL_XTE_HEADER_TRAIT_IS_COPY_ASSIGNABLE_NOEX
#
#	include "../trait/is_assignable_noex.hpp"

namespace xte {
	template<typename T>
	concept is_copy_assignable_noex = xte::is_assignable_noex<T&, const T&>;
}

#endif
