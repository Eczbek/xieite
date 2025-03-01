#pragma once

#include <cmath>
#include <limits>
#include "../math/abs.hpp"
#include "../math/diff.hpp"
#include "../trait/isarith.hpp"

namespace x4 {
	template<x4::isarith T>
	[[nodiscard]] constexpr bool almosteq(T n, T m) noexcept {
		if constexpr (std::floating_point<T>) {
			const T scale = std::abs(n) + std::abs(m);
			return std::abs(n - m) <= (std::numeric_limits<T>::epsilon() * ((scale < 1.0) ? (1.0 / scale) : scale));
		} else {
			return n == m;
		}
	}

	template<x4::isarith T>
	[[nodiscard]] constexpr bool almosteq(T n, T m, T epsilon) noexcept {
		return x4::diff(n, m) <= x4::abs(epsilon);
	}
}
