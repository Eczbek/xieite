#ifndef XIEITE_HEADER_GEOMETRY_POLYGON
#	define XIEITE_HEADER_GEOMETRY_POLYGON

#	include <algorithm>
#	include <cstddef>
#	include <ranges>
#	include <vector>
#	include "../algorithms/is_rotated.hpp"
#	include "../concepts/arithmetic.hpp"
#	include "../concepts/range_of.hpp"
#	include "../functors/static_cast.hpp"
#	include "../geometry/intersections.hpp"
#	include "../geometry/point.hpp"
#	include "../geometry/segment.hpp"

namespace xieite::geometry {
	template<xieite::concepts::Arithmetic>
	struct Line;

	template<xieite::concepts::Arithmetic>
	struct Ray;

	template<xieite::concepts::Arithmetic Number = double>
	struct Polygon {
		std::vector<xieite::geometry::Point<Number>> points;

		template<xieite::concepts::RangeOf<xieite::geometry::Point<Number>> Range = std::vector<xieite::geometry::Point<Number>>>
		constexpr Polygon(Range&& points) noexcept
		: points(std::ranges::begin(points), std::ranges::end(points)) {}

		template<typename OtherNumber>
		[[nodiscard]] constexpr operator xieite::geometry::Polygon<OtherNumber>() const noexcept {
			using OtherPoint = xieite::geometry::Point<OtherNumber>;
			std::vector<OtherPoint> otherPoints = std::vector<OtherPoint>(this->points.size());
			std::ranges::transform(this->points, otherPoints.begin(), xieite::functors::StaticCast<OtherPoint>());
			return xieite::geometry::Polygon<OtherNumber>(otherPoints);
		}

		[[nodiscard]] friend constexpr bool operator==(const xieite::geometry::Polygon<Number>& polygon1, const xieite::geometry::Polygon<Number>& polygon2) noexcept {
			return xieite::algorithms::isRotated(polygon1.points, polygon2.points) || xieite::algorithms::isRotated(polygon1.points, std::views::reverse(polygon2.points));
		}

		[[nodiscard]] static constexpr xieite::geometry::Polygon<Number> rectangle(const xieite::geometry::Point<Number> start, const xieite::geometry::Point<Number> end) noexcept {
			return xieite::geometry::Polygon<Number>(std::vector<xieite::geometry::Point<Number>> {
				start,
				xieite::geometry::Point<Number>(start.x, end.y),
				end,
				xieite::geometry::Point<Number>(end.x, start.y)
			});
		}

		[[nodiscard]] constexpr std::conditional_t<std::floating_point<Number>, Number, double> area() const noexcept {
			std::conditional_t<std::floating_point<Number>, Number, double> area = 0;
			const std::size_t pointsSize = this->points.size();
			for (std::size_t i = 0; i < pointsSize; ++i) {
				const std::size_t j = (i + 1) % pointsSize;
				area += this->points[i].x * this->points[j].y - this->points[j].x * this->points[i].y;
			}
			return area / 2;
		}

		[[nodiscard]] constexpr std::conditional_t<std::floating_point<Number>, Number, double> perimeter() const noexcept {
			std::conditional_t<std::floating_point<Number>, Number, double> perimeter = 0;
			for (const xieite::geometry::Segment<Number>& side : this->sides()) {
				perimeter += side.length();
			}
			return perimeter;
		}

		[[nodiscard]] constexpr std::vector<xieite::geometry::Segment<Number>> sides() const noexcept {
			std::vector<xieite::geometry::Segment<Number>> sides;
			const std::size_t pointsSize = this->points.size();
			sides.reserve(pointsSize);
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
				if (side.contains(point)) {
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
			return this->contains(segment.start) && this->contains(segment.end) && (xieite::geometry::intersections(*this, segment).size() < 2);
		}

		[[nodiscard]] constexpr bool contains(const xieite::geometry::Polygon<Number>& polygon) const noexcept {
			return polygon.points.size() && this->contains(polygon.points[0]) && (xieite::geometry::intersections(*this, polygon).size() < 2);
		}
	};
}

#endif
