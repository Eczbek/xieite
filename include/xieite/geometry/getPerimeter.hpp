#ifndef XIEITE_HEADER_GEOMETRY_GETPERIMETER
#	define XIEITE_HEADER_GEOMETRY_GETPERIMETER

#	include "../geometry/Polygon.hpp"
#	include "../geometry/Segment.hpp"
#	include "../geometry/getLength.hpp"
#	include "../geometry/getSides.hpp"

namespace xieite::geometry {
	[[nodiscard]]
	constexpr double getPerimeter(const xieite::geometry::Polygon& polygon) noexcept {
		double perimeter = 0.0;
		for (const xieite::geometry::Segment& side : xieite::geometry::getSides(polygon)) {
			perimeter += xieite::geometry::getLength(side);
		}
		return perimeter;
	}
}

#endif
