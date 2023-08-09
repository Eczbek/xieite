#ifndef XIEITE_HEADER__GEOMETRY__POINT
#	define XIEITE_HEADER__GEOMETRY__POINT

#	include "../math/almostEqual.hpp"

namespace xieite::geometry {
	struct Point {
		double x;
		double y;

		constexpr Point(const double x = 0, const double y = 0) noexcept
		: x(x), y(y) {}

		constexpr bool operator==(const xieite::geometry::Point point) const noexcept {
			return xieite::math::almostEqual(this->x, point.x) && xieite::math::almostEqual(this->y, point.y);
		}
	};
}

#endif
