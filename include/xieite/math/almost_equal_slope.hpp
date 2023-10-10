#pragma once

#include <cmath>
#include "../concepts/numeric.hpp"
#include "../math/almost_equal.hpp"

namespace xieite::math {
	template<xieite::concepts::Numeric Number1, xieite::concepts::Numeric Number2>
	[[nodiscard]] constexpr bool almostEqualSlope(const Number1 value1, const Number2 value2) noexcept {
		return std::isinf(value1) && std::isinf(value2) || xieite::math::almostEqual(value1, value2);
	}
}
