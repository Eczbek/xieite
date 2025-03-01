#pragma once

#include "../math/minmax.hpp"
#include "../math/mod.hpp"
#include "../trait/isarith.hpp"

namespace x4 {
	template<x4::isarith T>
	[[nodiscard]] constexpr T wrap(T n, T limit0, T limit1) noexcept {
		const auto [min, max] = x4::minmax(limit0, limit1);
		return x4::mod(n - min, max - min) + min;
	}
}
