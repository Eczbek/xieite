#ifndef DETAIL_XIEITE_HEADER_TRAIT_IS_ARRAY
#	define DETAIL_XIEITE_HEADER_TRAIT_IS_ARRAY
#
#	include <type_traits>

namespace xieite {
	template<typename T>
	concept is_array = std::is_array_v<T>;
}

#endif
