#pragma once

#include "../math/div_floor.hpp"
#include "../trait/isarith.hpp"

namespace x4 {
	template<x4::isarith T>
	[[nodiscard]] constexpr T floor(T n, T step = 1) noexcept {
		return x4::div_floor(n, step) * step;
	}
}
