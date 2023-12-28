#ifndef XIEITE_HEADER_MATH_FLOOR
#	define XIEITE_HEADER_MATH_FLOOR

#	include <cmath>
#	include <type_traits>
#	include "../concepts/arithmetic.hpp"

namespace xieite::math {
	template<xieite::concepts::Arithmetic Number1, xieite::concepts::Arithmetic Number2>
	[[nodiscard]] constexpr std::common_type_t<Number1, Number2> floor(const Number1 value, const Number2 step = 1) noexcept {
		return std::floor(value / step) * step;
	}
}

#endif
