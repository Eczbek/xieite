#ifndef XIEITE_HEADER_GEOMETRY_GETINTERSECTIONS
#	define XIEITE_HEADER_GEOMETRY_GETINTERSECTIONS

#	include <cmath>
#	include <vector>
#	include "../concepts/LinearShape.hpp"
#	include "../geometry/Point.hpp"
#	include "../geometry/Segment.hpp"
#	include "../geometry/containsPoint.hpp"
#	include "../geometry/getDistance.hpp"
#	include "../geometry/getSides.hpp"
#	include "../math/almostEqual.hpp"

namespace xieite::geometry {
	[[nodiscard]]
	constexpr std::vector<xieite::geometry::Point> getIntersections(const xieite::geometry::Point point1, const xieite::geometry::Point point2) noexcept {
		std::vector<xieite::geometry::Point> intersections;
		if (point1 == point2) {
			intersections.push_back(point1);
		}
		return intersections;
	}

	template<xieite::concepts::LinearShape LinearShape>
	[[nodiscard]]
	constexpr std::vector<xieite::geometry::Point> getIntersections(const xieite::geometry::Point point, const LinearShape& linearShape) noexcept {
		std::vector<xieite::geometry::Point> intersections;
		if (xieite::geometry::containsPoint(linearShape, point)) {
			intersections.push_back(point);
		}
		return intersections;
	}

	[[nodiscard]]
	constexpr std::vector<xieite::geometry::Point> getIntersections(const xieite::geometry::Point point, const xieite::geometry::Polygon& polygon) noexcept {
		std::vector<xieite::geometry::Point> intersections1;
		for (const xieite::geometry::Segment& side : xieite::geometry::getSides(polygon)) {
			const std::vector<xieite::geometry::Point> intersections2 = xieite::geometry::getIntersections(point, side);
			if (intersections2.size()) {
				intersections1.push_back(intersections2[0]);
			}
		}
		return intersections1;
	}
	
	template<xieite::concepts::LinearShape LinearShape>
	[[nodiscard]]
	constexpr std::vector<xieite::geometry::Point> getIntersections(const LinearShape& linearShape, const xieite::geometry::Point point) noexcept {
		return xieite::geometry::getIntersections(point, linearShape);
	}

	template<xieite::concepts::LinearShape LinearShape1, xieite::concepts::LinearShape LinearShape2>
	[[nodiscard]]
	constexpr std::vector<xieite::geometry::Point> getIntersections(const LinearShape1& linearShape1, const LinearShape2& linearShape2) noexcept {
		std::vector<xieite::geometry::Point> intersections;
		const double a = (linearShape1.start.x - linearShape1.end.x) * (linearShape2.start.y - linearShape2.end.y) - (linearShape1.start.y - linearShape1.end.y) * (linearShape2.start.x - linearShape2.end.x);
		if (!xieite::math::almostEqual(a, 0)) {
			const xieite::geometry::Point intersection = xieite::geometry::Point(((linearShape2.start.x - linearShape2.end.x) * (linearShape1.start.x * linearShape1.end.y - linearShape1.start.y * linearShape1.end.x) - (linearShape1.start.x - linearShape1.end.x) * (linearShape2.start.x * linearShape2.end.y - linearShape2.start.y * linearShape2.end.x)) / a, ((linearShape2.start.y - linearShape2.end.y) * (linearShape1.start.x * linearShape1.end.y - linearShape1.start.y * linearShape1.end.x) - (linearShape1.start.y - linearShape1.end.y) * (linearShape2.start.x * linearShape2.end.y - linearShape2.start.y * linearShape2.end.x)) / a);
			if (xieite::geometry::containsPoint(linearShape1, intersection) && xieite::geometry::containsPoint(linearShape2, intersection)) {
				intersections.push_back(intersection);
			}
		}
		return intersections;
	}
	// I will NEVER be debugging this code again

	template<xieite::concepts::LinearShape LinearShape>
	[[nodiscard]]
	constexpr std::vector<xieite::geometry::Point> getIntersections(const LinearShape& linearShape, const xieite::geometry::Polygon& polygon) noexcept {
		std::vector<xieite::geometry::Point> intersections1;
		for (const xieite::geometry::Segment& side : xieite::geometry::getSides(polygon)) {
			const std::vector<xieite::geometry::Point> intersections2 = xieite::geometry::getIntersections(linearShape, side);
			if (intersections2.size()) {
				intersections1.push_back(intersections2[0]);
			}
		}
		return intersections1;
	}

	[[nodiscard]]
	constexpr std::vector<xieite::geometry::Point> getIntersections(const xieite::geometry::Polygon& polygon, const xieite::geometry::Point point) noexcept {
		return xieite::geometry::getIntersections(point, polygon);
	}

	template<xieite::concepts::LinearShape LinearShape>
	[[nodiscard]]
	constexpr std::vector<xieite::geometry::Point> getIntersections(const xieite::geometry::Polygon& polygon, const LinearShape& linearShape) noexcept {
		return xieite::geometry::getIntersections(linearShape, polygon);
	}

	[[nodiscard]]
	constexpr std::vector<xieite::geometry::Point> getIntersections(const xieite::geometry::Polygon& polygon1, const xieite::geometry::Polygon& polygon2) noexcept {
		std::vector<xieite::geometry::Point> intersections1;
		for (const xieite::geometry::Segment& side1 : xieite::geometry::getSides(polygon1)) {
			for (const xieite::geometry::Segment& side2 : xieite::geometry::getSides(polygon2)) {
				const std::vector<xieite::geometry::Point> intersections2 = xieite::geometry::getIntersections(side1, side2);
				if (intersections2.size()) {
					intersections1.push_back(intersections2[0]);
				}
			}
		}
		return intersections1;
	}
}

#endif
