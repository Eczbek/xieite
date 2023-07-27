#ifndef XIEITE_HEADER_GEOMETRY_REFLECT
#	define XIEITE_HEADER_GEOMETRY_REFLECT

#	include "../concepts/LinearShape.hpp"
#	include "../geometry/Point.hpp"
#	include "../geometry/Polygon.hpp"
#	include "../geometry/getAngle.hpp"
#	include "../geometry/rotate.hpp"

namespace xieite::geometry {
	template<xieite::concepts::LinearShape LinearShape>
	[[nodiscard]]
	constexpr xieite::geometry::Point reflect(const xieite::geometry::Point point, const LinearShape& mirror) noexcept {
		return xieite::geometry::rotate(point, (xieite::geometry::getAngle(mirror) - xieite::geometry::getAngle(mirror.start, point)) * 2);
	}

	template<xieite::concepts::LinearShape LinearShape1, xieite::concepts::LinearShape LinearShape2>
	[[nodiscard]]
	constexpr LinearShape1 reflect(const LinearShape1& line, const LinearShape2& mirror) noexcept {
		const double angle = xieite::geometry::getAngle(mirror);
		return LinearShape1(xieite::geometry::rotate(line.start, (angle - xieite::geometry::getAngle(mirror.start, line.start)) * 2), xieite::geometry::rotate(line.end, (angle - xieite::geometry::getAngle(mirror.start, line.end)) * 2));
	}

	template<xieite::concepts::LinearShape LinearShape>
	[[nodiscard]]
	constexpr xieite::geometry::Polygon reflect(xieite::geometry::Polygon polygon, const LinearShape& mirror) noexcept {
		const double angle = xieite::geometry::getAngle(mirror);
		for (xieite::geometry::Point& point : polygon.points) {
			point = xieite::geometry::rotate(point, (angle - xieite::geometry::getAngle(mirror.start, point)) * 2);
		}
		return polygon;
	}
}

#endif
