#ifndef DETAIL_XTE_HEADER_TRAIT_IS_UNSIGNED
#	define DETAIL_XTE_HEADER_TRAIT_IS_UNSIGNED
#
#	include "../trait/is_same_drop_cv.hpp"
#	include <concepts>

namespace xte {
	template<typename T>
	concept is_unsigned = std::unsigned_integral<T> && !xte::is_same_drop_cv<T, bool>;
}

#endif
