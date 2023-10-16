#ifndef XIEITE_HEADER_MATH_ROUND
#	define XIEITE_HEADER_MATH_ROUND

#	include <cmath>
#	include <type_traits>
#	include "../concepts/numeric.hpp"

namespace xieite::math {
	template<xieite::concepts::Numeric Number1, xieite::concepts::Numeric Number2>
	[[nodiscard]] constexpr std::common_type_t<Number1, Number2> round(const Number1 value, const Number2 step = 1) noexcept {
		return std::round(value / step) * step;
	}
}

#endif
