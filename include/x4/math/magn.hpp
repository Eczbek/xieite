#pragma once

#include "../math/divmagn.hpp"
#include "../trait/isarith.hpp"

namespace x4 {
	template<x4::isarith T>
	[[nodiscard]] constexpr T magn(T n, T step = 1) noexcept {
		return x4::divmagn(n, step) * step;
	}
}
