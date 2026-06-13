#ifndef DETAIL_XTE_HEADER_TRAIT_IS_SIGNED
#	define DETAIL_XTE_HEADER_TRAIT_IS_SIGNED
#
#	include <concepts>

namespace xte {
	template<typename T>
	concept is_signed = std::signed_integral<T>;
}

#endif
