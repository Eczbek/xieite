#pragma once
#include <numbers>
#include <xieite/concepts/Arithmetic.hpp>
#include <xieite/math/pi.hpp>

namespace xieite::math {
	template<xieite::concepts::Arithmetic N>
	[[nodiscard]]
	constexpr N toRadians(const N degrees) noexcept {
		return degrees * xieite::math::pi<N> / 180;
	}
}
