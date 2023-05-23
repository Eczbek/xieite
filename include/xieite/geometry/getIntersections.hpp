#ifndef XIEITE_HEADER_GEOMETRY_GETINTERSECTIONS
#	define XIEITE_HEADER_GEOMETRY_GETINTERSECTIONS

#	include <cmath>
#	include <vector>
#	include <xieite/concepts/LinearShape.hpp>
#	include <xieite/geometry/Point.hpp>
#	include <xieite/geometry/Segment.hpp>
#	include <xieite/geometry/containsPoint.hpp>
#	include <xieite/geometry/getDistance.hpp>
#	include <xieite/geometry/getSides.hpp>
#	include <xieite/geometry/rotate.hpp>
#	include <xieite/math/approximatelyEqual.hpp>

namespace xieite::geometry {
	[[nodiscard]]
	constexpr std::vector<xieite::geometry::Point> getIntersections(const xieite::geometry::Point point1, const xieite::geometry::Point point2) noexcept {
		std::vector<xieite::geometry::Point> intersections;
		if (point1 == point2) {
			intersections.push_back(point1);
		}
		return intersections;
	}

	[[nodiscard]]
	constexpr std::vector<xieite::geometry::Point> getIntersections(const xieite::geometry::Point point, const xieite::concepts::LinearShape auto& linearShape) noexcept {
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
	
	[[nodiscard]]
	constexpr std::vector<xieite::geometry::Point> getIntersections(const xieite::concepts::LinearShape auto& linearShape, const xieite::geometry::Point point) noexcept {
		return xieite::geometry::getIntersections(point, linearShape);
	}

	[[nodiscard]]
	constexpr std::vector<xieite::geometry::Point> getIntersections(const xieite::concepts::LinearShape auto& linearShape1, const xieite::concepts::LinearShape auto& linearShape2) noexcept {
		std::vector<xieite::geometry::Point> intersections;
		const double a = (linearShape1.start.x - linearShape1.end.x) * (linearShape2.start.y - linearShape2.end.y) - (linearShape1.start.y - linearShape1.end.y) * (linearShape2.start.x - linearShape2.end.x);
		if (!xieite::math::approximatelyEqual(a, 0.0)) {
			const xieite::geometry::Point intersection(((linearShape2.start.x - linearShape2.end.x) * (linearShape1.start.x * linearShape1.end.y - linearShape1.start.y * linearShape1.end.x) - (linearShape1.start.x - linearShape1.end.x) * (linearShape2.start.x * linearShape2.end.y - linearShape2.start.y * linearShape2.end.x)) / a, ((linearShape2.start.y - linearShape2.end.y) * (linearShape1.start.x * linearShape1.end.y - linearShape1.start.y * linearShape1.end.x) - (linearShape1.start.y - linearShape1.end.y) * (linearShape2.start.x * linearShape2.end.y - linearShape2.start.y * linearShape2.end.x)) / a);
			if (xieite::geometry::containsPoint(linearShape1, intersection) && xieite::geometry::containsPoint(linearShape2, intersection)) {
				intersections.push_back(intersection);
			}
		}
		return intersections;
	}

	[[nodiscard]]
	constexpr std::vector<xieite::geometry::Point> getIntersections(const xieite::concepts::LinearShape auto& linearShape, const xieite::geometry::Polygon& polygon) noexcept {
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

	[[nodiscard]]
	constexpr std::vector<xieite::geometry::Point> getIntersections(const xieite::geometry::Polygon& polygon, const xieite::concepts::LinearShape auto& linearShape) noexcept {
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
