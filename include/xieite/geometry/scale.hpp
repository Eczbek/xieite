#ifndef XIEITE_HEADER_GEOMETRY_SCALE
#	define XIEITE_HEADER_GEOMETRY_SCALE

#	include "../concepts/LinearShape.hpp"
#	include "../geometry/Point.hpp"
#	include "../geometry/Polygon.hpp"

namespace xieite::geometry {
	[[nodiscard]]
	constexpr xieite::geometry::Point scale(const xieite::geometry::Point point, const double scale, const xieite::geometry::Point origin = xieite::geometry::Point(0, 0)) noexcept {
		return xieite::geometry::Point(point.x + (origin.x - point.x) * scale, point.y + (origin.y - point.y) * scale);
	}

	template<xieite::concepts::LinearShape LinearShape>
	[[nodiscard]]
	constexpr LinearShape scale(const LinearShape& line, const double scale, const xieite::geometry::Point origin = xieite::geometry::Point(0, 0)) noexcept {
		return Line(xieite::geometry::scale(line.start, scale, origin), xieite::geometry::scale(line.end, scale, origin));
	}

	[[nodiscard]]
	constexpr xieite::geometry::Polygon scale(xieite::geometry::Polygon polygon, const double scale, const xieite::geometry::Point origin = xieite::geometry::Point(0, 0)) noexcept {
		for (xieite::geometry::Point& point : polygon.points) {
			point = xieite::geometry::scale(point, scale, origin);
		}
		return polygon;
	}
}

#endif
