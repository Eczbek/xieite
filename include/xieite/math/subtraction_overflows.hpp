#ifndef XIEITE_HEADER_MATH_SUBTRACTION_OVERFLOWS
#	define XIEITE_HEADER_MATH_SUBTRACTION_OVERFLOWS

#	include <limits>
#	include "../concepts/arithmetic.hpp"

namespace xieite::math {
	template<xieite::concepts::Arithmetic Number>
	[[nodiscard]] constexpr bool subtractionOverflows(const Number value1, const Number value2) noexcept {
		return value1 && value2 && ((value2 >= 0) ? ((std::numeric_limits<Number>::min() + value2) > value1) : ((std::numeric_limits<Number>::max() + value2) < value1));
	}
}

#endif
