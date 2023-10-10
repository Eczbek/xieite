#pragma once

#include <cmath>
#include "../concepts/numeric.hpp"
#include "../math/result.hpp"

namespace xieite::math {
	template<xieite::concepts::Numeric Number>
	[[nodiscard]] constexpr xieite::math::Result<Number> cosecant(const Number value) noexcept {
		return 1 / std::sin(value);
	}
}
