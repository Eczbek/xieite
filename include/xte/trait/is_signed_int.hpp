#ifndef DETAIL_XTE_HEADER_TRAIT_IS_SIGNED_INT
#	define DETAIL_XTE_HEADER_TRAIT_IS_SIGNED_INT
#
#	include <concepts>

namespace xte {
	template<typename T>
	concept is_signed_int = std::signed_integral<T>;
}

#endif
