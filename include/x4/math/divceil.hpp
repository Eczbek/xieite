#pragma once

#include <cmath>
#include <concepts>
#include "../math/sgn.hpp"
#include "../trait/isarith.hpp"

namespace x4 {
	template<x4::isarith T>
	[[nodiscard]] constexpr T divceil(T a, T b) {
		if constexpr (std::floating_point<T>) {
			return std::ceil(a / b);
		} else {
			return static_cast<T>(a / b + !!(a % b) * (x4::sgn(a, b) > 0));
		}
	}
}
