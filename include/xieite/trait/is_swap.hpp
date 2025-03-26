#ifndef DETAIL_XIEITE_HEADER_TRAIT_IS_SWAP
#	define DETAIL_XIEITE_HEADER_TRAIT_IS_SWAP
#
#	include <type_traits>

namespace xieite {
	template<typename T>
	concept is_swap = std::is_swappable_v<T>;
}

#endif
