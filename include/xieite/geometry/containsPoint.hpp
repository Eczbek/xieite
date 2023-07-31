#ifndef XIEITE_HEADER_GEOMETRY_CONTAINSPOINT
#	define XIEITE_HEADER_GEOMETRY_CONTAINSPOINT

#	include <cmath>
#	include <cstddef>
#	include "../geometry/Line.hpp"
#	include "../geometry/Point.hpp"
#	include "../geometry/Polygon.hpp"
#	include "../geometry/Ray.hpp"
#	include "../geometry/Segment.hpp"
#	include "../geometry/getDistance.hpp"
#	include "../geometry/getLength.hpp"
#	include "../geometry/getSides.hpp"
#	include "../geometry/getSlope.hpp"
#	include "../math/almostEqual.hpp"

namespace xieite::geometry {
	[[nodiscard]]
	constexpr bool containsPoint(const xieite::geometry::Point point1, const xieite::geometry::Point point2) noexcept {
		return (point1 == point2);
	}

	[[nodiscard]]
	constexpr bool containsPoint(const xieite::geometry::Line& line, const xieite::geometry::Point point) noexcept {
		const double slope = xieite::geometry::getSlope(line);
		return std::isinf(slope) ? xieite::math::almostEqual(point.x, line.start.x) : xieite::math::almostEqual(point.x * slope - line.start.x * slope + line.start.y, point.y);
	}

	[[nodiscard]]
	constexpr bool containsPoint(const xieite::geometry::Ray& ray, const xieite::geometry::Point point) noexcept {
		const double slope = xieite::geometry::getSlope(ray);
		return std::isinf(slope) ? (xieite::math::almostEqual(point.x, ray.start.x) && (slope < std::numeric_limits<double>::lowest()) ? (point.y >= ray.start.y) : (point.y <= ray.start.y)) : (xieite::math::almostEqual(point.x * slope - ray.start.x * slope + ray.start.y, point.y) && ((ray.start.x <= ray.end.x) ? (point.x >= ray.start.x) : (point.x <= ray.start.x)) && ((ray.start.y <= ray.end.y) ? (point.y >= ray.start.y) : (point.y <= ray.start.y)));
	}

	[[nodiscard]]
	constexpr bool containsPoint(const xieite::geometry::Segment& segment, const xieite::geometry::Point point) noexcept {
		return xieite::math::almostEqual(xieite::geometry::getDistance(point, segment.start) + xieite::geometry::getDistance(point, segment.end), xieite::geometry::getLength(segment));
	}

	[[nodiscard]]
	constexpr bool containsPoint(const xieite::geometry::Polygon& polygon, const xieite::geometry::Point point) noexcept {
		std::size_t intersections = 0;
		xieite::geometry::Ray ray = xieite::geometry::Ray(point, 0);
		for (const xieite::geometry::Segment& side : xieite::geometry::getSides(polygon)) {
			const double a = (ray.start.x - ray.end.x) * (side.start.y - side.end.y) - (ray.start.y - ray.end.y) * (side.start.x - side.end.x);
			if (!xieite::math::almostEqual(a, 0)) {
				const xieite::geometry::Point intersection = xieite::geometry::Point(((side.start.x - side.end.x) * (ray.start.x * ray.end.y - ray.start.y * ray.end.x) - (ray.start.x - ray.end.x) * (side.start.x * side.end.y - side.start.y * side.end.x)) / a, ((side.start.y - side.end.y) * (ray.start.x * ray.end.y - ray.start.y * ray.end.x) - (ray.start.y - ray.end.y) * (side.start.x * side.end.y - side.start.y * side.end.x)) / a);
				intersections += (xieite::geometry::containsPoint(ray, intersection) && xieite::geometry::containsPoint(side, intersection));
			}
		}
		return intersections % 2;
	}
}

#endif
