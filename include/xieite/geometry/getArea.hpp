#ifndef XIEITE_HEADER_GEOMETRY_GETAREA
#	define XIEITE_HEADER_GEOMETRY_GETAREA

#	include <cmath>
#	include <xieite/geometry/Polygon.hpp>
#	include <xieite/geometry/Segment.hpp>
#	include <xieite/geometry/getSides.hpp>
#	include <xieite/math/pi.hpp>

namespace xieite::geometry {
	[[nodiscard]]
	constexpr double getArea(const xieite::geometry::Polygon& polygon) noexcept {
		double area = 0.0;
		for (const xieite::geometry::Segment& side : xieite::geometry::getSides(polygon)) {
			area += side.start.x * side.start.y - side.start.x * side.end.y;
		}
		return std::abs(area) / 2.0;
	}
}

#endif
