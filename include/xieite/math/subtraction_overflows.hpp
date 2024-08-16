#ifndef XIEITE_HEADER_MATH_SUBTRACTION_OVERFLOWS
#	define XIEITE_HEADER_MATH_SUBTRACTION_OVERFLOWS

#	include <limits>
#	include "../concepts/arithmetic.hpp"

namespace xieite::math {
	template<xieite::concepts::Arithmetic Arithmetic>
	[[nodiscard]] constexpr bool subtractionOverflows(const Arithmetic minuend, const Arithmetic subtrahend) noexcept {
		return minuend && subtrahend && ((subtrahend >= 0) ? ((std::numeric_limits<Arithmetic>::min() + subtrahend) > minuend) : ((std::numeric_limits<Arithmetic>::max() + subtrahend) < minuend));
	}
}

#endif
