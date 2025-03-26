#ifndef DETAIL_XIEITE_HEADER_TRAIT_IS_NOEX_SWAP
#	define DETAIL_XIEITE_HEADER_TRAIT_IS_NOEX_SWAP
#
#	include <type_traits>

namespace xieite {
	template<typename T>
	concept is_noex_swap = std::is_nothrow_swappable_v<T>;
}

#endif
