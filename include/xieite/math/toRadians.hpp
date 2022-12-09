#pragma once
#include <xieite/concepts/Arithmetic.hpp> // xieite::concepts::Arithmetic
#include <xieite/math/pi.hpp> // xieite::math::pi

namespace xieite::math {
	template<xieite::concepts::Arithmetic N>
	[[nodiscard]]
	constexpr N toRadians(const N degrees) noexcept {
		return degrees * xieite::math::pi<N> / 180;
	}
}
