#pragma once

#include "../math/div_magnify.hpp"
#include "../trait/is_arith.hpp"

namespace xieite {
	template<xieite::is_arith T>
	[[nodiscard]] constexpr T magnify(T n, T step = 1) noexcept {
		return xieite::div_magnify(n, step) * step;
	}
}
