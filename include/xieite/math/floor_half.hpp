#pragma once

#include "../math/div_floor_half.hpp"
#include "../trait/is_arith.hpp"

namespace xieite {
	template<xieite::is_arith T>
	[[nodiscard]] constexpr T floor_half(T n, T step = 1) noexcept {
		return xieite::div_floor_half(n, step) * step;
	}
}
