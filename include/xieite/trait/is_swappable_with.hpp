#ifndef DETAIL_XIEITE_HEADER_TRAIT_IS_SWAPPABLE_WITH
#	define DETAIL_XIEITE_HEADER_TRAIT_IS_SWAPPABLE_WITH
#
#	include <type_traits>

namespace xieite {
	template<typename T, typename U>
	concept is_swappable_with = std::is_swappable_with_v<T, U>;
}

#endif
