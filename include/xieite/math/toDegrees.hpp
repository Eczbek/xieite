#pragma once
#include <xieite/concepts/Arithmetic.hpp> // xieite::concepts::Arithmetic
#include <xieite/math/pi.hpp> // xieite::math::pi

namespace xieite::math {
	template<xieite::concepts::Arithmetic N>
	[[nodiscard]]
	constexpr N toDegrees(const N radians) noexcept {
		return radians * 180 / xieite::math::pi<N>;
	}
}
