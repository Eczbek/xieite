#ifndef DETAIL_XIEITE_HEADER_TRAIT_IS_FUNDAMENTAL
#	define DETAIL_XIEITE_HEADER_TRAIT_IS_FUNDAMENTAL
#
#	include <type_traits>

namespace xieite {
	template<typename T>
	concept is_fundamental = std::is_fundamental_v<T>;
}

#endif
