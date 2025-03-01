#pragma once

#include <cmath>
#include <concepts>
#include "../trait/isarith.hpp"

namespace x4 {
	template<x4::isarith T>
	[[nodiscard]] constexpr T rem(T a, T b) noexcept {
		if constexpr (std::floating_point<T>) {
			return std::fmod(a, b);
		} else {
			return a % b;
		}
	}
}
