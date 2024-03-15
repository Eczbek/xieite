#ifndef XIEITE_HEADER_MATH_ROUND
#	define XIEITE_HEADER_MATH_ROUND

#	include <cmath>
#	include "../concepts/arithmetic.hpp"

namespace xieite::math {
	template<xieite::concepts::Arithmetic Number>
	[[nodiscard]] constexpr Number round(const Number value, const Number step = 1) noexcept {
		return std::round(value / step) * step;
	}
}

#endif
