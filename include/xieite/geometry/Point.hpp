#pragma once

#include <xieite/math/approximatelyEqual.hpp>

namespace xieite::geometry {
	struct Point {
		double x;
		double y;

		constexpr Point(const double x = 0.0, const double y = 0.0) noexcept
		: x(x), y(y) {}

		[[nodiscard]]
		constexpr bool operator==(const xieite::geometry::Point other) const noexcept {
			return xieite::math::approximatelyEqual(this->x, other.x) && xieite::math::approximatelyEqual(this->y, other.y);
		}
	};
}
