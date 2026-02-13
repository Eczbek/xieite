#ifndef DETAIL_XTE_HEADER_TRAIT_IS_NOEX_COPY_ASSIGNABLE
#	define DETAIL_XTE_HEADER_TRAIT_IS_NOEX_COPY_ASSIGNABLE
#
#	include "../trait/is_noex_assignable.hpp"

namespace xte {
	template<typename T>
	concept is_noex_copy_assignable = xte::is_noex_assignable<T&, const T&>;
}

#endif
