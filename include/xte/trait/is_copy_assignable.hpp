#ifndef DETAIL_XTE_HEADER_TRAITS_IS_COPY_ASSIGNABLE
#	define DETAIL_XTE_HEADER_TRAITS_IS_COPY_ASSIGNABLE
#
#	include "../trait/is_assignable.hpp"

namespace xte {
	template<typename T>
	concept is_copy_assignable = xte::is_assignable<T, const T&>;
}

#endif
