#pragma once

#include <gcufl/concepts/Arithmetic.hpp>
#include <numbers>


namespace gcufl::math {
	template<gcufl::concepts::Arithmetic N>
	constexpr double toRadians(const N degrees) noexcept {
		return degrees * std::numbers::pi_v<double> / 180;
	}
}
