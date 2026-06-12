#ifndef DETAIL_XTE_HEADER_MATH_HIGHEST
#	define DETAIL_XTE_HEADER_MATH_HIGHEST
#
#	include "../trait/is_arithmetic.hpp"
#	include <limits>

namespace xte {
	template<xte::is_arithmetic T>
	constexpr T highest = std::numeric_limits<T>::max();
}

#endif
