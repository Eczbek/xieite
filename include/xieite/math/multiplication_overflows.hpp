#ifndef XIEITE_HEADER_MATH_MULTIPLICATION_OVERFLOWS
#	define XIEITE_HEADER_MATH_MULTIPLICATION_OVERFLOWS

#	include <limits>
#	include "../concepts/arithmetic.hpp"
#	include "../math/absolute.hpp"

namespace xieite::math {
	template<xieite::concepts::Arithmetic Number>
	[[nodiscard]] constexpr bool multiplicationOverflows(const Number value1, const Number value2) noexcept {
		return value1 && value2 && ((xieite::math::absolute(((value1 < 0) != (value2 < 0)) ? std::numeric_limits<Number>::min() : std::numeric_limits<Number>::max()) / xieite::math::absolute(value1)) < xieite::math::absolute(value2));
	}
}

#endif
