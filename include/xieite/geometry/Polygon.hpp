#ifndef XIEITE_HEADER_GEOMETRY_POLYGON
#	define XIEITE_HEADER_GEOMETRY_POLYGON

#	include <iterator>
#	include <vector>
#	include <xieite/algorithms/sameRelativeOrder.hpp>
#	include <xieite/concepts/RangeOf.hpp>
#	include <xieite/geometry/Point.hpp>

namespace xieite::geometry {
	struct Polygon final {
		std::vector<xieite::geometry::Point> points;

		constexpr Polygon(const xieite::concepts::RangeOf<xieite::geometry::Point> auto& points) noexcept
		: points(points.begin(), points.end()) {}

		[[nodiscard]]
		constexpr bool operator==(const xieite::geometry::Polygon& polygon) const noexcept {
			return xieite::algorithms::sameRelativeOrder(this->points, polygon.points) || xieite::algorithms::sameRelativeOrder(std::vector<xieite::geometry::Point>(std::rbegin(this->points), std::rend(this->points)), polygon.points);
		}
	};
}

#endif
