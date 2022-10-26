#pragma once
#include <xieite/concepts/Arithmetic.hpp>
#include <numbers>

namespace xieite::math {
	template<xieite::concepts::Arithmetic N>
	[[nodiscard]]
	constexpr double toRadians(const N degrees) noexcept {
		return degrees * std::numbers::pi_v<double> / 180;
	}
}
