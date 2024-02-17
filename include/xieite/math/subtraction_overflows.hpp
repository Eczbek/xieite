#ifndef XIEITE_HEADER_MATH_SUBTRACTION_OVERFLOWS
#	define XIEITE_HEADER_MATH_SUBTRACTION_OVERFLOWS

#	include <limits>
#	include "../concepts/arithmetic.hpp"

namespace xieite::math {
	template<xieite::concepts::Arithmetic Number>
	[[nodiscard]] constexpr bool subtractionOverflows(const Number minuend, const Number subtrahend) noexcept {
		return minuend && subtrahend && ((subtrahend >= 0) ? ((std::numeric_limits<Number>::min() + subtrahend) > minuend) : ((std::numeric_limits<Number>::max() + subtrahend) < minuend));
	}
}

#endif
