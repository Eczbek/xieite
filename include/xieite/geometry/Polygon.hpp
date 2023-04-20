#pragma once

#include <iterator>
#include <vector>
#include <xieite/algorithms/rotatedMatch.hpp>
#include <xieite/geometry/Point.hpp>

namespace xieite::geometry {
	struct Polygon {
		std::vector<xieite::geometry::Point> points;

		constexpr Polygon(const std::vector<xieite::geometry::Point>& points) noexcept
		: points(points) {}

		[[nodiscard]]
		constexpr bool operator==(const xieite::geometry::Polygon& polygon) const noexcept {
			return xieite::algorithms::rotatedMatch(std::begin(this->points), std::end(this->points), std::begin(polygon.points), std::end(polygon.points)) || xieite::algorithms::rotatedMatch(std::rbegin(this->points), std::rend(this->points), std::begin(polygon.points), std::end(polygon.points));
		}
	};
}
