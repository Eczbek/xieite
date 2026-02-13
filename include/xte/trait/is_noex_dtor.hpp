#ifndef DETAIL_XTE_HEADER_TRAIT_IS_NOEX_DTOR
#	define DETAIL_XTE_HEADER_TRAIT_IS_NOEX_DTOR
#
#	include <type_traits>

namespace xte {
	template<typename T>
	concept is_noex_dtor = std::is_nothrow_destructible_v<T>;
}

#endif
