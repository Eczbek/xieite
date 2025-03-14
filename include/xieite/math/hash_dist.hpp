#pragma once

#include <concepts>
#include <limits>
#include <numbers>
#include "../math/xor_shift.hpp"
#include "../trait/try_unsign.hpp"

namespace xieite {
	template<std::integral T, std::floating_point Phi = double>
	[[nodiscard]] constexpr T hash_dist(T n) noexcept {
		return static_cast<T>(static_cast<Phi>(std::numeric_limits<xieite::try_unsign<T>>::max()) / std::numbers::phi_v<Phi>) * xieite::xor_shift(std::numeric_limits<xieite::try_unsign<T>>::max() / 3 * xieite::xor_shift(n, sizeof(T) * 4), sizeof(T) * 4);
	}
}
