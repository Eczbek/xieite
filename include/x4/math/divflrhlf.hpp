#pragma once

#include <cmath>
#include <concepts>
#include "../math/sgn.hpp"
#include "../trait/isarith.hpp"

namespace x4 {
	template<x4::isarith T>
	[[nodiscard]] constexpr T divflrhlf(T a, T b) noexcept {
		if constexpr (std::floating_point<T>) {
			const T result = a / b;
			const T fractional = std::fmod(result, 1);
			return std::floor(result) + (result < 0) + (fractional > 0.5) - (fractional <= -0.5);
		} else {
			const int quot_sign = x4::sgn(a, b);
			return static_cast<T>(a / b + ((a % b * x4::sgn(a)) >= (b / 2 * x4::sgn(b) + ((b % 2) || (quot_sign >= 0)))) * quot_sign);
		}
	}
}
