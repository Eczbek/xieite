#ifndef XIEITE_HEADER_GEOMETRY_REFLECT
#	define XIEITE_HEADER_GEOMETRY_REFLECT

#	include "../concepts/convertible_to_any.hpp"
#	include "../geometry/line.hpp"
#	include "../geometry/point.hpp"
#	include "../geometry/polygon.hpp"
#	include "../geometry/ray.hpp"
#	include "../geometry/rotate.hpp"
#	include "../geometry/segment.hpp"

namespace xieite::geometry {
	template<typename Number, xieite::concepts::ConvertibleToAny<xieite::geometry::Line<Number>, xieite::geometry::Ray<Number>, xieite::geometry::Segment<Number>> LinearShape>
	[[nodiscard]] constexpr xieite::geometry::Point<Number> reflect(const xieite::geometry::Point<Number> point, const LinearShape& mirror) noexcept {
		return xieite::geometry::rotate(point, (mirror.angle() - mirror.start.angleTo(point)) * 2);
	}

	template<typename Number, xieite::concepts::ConvertibleToAny<xieite::geometry::Line<Number>, xieite::geometry::Ray<Number>, xieite::geometry::Segment<Number>> LinearShape1, xieite::concepts::ConvertibleToAny<xieite::geometry::Line<Number>, xieite::geometry::Ray<Number>, xieite::geometry::Segment<Number>> LinearShape2>
	[[nodiscard]] constexpr LinearShape1 reflect(const LinearShape1& line, const LinearShape2& mirror) noexcept {
		return LinearShape1(xieite::geometry::rotate(line.start, (mirror.angle() - mirror.start.angleTo(line.start)) * 2), xieite::geometry::rotate(line.end, (mirror.angle() - mirror.start.angleTo(line.end)) * 2));
	}

	template<typename Number, xieite::concepts::ConvertibleToAny<xieite::geometry::Line<Number>, xieite::geometry::Ray<Number>, xieite::geometry::Segment<Number>> LinearShape>
	[[nodiscard]] constexpr xieite::geometry::Polygon<Number> reflect(xieite::geometry::Polygon<Number> polygon, const LinearShape& mirror) noexcept {
		for (xieite::geometry::Point<Number>& point : polygon.points) {
			point = xieite::geometry::rotate(point, (mirror.angle() - mirror.start.angleTo(point)) * 2);
		}
		return polygon;
	}
}

#endif
