#ifndef DETAIL_XIEITE_HEADER_TRAIT_HAS_CTOR
#	define DETAIL_XIEITE_HEADER_TRAIT_HAS_CTOR
#
#	include <type_traits>

namespace xieite {
	template<typename T, typename... Args>
	concept has_ctor = std::is_constructible_v<T, Args...>;
}

#endif
