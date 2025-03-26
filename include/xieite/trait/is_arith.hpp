#ifndef DETAIL_XIEITE_HEADER_TRAIT_IS_ARITH
#	define DETAIL_XIEITE_HEADER_TRAIT_IS_ARITH
#
#	include <concepts>

namespace xieite {
	template<typename T>
	concept is_arith = std::integral<T> || std::floating_point<T>;
}

#endif
