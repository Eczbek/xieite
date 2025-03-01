#pragma once

#include "../math/div_trunc.hpp"
#include "../trait/isarith.hpp"

namespace x4 {
	template<x4::isarith T>
	[[nodiscard]] constexpr T trunc(T n, T step = 1) noexcept {
		return x4::div_trunc(n, step) * step;
	}
}
