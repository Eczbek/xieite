#ifndef XIEITE_HEADER__GEOMETRY__POLYGON
#	define XIEITE_HEADER__GEOMETRY__POLYGON

#	include <cmath>
#	include <cstddef>
#	include <ranges>
#	include <vector>
#	include "../algorithms/sameRelativeOrder.hpp"
#	include "../concepts/RangeOf.hpp"
#	include "../geometry/Point.hpp"
#	include "../geometry/Segment.hpp"

namespace xieite::geometry {
	struct Polygon {
		std::vector<xieite::geometry::Point> points;

		template<xieite::concepts::RangeOf<xieite::geometry::Point> Range = std::vector<xieite::geometry::Point>>
		constexpr Polygon(const Range& points) noexcept
		: points(std::ranges::begin(points), std::ranges::end(points)) {}

		friend constexpr bool operator==(const xieite::geometry::Polygon& polygon1, const xieite::geometry::Polygon& polygon2) noexcept {
			return xieite::algorithms::sameRelativeOrder(polygon1.points, polygon2.points) || xieite::algorithms::sameRelativeOrder(polygon1.points, std::vector<xieite::geometry::Point>(polygon2.points.rbegin(), polygon2.points.rend()));
		}

		constexpr double area() const noexcept {
			double area = 0;
			for (const xieite::geometry::Segment& side : this->sides()) {
				area += side.start.x * side.start.y - side.start.x * side.end.y;
			}
			return std::abs(area) / 2;
		}

		constexpr bool containsPoint(const xieite::geometry::Point point) const noexcept {
			bool odd = false;
			const std::size_t pointsSize = this->points.size();
			for (std::size_t i = 0; i < pointsSize; ++i) {
				const std::size_t j = (i + 1) % pointsSize;
				odd ^= ((this->points[i].y < point.y) && (this->points[j].y >= point.y) || (this->points[j].y < point.y) && (this->points[i].y >= point.y)) && ((this->points[i].x <= point.x) || (this->points[j].x <= point.x)) && ((this->points[i].x + (point.y - this->points[i].y) / (this->points[j].y - this->points[i].y) * (this->points[j].x - this->points[i].x)) < point.x);
			}
			if (odd) {
				return true;
			}
			for (const xieite::geometry::Segment& side : this->sides()) {
				if (side.containsPoint(point)) {
					return true;
				}
			}
			return false;
		}

		constexpr double perimeter() const noexcept {
			double perimeter = 0;
			for (const xieite::geometry::Segment& side : this->sides()) {
				perimeter += side.length();
			}
			return perimeter;
		}

		constexpr std::vector<xieite::geometry::Segment> sides() const noexcept {
			const std::size_t pointsSize = this->points.size();
			std::vector<xieite::geometry::Segment> sides;
			sides.reserve(pointsSize);
			for (std::size_t i = 0; i < pointsSize; ++i) {
				sides[i] = xieite::geometry::Segment(this->points[i], this->points[(i + 1) % pointsSize]);
			}
			return sides;
		}
	};
}

#endif
