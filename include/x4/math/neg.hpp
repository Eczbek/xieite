#pragma once

#include <cmath>
#include <concepts>
#include "../trait/isarith.hpp"

namespace x4 {
	template<x4::isarith T>
	[[nodiscard]] constexpr bool neg(T n) noexcept {
		if constexpr (std::floating_point<T>) {
			return std::signbit(n);
		} else if constexpr (!std::unsigned_integral<T>) {
			return n < 0;
		} else {
			return false;
		}
	}
}
