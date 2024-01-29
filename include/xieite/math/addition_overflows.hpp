#ifndef XIEITE_HEADER_MATH_ADDITION_OVERFLOWS
#	define XIEITE_HEADER_MATH_ADDITION_OVERFLOWS

#	include <limits>
#	include "../concepts/arithmetic.hpp"

namespace xieite::math {
	template<xieite::concepts::Arithmetic Number>
	[[nodiscard]] constexpr bool additionOverflows(const Number value1, const Number value2) noexcept {
		return value1 && value2 && ((value1 >= 0) ? ((std::numeric_limits<Number>::max() - value1) < value2) : ((std::numeric_limits<Number>::min() - value1) > value2));
	}
}

#endif
