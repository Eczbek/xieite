#ifndef XIEITE_HEADER__GEOMETRY__TRANSLATE
#	define XIEITE_HEADER__GEOMETRY__TRANSLATE

#	include "../concepts/LinearShape.hpp"
#	include "../geometry/Point.hpp"
#	include "../geometry/Polygon.hpp"

namespace xieite::geometry {
	[[nodiscard]] constexpr xieite::geometry::Point translate(const xieite::geometry::Point point, const xieite::geometry::Point difference) noexcept {
		return xieite::geometry::Point(point.x + difference.x, point.y + difference.y);
	}

	template<xieite::concepts::LinearShape LinearShape>
	[[nodiscard]] constexpr LinearShape translate(const LinearShape& line, const xieite::geometry::Point difference) noexcept {
		return Line(xieite::geometry::translate(line.start, difference), xieite::geometry::translate(line.end, difference));
	}

	[[nodiscard]] constexpr xieite::geometry::Polygon translate(xieite::geometry::Polygon polygon, const xieite::geometry::Point difference) noexcept {
		for (xieite::geometry::Point& point : polygon.points) {
			point = xieite::geometry::translate(point, difference);
		}
		return polygon;
	}
}

#endif
