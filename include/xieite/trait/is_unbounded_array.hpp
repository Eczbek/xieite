#ifndef DETAIL_XIEITE_HEADER_TRAIT_IS_UNBOUNDED_ARRAY
#	define DETAIL_XIEITE_HEADER_TRAIT_IS_UNBOUNDED_ARRAY
#
#	include <type_traits>

namespace xieite {
	template<typename T>
	concept is_unbounded_array = std::is_unbounded_array_v<T>;
}

#endif
