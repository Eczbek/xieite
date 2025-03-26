#ifndef DETAIL_XIEITE_HEADER_TRAIT_HAS_DTOR
#	define DETAIL_XIEITE_HEADER_TRAIT_HAS_DTOR
#
#	include <type_traits>

namespace xieite {
	template<typename T>
	concept has_dtor = std::is_destructible_v<T>;
}

#endif
