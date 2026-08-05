#ifndef DETAIL_XTE_HEADER_TRAIT_IS_DESTRUCTIBLE_NOEX
#	define DETAIL_XTE_HEADER_TRAIT_IS_DESTRUCTIBLE_NOEX
#
#	include <type_traits>

namespace xte {
	template<typename T>
	concept is_destructible_noex = std::is_nothrow_destructible_v<T>;
}

#endif
