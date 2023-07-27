#ifndef XIEITE_HEADER_GEOMETRY_GETDISTANCE
#	define XIEITE_HEADER_GEOMETRY_GETDISTANCE

#	include <cmath>
#	include "../geometry/Point.hpp"

namespace xieite::geometry {
	[[nodiscard]]
	constexpr double getDistance(const xieite::geometry::Point point1, const xieite::geometry::Point point2) noexcept {
		return std::hypot(point1.x - point2.x, point1.y - point2.y);
	}
}

#endif
