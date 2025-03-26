#ifndef DETAIL_XIEITE_HEADER_TRAIT_IS_UNION
#	define DETAIL_XIEITE_HEADER_TRAIT_IS_UNION
#
#	include <type_traits>

namespace xieite {
	template<typename T>
	concept is_union = std::is_union_v<T>;
}

#endif
