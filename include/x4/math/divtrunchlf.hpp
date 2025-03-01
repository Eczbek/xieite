#pragma once

#include <cmath>
#include <concepts>
#include "../math/sgn.hpp"
#include "../trait/isarith.hpp"

namespace x4 {
	template<x4::isarith T>
	[[nodiscard]] constexpr T divtrunchlf(T a, T b) noexcept {
		if constexpr (std::floating_point<T>) {
			const T result = a / b;
			return std::floor(result) + (result < 0) + (std::fmod(std::abs(result), 1) > 0.5) * x4::sgn(result);
		} else {
			return static_cast<T>(a / b + ((a % b * x4::sgn(a)) > (b / 2 * x4::sgn(b))) * x4::sgn(a, b));
		}
	}
}
