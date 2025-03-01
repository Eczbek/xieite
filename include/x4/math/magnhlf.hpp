#pragma once

#include "../math/divmagnhlf.hpp"
#include "../trait/isarith.hpp"

namespace x4 {
	template<x4::isarith T>
	[[nodiscard]] constexpr T magnhlf(T n, T step = 1) noexcept {
		return x4::divmagnhlf(n, step) * step;
	}
}
