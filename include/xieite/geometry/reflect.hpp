#ifndef XIEITE_HEADER_GEOMETRY_REFLECT
#	define XIEITE_HEADER_GEOMETRY_REFLECT

#	include <xieite/concepts/LinearShape.hpp>
#	include <xieite/geometry/Point.hpp>
#	include <xieite/geometry/Polygon.hpp>
#	include <xieite/geometry/getAngle.hpp>
#	include <xieite/geometry/rotate.hpp>

namespace xieite::geometry {
	[[nodiscard]]
	constexpr xieite::geometry::Point reflect(const xieite::geometry::Point point, const xieite::concepts::LinearShape auto& mirror) noexcept {
		return xieite::geometry::rotate(point, (xieite::geometry::getAngle(mirror) - xieite::geometry::getAngle(mirror.start, point)) * 2);
	}

	template<xieite::concepts::LinearShape LinearShape>
	[[nodiscard]]
	constexpr LinearShape reflect(const LinearShape& line, const xieite::concepts::LinearShape auto& mirror) noexcept {
		const double angle = xieite::geometry::getAngle(mirror);
		return Line(xieite::geometry::rotate(line.start, (angle - xieite::geometry::getAngle(mirror.start, line.start)) * 2), xieite::geometry::rotate(line.end, (angle - xieite::geometry::getAngle(mirror.start, line.end)) * 2));
	}

	[[nodiscard]]
	constexpr xieite::geometry::Polygon reflect(xieite::geometry::Polygon polygon, const xieite::concepts::LinearShape auto& mirror) noexcept {
		const double angle = xieite::geometry::getAngle(mirror);
		for (xieite::geometry::Point& point : polygon.points) {
			point = xieite::geometry::rotate(point, (angle - xieite::geometry::getAngle(mirror.start, point)) * 2);
		}
		return polygon;
	}
}

#endif
