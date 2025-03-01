#pragma once

#include "../math/divflrhlf.hpp"
#include "../trait/isarith.hpp"

namespace x4 {
	template<x4::isarith T>
	[[nodiscard]] constexpr T flrhlf(T n, T step = 1) noexcept {
		return x4::divflrhlf(n, step) * step;
	}
}
