#ifndef DETAIL_XTE_HEADER_TRAIT_IS_SIGNED
#	define DETAIL_XTE_HEADER_TRAIT_IS_SIGNED
#
#	include "../trait/is_same_drop_cv.hpp"
#	include <concepts>

namespace xte {
	template<typename T>
	concept is_signed = std::signed_integral<T> && !xte::is_same_drop_cv<T, bool>;
}

#endif
