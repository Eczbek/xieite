#ifndef XIEITE_HEADER__GEOMETRY__GET_DISTANCE
#	define XIEITE_HEADER__GEOMETRY__GET_DISTANCE

#	include <cmath>
#	include "../geometry/Point.hpp"

namespace xieite::geometry {
	constexpr double getDistance(const xieite::geometry::Point point1, const xieite::geometry::Point point2) noexcept {
		return std::hypot(point1.x - point2.x, point1.y - point2.y);
	}
}

#endif
