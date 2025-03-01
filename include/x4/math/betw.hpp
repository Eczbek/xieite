#pragma once

#include "../math/minmax.hpp"
#include "../trait/isarith.hpp"

namespace x4 {
	template<x4::isarith T>
	[[nodiscard]] constexpr bool betw(T n, T limit0, T limit1, bool lower_incl = true, bool upper_incl = true) noexcept {
		const auto [lower, upper] = x4::minmax(limit0, limit1);
		return (lower_incl ? (n >= lower) : (n > lower))
			&& (upper_incl ? (n <= upper) : (n < upper));
	}
}
