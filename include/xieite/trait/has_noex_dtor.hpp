#ifndef DETAIL_XIEITE_HEADER_TRAIT_HAS_NOEX_DTOR
#	define DETAIL_XIEITE_HEADER_TRAIT_HAS_NOEX_DTOR
#
#	include <type_traits>

namespace xieite {
	template<typename T>
	concept has_noex_dtor = std::is_nothrow_destructible_v<T>;
}

#endif
