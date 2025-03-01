#pragma once

#include "../math/divceilhlf.hpp"
#include "../trait/isarith.hpp"

namespace x4 {
	template<x4::isarith T>
	[[nodiscard]] constexpr T ceilhlf(T n, T step = 1) noexcept {
		return x4::divceilhlf(n, step) * step;
	}
}
