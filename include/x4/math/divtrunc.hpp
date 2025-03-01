#pragma once

#include <cmath>
#include <concepts>
#include "../trait/isarith.hpp"

namespace x4 {
	template<x4::isarith T>
	[[nodiscard]] constexpr T divtrunc(T a, T b) noexcept {
		if constexpr (std::floating_point<T>) {
			return std::floor(a / b) + ((a < 0) != (b < 0));
		} else {
			return a / b;
		}
	}
}
