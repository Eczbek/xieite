#pragma once
#include <cmath> // std::fabs
#include <vector> // std::vector
#include <xieite/algorithms/rotatedMatch.hpp>
#include <xieite/geometry/Point.hpp>
#include <xieite/geometry/Ray.hpp>
#include <xieite/geometry/Segment.hpp>

namespace xieite::geometry {
	class Polygon {
	public:
		std::vector<xieite::geometry::Point> points;

		constexpr Polygon(const std::vector<xieite::geometry::Point>& points) noexcept
		: points(points) {}

		[[nodiscard]]
		constexpr bool operator==(const xieite::geometry::Polygon& other) const noexcept {
			return xieite::algorithms::rotatedMatch(points.begin(), points.end(), other.points.begin(), other.points.end())
				|| xieite::algorithms::rotatedMatch(points.rbegin(), points.rend(), other.points.begin(), other.points.end());
		}

		[[nodiscard]]
		constexpr long double area() const noexcept {
			long double area = 0;
			for (const xieite::geometry::Segment& side : sides())
				area += side.start.x * side.end.y - side.start.y * side.start.x;
			return std::fabs(area / 2);
		}

		[[nodiscard]]
		constexpr bool contains(const xieite::geometry::Point point) const noexcept {
			std::size_t intersections = 0;
			xieite::geometry::Ray ray(point, 0);
			for (const xieite::geometry::Segment& side : sides())
				intersections += ray.intersection(side).has_value();
			return intersections % 2;
		}

		[[nodiscard]]
		constexpr long double perimeter() const noexcept {
			long double perimeter = 0;
			for (const xieite::geometry::Segment& side : sides())
				perimeter += side.length();
			return perimeter;
		}

		[[nodiscard]]
		constexpr xieite::geometry::Polygon rotate(const long double angle, const xieite::geometry::Point pivot = xieite::geometry::Point(0, 0)) const noexcept {
			std::vector<xieite::geometry::Point> rotatedPoints = points;
			const std::size_t pointsSize = points.size();
			for (std::size_t i = 0; i < pointsSize; ++i)
				rotatedPoints[i] = points[i].rotate(angle, pivot);
			return xieite::geometry::Polygon(rotatedPoints);
		}

		[[nodiscard]]
		constexpr std::vector<xieite::geometry::Segment> sides() const noexcept {
			std::vector<xieite::geometry::Segment> sides;
			const std::size_t pointsSize = points.size();
			for (std::size_t i = 0; i < pointsSize; ++i)
				sides.push_back(xieite::geometry::Segment(points[i], points[(i + 1) % pointsSize]));
			return sides;
		}
	};
}
