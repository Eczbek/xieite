#ifndef DETAIL_XIEITE_HEADER_TRAIT_IS_NULLPTR
#	define DETAIL_XIEITE_HEADER_TRAIT_IS_NULLPTR
#
#	include <type_traits>

namespace xieite {
	template<typename T>
	concept is_nullptr = std::is_null_pointer_v<T>;
}

#endif
