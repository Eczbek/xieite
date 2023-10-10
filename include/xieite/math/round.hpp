#pragma once

#include <cmath>
#include "../concepts/numeric.hpp"

namespace xieite::math {
	template<xieite::concepts::Numeric Number1, xieite::concepts::Numeric Number2>
	[[nodiscard]] constexpr Number1 round(const Number1 value, const Number2 step = 1) noexcept {
		return std::round(value / step) * step;
	}
}
