#pragma once

#include <iterator>
#include <span>
#include <vector>
#include <xieite/algorithms/sameRelativeOrder.hpp>
#include <xieite/geometry/Point.hpp>

namespace xieite::geometry {
	struct Polygon final {
		std::vector<xieite::geometry::Point> points;

		constexpr Polygon(std::span<const xieite::geometry::Point> points) noexcept
		: points(std::vector<xieite::geometry::Point>(points.begin(), points.end())) {}

		[[nodiscard]]
		constexpr bool operator==(const xieite::geometry::Polygon& polygon) const noexcept {
			return xieite::algorithms::sameRelativeOrder(std::begin(this->points), std::end(this->points), std::begin(polygon.points), std::end(polygon.points)) || xieite::algorithms::sameRelativeOrder(std::rbegin(this->points), std::rend(this->points), std::begin(polygon.points), std::end(polygon.points));
		}
	};
}
