#ifndef DETAIL_XIEITE_HEADER_TRAIT_IS_EMPTY
#	define DETAIL_XIEITE_HEADER_TRAIT_IS_EMPTY
#
#	include <type_traits>

namespace xieite {
	template<typename T>
	concept is_empty = std::is_empty_v<T>;
}

#endif
