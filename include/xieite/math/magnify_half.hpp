#pragma once

#include "../math/div_magnify_half.hpp"
#include "../trait/is_arith.hpp"

namespace xieite {
	template<xieite::is_arith T>
	[[nodiscard]] constexpr T magnify_half(T n, T step = 1) noexcept {
		return xieite::div_magnify_half(n, step) * step;
	}
}
