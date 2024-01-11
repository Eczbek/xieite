#ifndef XIEITE_HEADER_MATH_COTANGENT
#	define XIEITE_HEADER_MATH_COTANGENT

#	include <cmath>
#	include "../concepts/arithmetic.hpp"
#	include "../types/common_floating_point.hpp"

namespace xieite::math {
	template<xieite::concepts::Arithmetic Number>
	[[nodiscard]] constexpr xieite::types::CommonFloatingPoint<Number> cotangent(const Number value) noexcept {
		return std::cos(static_cast<xieite::types::CommonFloatingPoint<Number>>(value)) / std::sin(static_cast<xieite::types::CommonFloatingPoint<Number>>(value));
	}
}

#endif
