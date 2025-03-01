#pragma once

#include <concepts>
#include <limits>
#include <numbers>
#include "../math/xorshift.hpp"
#include "../meta/tryunsign.hpp"

namespace x4 {
	template<std::integral T, std::floating_point Phi = double>
	[[nodiscard]] constexpr T hashdist(T n) noexcept {
		return static_cast<T>(static_cast<Phi>(std::numeric_limits<x4::tryunsign<T>>::max()) / std::numbers::phi_v<Phi>) * x4::xorshift(std::numeric_limits<x4::tryunsign<T>>::max() / 3 * x4::xorshift(n, sizeof(T) * 4), sizeof(T) * 4);
	}
}
