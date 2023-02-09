#pragma once
#include <xieite/math/approximatelyEqual.hpp>

namespace xieite::geometry {
	struct Point {
		long double x;
		long double y;

		constexpr Point(const long double x = 0, const long double y = 0) noexcept
		: x(x), y(y) {}

		[[nodiscard]]
		constexpr bool operator==(const xieite::geometry::Point other) const noexcept {
			return xieite::math::approximatelyEqual(x, other.x) && xieite::math::approximatelyEqual(y, other.y);
		}
	};
}
