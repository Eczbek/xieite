#pragma once

#include <cmath>
#include <concepts>
#include "../meta/tryunsign.hpp"
#include "../trait/isarith.hpp"

namespace x4 {
	template<x4::isarith T>
	[[nodiscard]] constexpr x4::tryunsign<T> abs(T n) noexcept {
		if constexpr (std::floating_point<T>) {
			return std::abs(n);
		} else if constexpr (std::unsigned_integral<T>) {
			return n;
		} else {
			return (n < 0)
				? -static_cast<x4::tryunsign<T>>(n)
				: static_cast<x4::tryunsign<T>>(n);
		}
	}
}
