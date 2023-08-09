#ifndef XIEITE_HEADER__GEOMETRY__GET_PERIMETER
#	define XIEITE_HEADER__GEOMETRY__GET_PERIMETER

#	include "../geometry/Polygon.hpp"
#	include "../geometry/Segment.hpp"
#	include "../geometry/getLength.hpp"
#	include "../geometry/getSides.hpp"

namespace xieite::geometry {
	constexpr double getPerimeter(const xieite::geometry::Polygon& polygon) noexcept {
		double perimeter = 0;
		for (const xieite::geometry::Segment& side : xieite::geometry::getSides(polygon)) {
			perimeter += xieite::geometry::getLength(side);
		}
		return perimeter;
	}
}

#endif
