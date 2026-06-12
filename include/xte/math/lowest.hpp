#ifndef DETAIL_XTE_HEADER_MATH_LOWEST
#	define DETAIL_XTE_HEADER_MATH_LOWEST
#
#	include "../trait/is_arithmetic.hpp"
#	include <limits>

namespace xte {
	template<xte::is_arithmetic T>
	constexpr T lowest = std::numeric_limits<T>::lowest();
}

#endif
