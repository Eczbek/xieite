#ifndef XIEITE_HEADER_MATH_SUBTRACTION_OVERFLOWS
#	define XIEITE_HEADER_MATH_SUBTRACTION_OVERFLOWS

#	include <limits>
#	include "../concepts/arithmetic.hpp"

namespace xieite::math {
	template<xieite::concepts::Arithmetic Arithmetic_>
	[[nodiscard]] constexpr bool subtractionOverflows(const Arithmetic_ minuend, const Arithmetic_ subtrahend) noexcept {
		return minuend && subtrahend && ((subtrahend >= 0) ? ((std::numeric_limits<Arithmetic_>::min() + subtrahend) > minuend) : ((std::numeric_limits<Arithmetic_>::max() + subtrahend) < minuend));
	}
}

#endif
