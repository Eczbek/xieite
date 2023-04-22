#pragma once

#include <cmath>
#include <optional>
#include <vector>
#include <xieite/concepts/LinearShape.hpp>
#include <xieite/geometry/Ellipse.hpp>
#include <xieite/geometry/Point.hpp>
#include <xieite/geometry/Segment.hpp>
#include <xieite/geometry/containsPoint.hpp>
#include <xieite/geometry/getDistance.hpp>
#include <xieite/geometry/getIntersection.hpp>
#include <xieite/geometry/getSides.hpp>
#include <xieite/geometry/rotate.hpp>
#include <xieite/math/approximatelyEqual.hpp>

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
	constexpr std::vector<xieite::geometry::Point> getIntersections(const xieite::geometry::Point point, const xieite::geometry::Circle& circle) noexcept {
		std::vector<xieite::geometry::Point> intersections;
		if (xieite::math::approximatelyEqual(xieite::geometry::getDistance(point, circle.center), circle.radius)) {
			intersections.push_back(point);
		}
		return intersections;
	}

	[[nodiscard]]
	constexpr std::vector<xieite::geometry::Point> getIntersections(const xieite::geometry::Point point, const xieite::geometry::Ellipse& ellipse) noexcept {
		std::vector<xieite::geometry::Point> intersections1;
		std::vecotr<xieite::geometry::Point> intersections2 = xieite::geometry::getIntersections(xieite::geometry::Ray(point, ellipse.center), ellipse);
		if ((intersections2.size() && (intersections2[0] == point)) || ((intersections2.size() > 1) && (intersections2[1] == point))) {
			intersections1.push_back(point);
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
			const std::vector<xieite::geometry::Point> intersections2 = xieite::geometry::getIntersection(linearShape, side);
			if (intersections2.size()) {
				intersections1.push_back(intersections2[0]);
			}
		}
		return intersections1;
	}

	[[nodiscard]]
	constexpr std::vector<xieite::geometry::Point> getIntersections(const xieite::concepts::LinearShape auto& linearShape, const xieite::geometry::Circle& circle) noexcept {
		return xieite::geometry::getIntersections(linearShape, xieite::geometry::Ellipse(circle.center, xieite::geometry::Point(circle.radius, circle.radius)));
	}

	[[nodiscard]]
	constexpr std::vector<xieite::geometry::Point> getIntersections(const xieite::concepts::LinearShape auto& linearShape, const xieite::geometry::Ellipse& ellipse) noexcept {
		std::vector<xieite::geometry::Point> intersections;
		const xieite::geometry::Point start = xieite::geometry::rotate(xieite::geometry::Point(linearShape.start.x - ellipse.center.x, linearShape.start.y - ellipse.center.y), ellipse.rotation);
		const xieite::geometry::Point end = xieite::geometry::rotate(xieite::geometry::Point(linearShape.end.x - ellipse.center.x, linearShape.end.y - ellipse.center.y), ellipse.rotation);
		const double a = ellipse.radii.y * ellipse.radii.y * (end.x - start.x) * (end.x - start.x) + ellipse.radii.x * ellipse.radii.x * (end.y - start.y) * (end.y - start.y);
		const double b = 2.0 * ellipse.radii.y * ellipse.radii.y * start.x * (end.x - start.x) + 2.0 * ellipse.radii.x * ellipse.radii.x * start.y * (end.y - start.y);
		const double c = ellipse.radii.y * ellipse.radii.y * start.x * start.x + ellipse.radii.x * ellipse.radii.x * start.y * start.y - ellipse.radii.y * ellipse.radii.y * ellipse.radii.x * ellipse.radii.x;
		const double d = b * b - 4.0 * a * c;
		if (d >= 0.0) {
			const double e = (-b + std::sqrt(d)) / 2.0 / a;
			const double f = (-b - std::sqrt(d)) / 2.0 / a;
			const xieite::geometry::Point g = xieite::geometry::rotate(xieite::geometry::Point(start.x + e * (end.x - start.x), start.y + e * (end.y - start.y)), -ellipse.rotation);
			intersections.push_back(xieite::geometry::Point(g.x + ellipse.center.x, g.y + ellipse.center.y));
			const xieite::geometry::Point h = xieite::geometry::rotate(xieite::geometry::Point(start.x + f * (end.x - start.x), start.y + f * (end.y - start.y)), -ellipse.rotation);
			intersections.push_back(xieite::geometry::Point(h.x + ellipse.center.x, h.y + ellipse.center.y));
		}
		return intersections;
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
		std::vector<xieite::geometry::Point> intersections;
		for (const xieite::geometry::Segment& side1 : xieite::geometry::getSides(polygon1)) {
			for (const xieite::geometry::Segment& side2 : xieite::geometry::getSides(polygon2)) {
				const std::optional<xieite::geometry::Point> intersection = xieite::geometry::getIntersection(side1, side2);
				if (intersection.has_value()) {
					intersections.push_back(intersection.value());
				}
			}
		}
		return intersections;
	}

	[[nodiscard]]
	constexpr std::vector<xieite::geometry::Point> getIntersections(const xieite::geometry::Polygon& polygon, const xieite::geometry::Circle& circle) noexcept {
		std::vector<xieite::geometry::Point> intersections1;
		for (const xieite::geometry::Segment& side : xieite::geometry::getSides(polygon)) {
			const std::vector<xieite::geometry::Point> intersections2 = xieite::geometry::getIntersections(side, circle);
			if (intersections2.size()) {
				intersections1.push_back(intersections2[0]);
			}
		}
		return intersections1;
	}

	[[nodiscard]]
	constexpr std::vector<xieite::geometry::Point> getIntersections(const xieite::geometry::Polygon& polygon, const xieite::geometry::Ellipse& ellipse) noexcept {
		std::vector<xieite::geometry::Point> intersections1;
		for (const xieite::geometry::Segment& side : xieite::geometry::getSides(polygon)) {
			const std::vector<xieite::geometry::Point> intersections2 = xieite::geometry::getIntersections(side, ellipse);
			if (intersections2.size()) {
				intersections1.push_back(intersections2[0]);
			}
		}
		return intersections1;
	}

	[[nodiscard]]
	constexpr std::vector<xieite::geometry::Point> getIntersections(const xieite::geometry::Circle& circle, const xieite::geometry::Point point) noexcept {
		return xieite::geometry::getIntersections(point, circle);
	}

	[[nodiscard]]
	constexpr std::vector<xieite::geometry::Point> getIntersections(const xieite::geometry::Circle& circle, const xieite::concepts::LinearShape auto& linearShape) noexcept {
		return xieite::geometry::getIntersections(linearShape, circle);
	}

	[[nodiscard]]
	constexpr std::vector<xieite::geometry::Point> getIntersections(const xieite::geometry::Circle& circle, const xieite::geometry::Polygon& polygon) noexcept {
		return xieite::geometry::getIntersections(polygon, circle);
	}

	[[nodiscard]]
	constexpr std::vector<xieite::geometry::Point> getIntersections(const xieite::geometry::Circle& circle, const xieite::geometry::Circle& circle) noexcept {
		return std::vector<xieite::geometry::Point> {}; // TODO
	}

	[[nodiscard]]
	constexpr std::vector<xieite::geometry::Point> getIntersections(const xieite::geometry::Circle& circle, const xieite::geometry::Ellipse& ellipse) noexcept {
		return std::vector<xieite::geometry::Point> {}; // TODO
	}

	[[nodiscard]]
	constexpr std::vector<xieite::geometry::Point> getIntersections(const xieite::geometry::Ellipse& ellipse, const xieite::geometry::Point point) noexcept {
		return xieite::geometry::getIntersections(point, ellipse);
	}

	[[nodiscard]]
	constexpr std::vector<xieite::geometry::Point> getIntersections(const xieite::geometry::Ellipse& ellipse, const xieite::concepts::LinearShape auto& linearShape) noexcept {
		return xieite::geometry::getIntersections(linearShape, ellipse);
	}

	[[nodiscard]]
	constexpr std::vector<xieite::geometry::Point> getIntersections(const xieite::geometry::Ellipse& ellipse, const xieite::geometry::Polygon& polygon) noexcept {
		return xieite::geometry::getIntersections(polygon, ellipse);
	}

	[[nodiscard]]
	constexpr std::vector<xieite::geometry::Point> getIntersections(const xieite::geometry::Ellipse& ellipse, const xieite::geometry::Circle& circle) noexcept {
		return xieite::geometry::getIntersections(circle, ellipse);
	}

	[[nodiscard]]
	constexpr std::vector<xieite::geometry::Point> getIntersections(const xieite::geometry::Ellipse& ellipse, const xieite::geometry::Ellipse& ellipse) noexcept {
		return std::vector<xieite::geometry::Point> {}; // TODO
	}
}
