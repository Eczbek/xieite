#pragma once
#include <vector> // std::vector
#include <xieite/algorithms/rotatedMatch.hpp>
#include <xieite/geometry/Point.hpp>

namespace xieite::geometry {
	struct Polygon {
		std::vector<xieite::geometry::Point> points;

		constexpr Polygon(const std::vector<xieite::geometry::Point>& points) noexcept
		: points(points) {}

		[[nodiscard]]
		constexpr bool operator==(const xieite::geometry::Polygon& other) const noexcept {
			return xieite::algorithms::rotatedMatch(points.begin(), points.end(), other.points.begin(), other.points.end()) || xieite::algorithms::rotatedMatch(points.rbegin(), points.rend(), other.points.begin(), other.points.end());
		}
	};
}
