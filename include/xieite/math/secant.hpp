#pragma once

#include <cmath>
#include <xieite/concepts/Arithmetic.hpp>

namespace xieite::math {
	template<xieite::concepts::Arithmetic Number>
	[[nodiscard]]
	constexpr Number secant(const Number value) noexcept {
		return 1.0 / std::cos(value);
	}
}
