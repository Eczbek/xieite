#pragma once
#include <concepts> // std::derived_from
#include <optional> // std::optional
#include <vector> // std::vector
#include <xieite/geometry/Ellipse.hpp>
#include <xieite/geometry/LineLike.hpp>
#include <xieite/geometry/Point.hpp>
#include <xieite/geometry/Segment.hpp>
#include <xieite/geometry/getIntersection.hpp>
#include <xieite/geometry/getSides.hpp>
#include <xieite/geometry/rotate.hpp>
#include <xieite/math/squareRoot.hpp>

namespace xieite::geometry {
	template<std::derived_from<xieite::geometry::LineLike> L>
	[[nodiscard]]
	constexpr std::vector<xieite::geometry::Point> getIntersections(const xieite::geometry::Polygon& polygon, const L& lineLike) noexcept {
		std::vector<xieite::geometry::Point> intersections;
		for (const xieite::geometry::Segment& side : xieite::geometry::getSides(polygon)) {
			const std::optional<xieite::geometry::Point> intersection = xieite::geometry::getIntersection(lineLike, side);
			if (intersection.has_value())
				intersections.push_back(intersection.value());
		}
		return intersections;
	}

	template<std::derived_from<xieite::geometry::LineLike> L>
	[[nodiscard]]
	constexpr std::vector<xieite::geometry::Point> getIntersections(const L& lineLike, const xieite::geometry::Polygon& polygon) noexcept {
		return xieite::geometry::getIntersections(polygon, lineLike);
	}

	[[nodiscard]]
	constexpr std::vector<xieite::geometry::Point> getIntersections(const xieite::geometry::Polygon& polygon1, const xieite::geometry::Polygon& polygon2) noexcept {
		std::vector<xieite::geometry::Point> intersections;
		for (const xieite::geometry::Segment& side1 : xieite::geometry::getSides(polygon1))
			for (const xieite::geometry::Segment& side2 : xieite::geometry::getSides(polygon2)) {
				const std::optional<xieite::geometry::Point> intersection = xieite::geometry::getIntersection(side1, side2);
				if (intersection.has_value())
					intersections.push_back(intersection.value());
			}
		return intersections;
	}

	template<std::derived_from<xieite::geometry::LineLike> L>
	[[nodiscard]]
	constexpr std::vector<xieite::geometry::Point> getIntersections(const xieite::geometry::Ellipse& ellipse, const L& lineLike) noexcept {
		const xieite::geometry::Point start = xieite::geometry::rotate(xieite::geometry::Point(lineLike.start.x - ellipse.center.x, lineLike.start.y - ellipse.center.y), ellipse.rotation);
		const xieite::geometry::Point end = xieite::geometry::rotate(xieite::geometry::Point(lineLike.end.x - ellipse.center.x, lineLike.end.y - ellipse.center.y), ellipse.rotation);
		const double a = ellipse.radii.y * ellipse.radii.y * (end.x - start.x) * (end.x - start.x) + ellipse.radii.x * ellipse.radii.x * (end.y - start.y) * (end.y - start.y);
		const double b = 2 * ellipse.radii.y * ellipse.radii.y * start.x * (end.x - start.x) + 2 * ellipse.radii.x * ellipse.radii.x * start.y * (end.y - start.y);
		const double c = ellipse.radii.y * ellipse.radii.y * start.x * start.x + ellipse.radii.x * ellipse.radii.x * start.y * start.y - ellipse.radii.y * ellipse.radii.y * ellipse.radii.x * ellipse.radii.x;
		const double d = b * b - 4 * a * c;
		if (d >= 0) {
			const double e = (-b + xieite::math::squareRoot(d)) / 2 / a;
			const double f = (-b - xieite::math::squareRoot(d)) / 2 / a;
			const xieite::geometry::Point g = xieite::geometry::rotate(xieite::geometry::Point(start.x + e * (end.x - start.x), start.y + e * (end.y - start.y)), -ellipse.rotation);
			const xieite::geometry::Point h = xieite::geometry::rotate(xieite::geometry::Point(start.x + f * (end.x - start.x), start.y + f * (end.y - start.y)), -ellipse.rotation);
			return std::vector<xieite::geometry::Point>({
				xieite::geometry::Point(g.x + ellipse.center.x, g.y + ellipse.center.y),
				xieite::geometry::Point(h.x + ellipse.center.x, h.y + ellipse.center.y)
			});
		}
		return std::vector<xieite::geometry::Point>();
	}

	template<std::derived_from<xieite::geometry::LineLike> L>
	[[nodiscard]]
	constexpr std::vector<xieite::geometry::Point> getIntersections(const L& lineLike, const xieite::geometry::Ellipse& ellipse) noexcept {
		return xieite::geometry::getIntersections(ellipse, lineLike);
	}

	template<std::derived_from<xieite::geometry::LineLike> L>
	[[nodiscard]]
	constexpr std::vector<xieite::geometry::Point> getIntersections(const xieite::geometry::Circle& circle, const L& lineLike) noexcept {
		return xieite::geometry::getIntersections(xieite::geometry::Ellipse(circle.center, xieite::geometry::Point(circle.radius, circle.radius)), lineLike);
	}

	template<std::derived_from<xieite::geometry::LineLike> L>
	[[nodiscard]]
	constexpr std::vector<xieite::geometry::Point> getIntersections(const L& lineLike, const xieite::geometry::Circle& circle) noexcept {
		return xieite::geometry::getIntersections(circle, lineLike);
	}
}
