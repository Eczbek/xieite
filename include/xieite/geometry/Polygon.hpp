#pragma once

#include <vector>
#include <xieite/algorithms/rotatedMatch.hpp>
#include <xieite/geometry/Point.hpp>

namespace xieite::geometry {
	struct Polygon {
		std::vector<xieite::geometry::Point> points;

		constexpr Polygon(const std::vector<xieite::geometry::Point>& points) noexcept
		: points(points) {}

		[[nodiscard]]
		constexpr bool operator==(const xieite::geometry::Polygon& other) const noexcept {
			return xieite::algorithms::rotatedMatch(this->points.begin(), this->points.end(), other.points.begin(), other.points.end()) || xieite::algorithms::rotatedMatch(this->points.rbegin(), this->points.rend(), other.points.begin(), other.points.end());
		}
	};
}
