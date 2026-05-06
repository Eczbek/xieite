#ifndef DETAIL_XTE_HEADER_MATH_LOWEST
#	define DETAIL_XTE_HEADER_MATH_LOWEST
#
#	include "../trait/is_number.hpp"
#	include <limits>

namespace xte {
	template<xte::is_number T>
	constexpr T lowest = std::numeric_limits<T>::lowest();
}

#endif
