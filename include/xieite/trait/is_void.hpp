#ifndef DETAIL_XIEITE_HEADER_TRAIT_IS_VOID
#	define DETAIL_XIEITE_HEADER_TRAIT_IS_VOID
#
#	include <type_traits>

namespace xieite {
	template<typename T>
	concept is_void = std::is_void_v<T>;
}

#endif
