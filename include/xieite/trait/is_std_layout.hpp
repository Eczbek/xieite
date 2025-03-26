#ifndef DETAIL_XIEITE_HEADER_TRAIT_IS_STD_LAYOUT
#	define DETAIL_XIEITE_HEADER_TRAIT_IS_STD_LAYOUT
#
#	include <type_traits>

namespace xieite {
	template<typename T>
	concept is_std_layout = std::is_standard_layout_v<T>;
}

#endif
