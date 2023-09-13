#ifndef XIEITE_HEADER__GEOMETRY__INTERSECTIONS
#	define XIEITE_HEADER__GEOMETRY__INTERSECTIONS

#	include <cmath>
#	include <vector>
#	include "../concepts/LinearShape.hpp"
#	include "../geometry/Point.hpp"
#	include "../geometry/Segment.hpp"
#	include "../math/almostEqual.hpp"

namespace xieite::geometry {
	constexpr std::vector<xieite::geometry::Point> intersections(const xieite::geometry::Point point1, const xieite::geometry::Point point2) noexcept {
		return (point1 == point2) ? std::vector<xieite::geometry::Point> {
			point1
		} : std::vector<xieite::geometry::Point>();
	}

	template<xieite::concepts::LinearShape LinearShape>
	constexpr std::vector<xieite::geometry::Point> intersections(const xieite::geometry::Point point, const LinearShape& linearShape) noexcept {
		return linearShape.containsPoint(point) ? std::vector<xieite::geometry::Point> {
			point
		} : std::vector<xieite::geometry::Point>();
	}

	constexpr std::vector<xieite::geometry::Point> intersections(const xieite::geometry::Point point, const xieite::geometry::Polygon& polygon) noexcept {
		std::vector<xieite::geometry::Point> totalIntersections;
		for (const xieite::geometry::Segment& side : polygon.sides()) {
			const std::vector<xieite::geometry::Point> localIntersections = xieite::geometry::intersections(point, side);
			totalIntersections.insert(totalIntersections.end(), localIntersections.begin(), localIntersections.end());
		}
		return totalIntersections;
	}
	
	template<xieite::concepts::LinearShape LinearShape>
	constexpr std::vector<xieite::geometry::Point> intersections(const LinearShape& linearShape, const xieite::geometry::Point point) noexcept {
		return xieite::geometry::intersections(point, linearShape);
	}

	template<xieite::concepts::LinearShape LinearShape1, xieite::concepts::LinearShape LinearShape2>
	constexpr std::vector<xieite::geometry::Point> intersections(const LinearShape1& linearShape1, const LinearShape2& linearShape2) noexcept {
		const double foo = (linearShape1.start.x - linearShape1.end.x) * (linearShape2.start.y - linearShape2.end.y) - (linearShape1.start.y - linearShape1.end.y) * (linearShape2.start.x - linearShape2.end.x);
		if (!xieite::math::almostEqual(foo, 0)) {
			const xieite::geometry::Point bar = xieite::geometry::Point(((linearShape2.start.x - linearShape2.end.x) * (linearShape1.start.x * linearShape1.end.y - linearShape1.start.y * linearShape1.end.x) - (linearShape1.start.x - linearShape1.end.x) * (linearShape2.start.x * linearShape2.end.y - linearShape2.start.y * linearShape2.end.x)) / foo, ((linearShape2.start.y - linearShape2.end.y) * (linearShape1.start.x * linearShape1.end.y - linearShape1.start.y * linearShape1.end.x) - (linearShape1.start.y - linearShape1.end.y) * (linearShape2.start.x * linearShape2.end.y - linearShape2.start.y * linearShape2.end.x)) / foo);
			if (linearShape1.containsPoint(bar) && linearShape2.containsPoint(bar)) {
				return std::vector<xieite::geometry::Point> {
					bar
				};
			}
		}
		return std::vector<xieite::geometry::Point>();
	}

	template<xieite::concepts::LinearShape LinearShape>
	constexpr std::vector<xieite::geometry::Point> intersections(const LinearShape& linearShape, const xieite::geometry::Polygon& polygon) noexcept {
		std::vector<xieite::geometry::Point> totalIntersections;
		for (const xieite::geometry::Segment& side : polygon.sides()) {
			const std::vector<xieite::geometry::Point> localIntersections = xieite::geometry::intersections(linearShape, side);
			totalIntersections.insert(totalIntersections.end(), localIntersections.begin(), localIntersections.end());
		}
		return totalIntersections;
	}

	constexpr std::vector<xieite::geometry::Point> intersections(const xieite::geometry::Polygon& polygon, const xieite::geometry::Point point) noexcept {
		return xieite::geometry::intersections(point, polygon);
	}

	template<xieite::concepts::LinearShape LinearShape>
	constexpr std::vector<xieite::geometry::Point> intersections(const xieite::geometry::Polygon& polygon, const LinearShape& linearShape) noexcept {
		return xieite::geometry::intersections(linearShape, polygon);
	}

	constexpr std::vector<xieite::geometry::Point> intersections(const xieite::geometry::Polygon& polygon1, const xieite::geometry::Polygon& polygon2) noexcept {
		std::vector<xieite::geometry::Point> totalIntersections;
		const std::vector<xieite::geometry::Segment> sides2 = polygon2.sides();
		for (const xieite::geometry::Segment& side1 : polygon1.sides()) {
			for (const xieite::geometry::Segment& side2 : sides2) {
				const std::vector<xieite::geometry::Point> localIntersections = xieite::geometry::intersections(side1, side2);
				totalIntersections.insert(totalIntersections.end(), localIntersections.begin(), localIntersections.end());
			}
		}
		return totalIntersections;
	}
}

#endif
