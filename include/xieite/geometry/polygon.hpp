#ifndef XIEITE_HEADER_GEOMETRY_POLYGON
#	define XIEITE_HEADER_GEOMETRY_POLYGON

#	include <cmath>
#	include <cstddef>
#	include <ranges>
#	include <vector>
#	include "../algorithms/same_relative_order.hpp"
#	include "../concepts/arithmetic.hpp"
#	include "../concepts/range_of.hpp"
#	include "../geometry/intersections.hpp"
#	include "../geometry/point.hpp"
#	include "../geometry/segment.hpp"

namespace xieite::geometry {
	template<xieite::concepts::Arithmetic>
	struct Line;

	template<xieite::concepts::Arithmetic>
	struct Ray;

	template<xieite::concepts::Arithmetic Number>
	struct Polygon {
		std::vector<xieite::geometry::Point<Number>> points;

		template<xieite::concepts::RangeOf<xieite::geometry::Point<Number>> Range = std::vector<xieite::geometry::Point<Number>>>
		constexpr Polygon(const Range& points) noexcept
		: points(std::ranges::begin(points), std::ranges::end(points)) {}

		[[nodiscard]] friend constexpr bool operator==(const xieite::geometry::Polygon<Number>& polygon1, const xieite::geometry::Polygon<Number>& polygon2) noexcept {
			return xieite::algorithms::sameRelativeOrder(polygon1.points, polygon2.points) || xieite::algorithms::sameRelativeOrder(polygon1.points, std::vector<xieite::geometry::Point<Number>>(polygon2.points.rbegin(), polygon2.points.rend()));
		}

		template<typename OtherNumber>
		[[nodiscard]] constexpr operator xieite::geometry::Polygon<OtherNumber>() const noexcept {
			const std::size_t pointsSize = this->points.size();
			auto otherPoints = std::vector<OtherNumber>(pointsSize);
			for (std::size_t i = 0; i < pointsSize; ++i) {
				otherPoints[i] = static_cast<OtherNumber>(this->points[i]);
			}
			return xieite::geometry::Polygon<OtherNumber>(otherPoints);
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

		[[nodiscard]] constexpr double perimeter() const noexcept {
			double perimeter = 0;
			for (const xieite::geometry::Segment<Number>& side : this->sides()) {
				perimeter += side.length();
			}
			return perimeter;
		}

		[[nodiscard]] constexpr std::vector<xieite::geometry::Segment<Number>> sides() const noexcept {
			std::vector<xieite::geometry::Segment<Number>> sides;
			const std::size_t pointsSize = this->points.size();
			for (std::size_t i = 0; i < pointsSize; ++i) {
				sides.push_back(xieite::geometry::Segment<Number>(this->points[i], this->points[(i + 1) % pointsSize]));
			}
			return sides;
		}

		[[nodiscard]] constexpr bool contains(const xieite::geometry::Point<Number> point) const noexcept {
			bool odd = false;
			const std::size_t pointsSize = this->points.size();
			for (std::size_t i = 0; i < pointsSize; ++i) {
				const std::size_t j = (i + 1) % pointsSize;
				odd ^= ((this->points[i].y < point.y) && (this->points[j].y >= point.y) || (this->points[j].y < point.y) && (this->points[i].y >= point.y)) && ((this->points[i].x <= point.x) || (this->points[j].x <= point.x)) && (this->points[i].x + (point.y - this->points[i].y) / (this->points[j].y - this->points[i].y) * (this->points[j].x - this->points[i].x) < point.x);
			}
			if (odd) {
				return true;
			}
			for (const xieite::geometry::Segment<Number>& side : this->sides()) {
				if (side.containsPoint(point)) {
					return true;
				}
			}
			return false;
		}

		[[nodiscard]] constexpr bool contains(const xieite::geometry::Line<Number>&) const noexcept {
			return false;
		}

		[[nodiscard]] constexpr bool contains(const xieite::geometry::Ray<Number>&) const noexcept {
			return false;
		}

		[[nodiscard]] constexpr bool contains(const xieite::geometry::Segment<Number>& segment) const noexcept {
			return this->contains(segment.start) && !xieite::geometry::intersections(*this, segment).size();
		}

		[[nodiscard]] constexpr bool contains(const xieite::geometry::Polygon<Number>& polygon) const noexcept {
			return polygon.points.size() && this->contains(polygon.points[0]) && !xieite::geometry::intersections(*this, polygon).size();
		}
	};
}

#endif
