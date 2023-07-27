#ifndef XIEITE_HEADER_GEOMETRY_POINT
#	define XIEITE_HEADER_GEOMETRY_POINT

#	include "../math/almostEqual.hpp"

namespace xieite::geometry {
	struct Point {
		double x;
		double y;

		constexpr Point(const double x = 0.0, const double y = 0.0) noexcept
		: x(x), y(y) {}

		[[nodiscard]]
		constexpr bool operator==(const xieite::geometry::Point point) const noexcept {
			return xieite::math::almostEqual(this->x, point.x) && xieite::math::almostEqual(this->y, point.y);
		}
	};
}

#endif
