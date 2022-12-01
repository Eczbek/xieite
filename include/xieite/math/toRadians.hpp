#pragma once
#include <numbers>
#include <xieite/concepts/Arithmetic.hpp>
#include <xieite/numbers/pi.hpp>

namespace xieite::math {
	template<xieite::concepts::Arithmetic N>
	[[nodiscard]]
	constexpr N toRadians(const N degrees) noexcept {
		return degrees * xieite::numbers::pi<N> / 180;
	}
}
