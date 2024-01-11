#ifndef XIEITE_HEADER_MATH_SECANT
#	define XIEITE_HEADER_MATH_SECANT

#	include <cmath>
#	include "../concepts/arithmetic.hpp"
#	include "../types/common_floating_point.hpp"

namespace xieite::math {
	template<xieite::concepts::Arithmetic Number>
	[[nodiscard]] constexpr xieite::types::CommonFloatingPoint<Number> secant(const Number value) noexcept {
		return 1 / std::cos(static_cast<xieite::types::CommonFloatingPoint<Number>>(value));
	}
}

#endif
