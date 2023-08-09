#ifndef XIEITE_HEADER__GEOMETRY__POLYGON
#	define XIEITE_HEADER__GEOMETRY__POLYGON

#	include <ranges>
#	include <vector>
#	include "../algorithms/sameRelativeOrder.hpp"
#	include "../concepts/RangeOf.hpp"
#	include "../geometry/Point.hpp"

namespace xieite::geometry {
	struct Polygon {
		std::vector<xieite::geometry::Point> points;

		template<xieite::concepts::RangeOf<xieite::geometry::Point> PointRange>
		constexpr Polygon(const PointRange& points) noexcept
		: points(std::ranges::begin(points), std::ranges::end(points)) {}

		constexpr bool operator==(const xieite::geometry::Polygon& polygon) const noexcept {
			return xieite::algorithms::sameRelativeOrder(this->points, polygon.points) || xieite::algorithms::sameRelativeOrder(std::vector<xieite::geometry::Point>(this->points.rbegin(), this->points.rend()), polygon.points);
		}
	};
}

#endif
