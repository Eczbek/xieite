#ifndef XIEITE_HEADER__GEOMETRY__POLYGON
#	define XIEITE_HEADER__GEOMETRY__POLYGON

#	include <cmath>
#	include <cstddef>
#	include <ranges>
#	include <vector>
#	include "../algorithms/same_relative_order.hpp"
#	include "../concepts/range_of.hpp"
#	include "../geometry/point.hpp"
#	include "../geometry/segment.hpp"

namespace xieite::geometry {
	struct Polygon {
		std::vector<xieite::geometry::Point> points;

		template<xieite::concepts::RangeOf<xieite::geometry::Point> Range = std::vector<xieite::geometry::Point>>
		constexpr Polygon(const Range& points) noexcept
		: points(std::ranges::begin(points), std::ranges::end(points)) {}

		[[nodiscard]] friend constexpr bool operator==(const xieite::geometry::Polygon& polygon1, const xieite::geometry::Polygon& polygon2) noexcept {
			return xieite::algorithms::sameRelativeOrder(polygon1.points, polygon2.points) || xieite::algorithms::sameRelativeOrder(polygon1.points, std::vector<xieite::geometry::Point>(polygon2.points.rbegin(), polygon2.points.rend()));
		}

		[[nodiscard]] constexpr double area() const noexcept {
			double area = 0;
			const std::size_t pointsSize = this->points.size();
			for (std::size_t i = 0; i < pointsSize; ++i) {
				const std::size_t j = (i + 1) % pointsSize;
				area += std::abs(this->points[i].x * this->points[j].y - this->points[i].y * this->points[j].x);
			}
			return area / 2;
		}

		[[nodiscard]] constexpr bool containsPoint(const xieite::geometry::Point point) const noexcept {
			bool odd = false;
			const std::size_t pointsSize = this->points.size();
			for (std::size_t i = 0; i < pointsSize; ++i) {
				const std::size_t j = (i + 1) % pointsSize;
				odd ^= ((this->points[i].y < point.y) && (this->points[j].y >= point.y) || (this->points[j].y < point.y) && (this->points[i].y >= point.y)) && ((this->points[i].x <= point.x) || (this->points[j].x <= point.x)) && (this->points[i].x + (point.y - this->points[i].y) / (this->points[j].y - this->points[i].y) * (this->points[j].x - this->points[i].x) < point.x);
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

		[[nodiscard]] constexpr double perimeter() const noexcept {
			double perimeter = 0;
			for (const xieite::geometry::Segment& side : this->sides()) {
				perimeter += side.length();
			}
			return perimeter;
		}

		[[nodiscard]] constexpr std::vector<xieite::geometry::Segment> sides() const noexcept {
			std::vector<xieite::geometry::Segment> sides;
			const std::size_t pointsSize = this->points.size();
			for (std::size_t i = 0; i < pointsSize; ++i) {
				sides.push_back(xieite::geometry::Segment(this->points[i], this->points[(i + 1) % pointsSize]));
			}
			return sides;
		}
	};
}

#endif
