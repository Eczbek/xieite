#pragma once

#include <cmath>
#include "../math/almosteq.hpp"
#include "../trait/isarith.hpp"

namespace x4 {
	template<x4::isarith T>
	[[nodiscard]] constexpr bool almosteqslope(T n, T m) noexcept {
		return (std::isinf(n) && std::isinf(m)) || x4::almosteq(n, m);
	}

	template<x4::isarith T>
	[[nodiscard]] constexpr bool almosteqslope(T n, T m, T epsilon) noexcept {
		return (std::isinf(n) && std::isinf(m)) || x4::almosteq(n, m, epsilon);
	}
}
