#pragma once

#include <cmath>
#include <concepts>
#include "../math/sgn.hpp"
#include "../trait/isarith.hpp"

namespace x4 {
	template<x4::isarith T>
	[[nodiscard]] constexpr T divmagn(T a, T b) noexcept {
		if constexpr (std::floating_point<T>) {
			return std::ceil(a / b) - ((a < 0) != (b < 0));
		} else {
			return static_cast<T>(a / b + !!(a % b) * x4::sgn(a, b));
		}
	}
}
