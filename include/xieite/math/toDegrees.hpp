#pragma once
#include <xieite/concepts/Arithmetic.hpp>
#include <numbers>

namespace xieite::math {
	template<xieite::concepts::Arithmetic N>
	[[nodiscard]]
	constexpr double toDegrees(const N radians) noexcept {
		return radians * 180 / std::numbers::pi_v<double>;
	}
}
