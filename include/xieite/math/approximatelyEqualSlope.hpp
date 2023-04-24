#pragma once

#include <cmath>
#include <xieite/concepts/Arithmetic.hpp>
#include <xieite/math/approximatelyEqual.hpp>

namespace xieite::math {
	template<xieite::concepts::Arithmetic Number>
	[[nodiscard]]
	constexpr bool approximatelyEqualSlope(const Number value1, const Number value2) noexcept {
		return (std::isinf(value1) && std::isinf(value2)) || xieite::math::approximatelyEqual(value1, value2);
	}
}
