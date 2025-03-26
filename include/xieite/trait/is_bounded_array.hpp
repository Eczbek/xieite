#ifndef DETAIL_XIEITE_HEADER_TRAIT_IS_BOUNDED_ARRAY
#	define DETAIL_XIEITE_HEADER_TRAIT_IS_BOUNDED_ARRAY
#
#	include <type_traits>

namespace xieite {
	template<typename T>
	concept is_bounded_array = std::is_bounded_array_v<T>;
}

#endif
