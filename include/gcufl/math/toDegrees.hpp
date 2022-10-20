#pragma once
#include <gcufl/concepts/Arithmetic.hpp>
#include <numbers>

namespace gcufl::math {
	template<gcufl::concepts::Arithmetic N>
	[[nodiscard]]
	constexpr double toDegrees(const N radians) noexcept {
		return radians * 180 / std::numbers::pi_v<double>;
	}
}
