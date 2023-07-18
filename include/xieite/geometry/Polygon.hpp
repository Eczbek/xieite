#ifndef XIEITE_HEADER_GEOMETRY_POLYGON
#	define XIEITE_HEADER_GEOMETRY_POLYGON

#	include <ranges>
#	include <vector>
#	include <xieite/algorithms/sameRelativeOrder.hpp>
#	include <xieite/concepts/RangeOf.hpp>
#	include <xieite/geometry/Point.hpp>

namespace xieite::geometry {
	struct Polygon {
		std::vector<xieite::geometry::Point> points;

		constexpr Polygon(const xieite::concepts::RangeOf<xieite::geometry::Point> auto& points) noexcept
		: points(std::ranges::begin(points), std::ranges::end(points)) {}

		[[nodiscard]]
		constexpr bool operator==(const xieite::geometry::Polygon& polygon) const noexcept {
			return xieite::algorithms::sameRelativeOrder(this->points, polygon.points) || xieite::algorithms::sameRelativeOrder(std::vector<xieite::geometry::Point>(std::ranges::rbegin(this->points), std::ranges::rend(this->points)), polygon.points);
		}
	};
}

#endif
