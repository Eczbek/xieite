#ifndef DETAIL_XIEITE_HEADER_TRAIT_IS_SWAPPABLE
#	define DETAIL_XIEITE_HEADER_TRAIT_IS_SWAPPABLE
#
#	include <type_traits>

namespace xieite {
	template<typename T>
	concept is_swappable = std::is_swappable_v<T>;
}

#endif
