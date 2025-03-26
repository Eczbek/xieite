#ifndef DETAIL_XIEITE_HEADER_TRAIT_HAS_NOEX_CTOR
#	define DETAIL_XIEITE_HEADER_TRAIT_HAS_NOEX_CTOR
#
#	include <type_traits>

namespace xieite {
	template<typename T, typename... Args>
	concept has_noex_ctor = std::is_nothrow_constructible_v<T, Args...>;
}

#endif
