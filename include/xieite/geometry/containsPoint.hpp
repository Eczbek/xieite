#pragma once

#include <cmath>
#include <cstddef>
#include <xieite/geometry/Circle.hpp>
#include <xieite/geometry/Ellipse.hpp>
#include <xieite/geometry/Line.hpp>
#include <xieite/geometry/Point.hpp>
#include <xieite/geometry/Polygon.hpp>
#include <xieite/geometry/Ray.hpp>
#include <xieite/geometry/Segment.hpp>
#include <xieite/geometry/getDistance.hpp>
#include <xieite/geometry/getSides.hpp>
#include <xieite/geometry/getSlope.hpp>
#include <xieite/math/approximatelyEqual.hpp>

namespace xieite::geometry {
	[[nodiscard]]
	constexpr bool containsPoint(const xieite::geometry::Point point1, const xieite::geometry::Point point2) noexcept {
		return point1 == point2;
	}

	[[nodiscard]]
	constexpr bool containsPoint(const xieite::geometry::Line& line, const xieite::geometry::Point point) noexcept {
		const double slope = xieite::geometry::getSlope(line);
		return std::isinf(slope) ? xieite::math::approximatelyEqual(point.x, line.start.x) : xieite::math::approximatelyEqual(point.x * slope - line.start.x * slope + line.start.y, point.y);
	}

	[[nodiscard]]
	constexpr bool containsPoint(const xieite::geometry::Ray& ray, const xieite::geometry::Point point) noexcept {
		const double slope = xieite::geometry::getSlope(ray);
		return std::isinf(slope) ? (xieite::math::approximatelyEqual(point.x, ray.start.x) && (slope < std::numeric_limits<double>::lowest()) ? (point.y >= ray.start.y) : (point.y <= ray.start.y)) : (xieite::math::approximatelyEqual(point.x * slope - ray.start.x * slope + ray.start.y, point.y) && ((ray.start.x <= ray.end.x) ? (point.x >= ray.start.x) : (point.x <= ray.start.x)) && ((ray.start.y <= ray.end.y) ? (point.y >= ray.start.y) : (point.y <= ray.start.y)));
	}

	[[nodiscard]]
	constexpr bool containsPoint(const xieite::geometry::Segment& segment, const xieite::geometry::Point point) noexcept {
		const double slope = xieite::geometry::getSlope(segment);
		return std::isinf(slope) ? (xieite::math::approximatelyEqual(point.x, segment.start.x) && ((point.y >= segment.start.y) && (point.y <= segment.end.y) || (point.y <= segment.start.y) && (point.y >= segment.end.y))) : (xieite::math::approximatelyEqual(point.x * slope - segment.start.x * slope + segment.start.y, point.y) && ((segment.start.x < segment.end.x) ? (point.x >= segment.start.x) && (point.x <= segment.end.x) : (point.x <= segment.start.x) && (point.x >= segment.end.x)) && ((segment.start.y < segment.end.y) ? (point.y >= segment.start.y) && (point.y <= segment.end.y) : (point.y <= segment.start.y) && (point.y >= segment.end.y)));
	}

	[[nodiscard]]
	constexpr bool containsPoint(const xieite::geometry::Polygon& polygon, const xieite::geometry::Point point) noexcept {
		std::size_t intersections = 0;
		xieite::geometry::Ray ray(point, 0.0);
		for (const xieite::geometry::Segment& side : xieite::geometry::getSides(polygon)) {
			const double a = (ray.start.x - ray.end.x) * (side.start.y - side.end.y) - (ray.start.y - ray.end.y) * (side.start.x - side.end.x);
			if (!xieite::math::approximatelyEqual(a, 0.0)) {
				const xieite::geometry::Point intersection(((side.start.x - side.end.x) * (ray.start.x * ray.end.y - ray.start.y * ray.end.x) - (ray.start.x - ray.end.x) * (side.start.x * side.end.y - side.start.y * side.end.x)) / a, ((side.start.y - side.end.y) * (ray.start.x * ray.end.y - ray.start.y * ray.end.x) - (ray.start.y - ray.end.y) * (side.start.x * side.end.y - side.start.y * side.end.x)) / a);
				intersections += (xieite::geometry::containsPoint(ray, intersection) && xieite::geometry::containsPoint(side, intersection));
			}
		}
		return intersections % 2;
	}

	[[nodiscard]]
	constexpr bool containsPoint(const xieite::geometry::Ellipse& ellipse, const xieite::geometry::Point point) noexcept {
		const double a = std::cos(ellipse.rotation) * (point.x - ellipse.center.x) + std::sin(ellipse.rotation) * (point.y - ellipse.center.y);
		const double b = std::sin(ellipse.rotation) * (point.x - ellipse.center.x) - std::cos(ellipse.rotation) * (point.y - ellipse.center.y);
		return (a * a / ellipse.radii.x / ellipse.radii.x + b * b / ellipse.radii.y / ellipse.radii.y) <= 1.0;
	}

	[[nodiscard]]
	constexpr bool containsPoint(const xieite::geometry::Circle& circle, const xieite::geometry::Point point) noexcept {
		return xieite::geometry::getDistance(circle.center, point) <= circle.radius;
	}
}
