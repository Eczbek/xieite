#pragma once
#include <xieite/concepts/Arithmetic.hpp>
#include <xieite/math/difference.hpp>

namespace xieite::math {
	template<xieite::concepts::Arithmetic Number>
	[[nodiscard]]
	constexpr Number& farthestFrom(const Number target, Number& a, Number& b) noexcept {
		return (a >= target) ? ((b >= target) ? ((a > b) ? a : b) : ((xieite::math::difference(target, a) < xieite::math::difference(target, b)) ? a : b)) : ((b < target) ? ((a < b) ? a : b) : ((xieite::math::difference(target, a) > xieite::math::difference(target, b)) ? a : b));
	}

	template<xieite::concepts::Arithmetic Number>
	[[nodiscard]]
	constexpr Number farthestFrom(const Number target, const Number& a, const Number& b) noexcept {
		return (a >= target) ? ((b >= target) ? ((a > b) ? a : b) : ((xieite::math::difference(target, a) < xieite::math::difference(target, b)) ? a : b)) : ((b < target) ? ((a < b) ? a : b) : ((xieite::math::difference(target, a) > xieite::math::difference(target, b)) ? a : b));
	}
}
