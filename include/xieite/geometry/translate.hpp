#ifndef XIEITE_HEADER_GEOMETRY_TRANSLATE
#	define XIEITE_HEADER_GEOMETRY_TRANSLATE

#	include "../concepts/convertible_to_any.hpp"
#	include "../geometry/line.hpp"
#	include "../geometry/point.hpp"
#	include "../geometry/polygon.hpp"
#	include "../geometry/ray.hpp"
#	include "../geometry/segment.hpp"

namespace xieite::geometry {
	template<typename Number>
	[[nodiscard]] constexpr xieite::geometry::Point<Number> translate(const xieite::geometry::Point<Number> point, const xieite::geometry::Point<Number> difference) noexcept {
		return xieite::geometry::Point<Number>(point.x + difference.x, point.y + difference.y);
	}

	template<typename Number, xieite::concepts::ConvertibleToAny<xieite::geometry::Line<Number>, xieite::geometry::Ray<Number>, xieite::geometry::Segment<Number>> LinearShape>
	[[nodiscard]] constexpr LinearShape translate(const LinearShape& line, const xieite::geometry::Point<Number> difference) noexcept {
		return Line(xieite::geometry::translate(line.start, difference), xieite::geometry::translate(line.end, difference));
	}

	[[nodiscard]] constexpr xieite::geometry::Polygon<Number> translate(xieite::geometry::Polygon<Number> polygon, const xieite::geometry::Point<Number> difference) noexcept {
		for (xieite::geometry::Point<Number>& point : polygon.points) {
			point = xieite::geometry::translate(point, difference);
		}
		return polygon;
	}
}

#endif
