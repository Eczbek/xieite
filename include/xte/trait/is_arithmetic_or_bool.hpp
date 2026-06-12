#ifndef DETAIL_XTE_HEADER_TRAIT_IS_ARITHMETIC_OR_BOOL
#	define DETAIL_XTE_HEADER_TRAIT_IS_ARITHMETIC_OR_BOOL
#
#	include "../trait/is_arithmetic.hpp"
#	include "../trait/is_same_ignore_cv.hpp"

namespace xte {
	template<typename T>
	concept is_arithmetic_or_bool = xte::is_arithmetic<T> || xte::is_same_ignore_cv<T, bool>;
}

#endif
