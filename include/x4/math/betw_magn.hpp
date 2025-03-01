#pragma once

#include "../math/minmaxmagn.hpp"
#include "../trait/isarith.hpp"

namespace x4 {
	template<x4::isarith T>
	[[nodiscard]] constexpr bool betwmagn(T n, T limit0, T limit1, bool down_incl = true, bool up_incl = true) noexcept {
		const auto [down, up] = x4::minmaxmagn(limit0, limit1);
		return (down_incl ? (n >= down) : (n > down))
			&& (up_incl ? (n <= up) : (n < up));
	}
}
