#ifndef XIEITE_HEADER__GEOMETRY__CONTAINS_POINT
#	define XIEITE_HEADER__GEOMETRY__CONTAINS_POINT

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
		bool odd = false;
		const std::size_t pointsSize = polygon.points.size();
		for (std::size_t i = 0; i < pointsSize; ++i) {
			const std::size_t j = (i + 1) % pointsSize;
			odd ^= ((polygon.points[i].y < point.y) && (polygon.points[j].y >= point.y) || (polygon.points[j].y < point.y) && (polygon.points[i].y >= point.y)) && ((polygon.points[i].x <= point.x) || (polygon.points[j].x <= point.x)) && ((polygon.points[i].x + (point.y - polygon.points[i].y) / (polygon.points[j].y - polygon.points[i].y) * (polygon.points[j].x - polygon.points[i].x)) < point.x);
		}
		if (odd) {
			return true;
		}
		for (const xieite::geometry::Segment& side : xieite::geometry::getSides(polygon)) {
			if (xieite::geometry::containsPoint(side, point)) {
				return true;
			}
		}
		return false;
	}
}

#endif
