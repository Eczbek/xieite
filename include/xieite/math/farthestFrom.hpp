#pragma once
#include <xieite/concepts/Arithmetic.hpp>
#include <xieite/math/difference.hpp>

namespace xieite::math {
	template<xieite::concepts::Arithmetic N>
	[[nodiscard]]
	constexpr N& farthestFrom(const N target, N& a, N& b) noexcept {
		return (a >= target) ? ((b >= target) ? ((a > b) ? a : b) : ((xieite::math::difference(target, a) < xieite::math::difference(target, b)) ? a : b)) : ((b < target) ? ((a < b) ? a : b) : ((xieite::math::difference(target, a) > xieite::math::difference(target, b)) ? a : b));
	}

	template<xieite::concepts::Arithmetic N>
	[[nodiscard]]
	constexpr const N& farthestFrom(const N target, const N& a, const N& b) noexcept {
		return (a >= target) ? ((b >= target) ? ((a > b) ? a : b) : ((xieite::math::difference(target, a) < xieite::math::difference(target, b)) ? a : b)) : ((b < target) ? ((a < b) ? a : b) : ((xieite::math::difference(target, a) > xieite::math::difference(target, b)) ? a : b));
	}
}
