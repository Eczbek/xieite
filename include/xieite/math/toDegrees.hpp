#pragma once
#include <numbers>
#include <xieite/concepts/Arithmetic.hpp>
#include <xieite/math/pi.hpp>

namespace xieite::math {
	template<xieite::concepts::Arithmetic N>
	[[nodiscard]]
	constexpr N toDegrees(const N radians) noexcept {
		return radians * 180 / xieite::math::pi<N>;
	}
}
