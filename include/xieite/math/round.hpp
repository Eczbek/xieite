#ifndef XIEITE_HEADER_MATH_ROUND
#	define XIEITE_HEADER_MATH_ROUND

#	include <cmath>
#	include <type_traits>
#	include "../concepts/arithmetic.hpp"

namespace xieite::math {
	template<xieite::concepts::Arithmetic Number1, xieite::concepts::Arithmetic Number2>
	[[nodiscard]] constexpr std::common_type_t<Number1, Number2> round(const Number1 value, const Number2 step = 1) noexcept {
		return std::round(value / step) * step;
	}
}

#endif
