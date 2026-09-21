#ifndef DETAIL_XTE_HEADER_TRAIT_IS_UNSIGNED_INT
#	define DETAIL_XTE_HEADER_TRAIT_IS_UNSIGNED_INT
#
#	include "../trait/is_same_drop_cv.hpp"
#	include <concepts>

namespace xte {
	template<typename T>
	concept is_unsigned_int = std::unsigned_integral<T> && !xte::is_same_drop_cv<T, bool>;
}

#endif
