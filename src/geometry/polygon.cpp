module;

#include "../macros/lift.hpp"

export module xieite:geometry.Polygon;

import std;
import :algorithms.isRotated;
import :concepts.Arithmetic;
import :geometry.intersections;
import :geometry.Point;
import :geometry.Segment;

export namespace xieite::geometry {
	template<xieite::concepts::Arithmetic>
	struct Line;

	template<xieite::concepts::Arithmetic>
	struct Ray;

	template<xieite::concepts::Arithmetic Arithmetic = double>
	struct Polygon {
		std::vector<xieite::geometry::Point<Arithmetic>> points;

		template<std::ranges::input_range PointRange = std::vector<xieite::geometry::Point<Arithmetic>>>
		requires(std::convertible_to<std::ranges::range_value_t<PointRange>, xieite::geometry::Point<Arithmetic>>)
		explicit constexpr Polygon(PointRange&& points) noexcept
		: points(std::ranges::begin(points), std::ranges::end(points)) {}

		template<typename OtherArithmetic>
		[[nodiscard]] explicit(false) constexpr operator xieite::geometry::Polygon<OtherArithmetic>() const noexcept {
			using OtherPoint = xieite::geometry::Point<OtherArithmetic>;
			std::vector<OtherPoint> otherPoints = std::vector<OtherPoint>(this->points.size());
			std::ranges::transform(this->points, otherPoints.begin(), XIEITE_LIFT_UNARY(static_cast<OtherPoint>));
			return xieite::geometry::Polygon<OtherArithmetic>(otherPoints);
		}

		[[nodiscard]] friend constexpr bool operator==(const xieite::geometry::Polygon<Arithmetic>& polygon1, const xieite::geometry::Polygon<Arithmetic>& polygon2) noexcept {
			return xieite::algorithms::isRotated(polygon1.points, polygon2.points) || xieite::algorithms::isRotated(polygon1.points, std::views::reverse(polygon2.points));
		}

		[[nodiscard]] static constexpr xieite::geometry::Polygon<Arithmetic> rectangle(const xieite::geometry::Point<Arithmetic> start, const xieite::geometry::Point<Arithmetic> end) noexcept {
			return xieite::geometry::Polygon<Arithmetic>(std::vector<xieite::geometry::Point<Arithmetic>> {
				start,
				xieite::geometry::Point<Arithmetic>(start.x, end.y),
				end,
				xieite::geometry::Point<Arithmetic>(end.x, start.y)
			});
		}

		[[nodiscard]] constexpr std::conditional_t<std::floating_point<Arithmetic>, Arithmetic, double> area() const noexcept {
			std::conditional_t<std::floating_point<Arithmetic>, Arithmetic, double> area = 0;
			const std::size_t pointsSize = this->points.size();
			for (std::size_t i = 0; i < pointsSize; ++i) {
				const std::size_t j = (i + 1) % pointsSize;
				area += this->points[i].x * this->points[j].y - this->points[j].x * this->points[i].y;
			}
			return area / 2;
		}

		[[nodiscard]] constexpr std::conditional_t<std::floating_point<Arithmetic>, Arithmetic, double> perimeter() const noexcept {
			std::conditional_t<std::floating_point<Arithmetic>, Arithmetic, double> perimeter = 0;
			for (const xieite::geometry::Segment<Arithmetic>& side : this->sides()) {
				perimeter += side.length();
			}
			return perimeter;
		}

		[[nodiscard]] constexpr std::vector<xieite::geometry::Segment<Arithmetic>> sides() const noexcept {
			std::vector<xieite::geometry::Segment<Arithmetic>> sides;
			const std::size_t pointsSize = this->points.size();
			sides.reserve(pointsSize);
			for (std::size_t i = 0; i < pointsSize; ++i) {
				sides.push_back(xieite::geometry::Segment<Arithmetic>(this->points[i], this->points[(i + 1) % pointsSize]));
			}
			return sides;
		}

		[[nodiscard]] constexpr bool contains(const xieite::geometry::Point<Arithmetic> point) const noexcept {
			bool odd = false;
			const std::size_t pointsSize = this->points.size();
			for (std::size_t i = 0; i < pointsSize; ++i) {
				const std::size_t j = (i + 1) % pointsSize;
				odd ^= ((this->points[i].y < point.y) && (this->points[j].y >= point.y) || (this->points[j].y < point.y) && (this->points[i].y >= point.y)) && ((this->points[i].x <= point.x) || (this->points[j].x <= point.x)) && (this->points[i].x + (point.y - this->points[i].y) / (this->points[j].y - this->points[i].y) * (this->points[j].x - this->points[i].x) < point.x);
			}
			if (odd) {
				return true;
			}
			for (const xieite::geometry::Segment<Arithmetic>& side : this->sides()) {
				if (side.contains(point)) {
					return true;
				}
			}
			return false;
		}

		[[nodiscard]] constexpr bool contains(const xieite::geometry::Line<Arithmetic>&) const noexcept {
			return false;
		}

		[[nodiscard]] constexpr bool contains(const xieite::geometry::Ray<Arithmetic>&) const noexcept {
			return false;
		}

		[[nodiscard]] constexpr bool contains(const xieite::geometry::Segment<Arithmetic>& segment) const noexcept {
			return this->contains(segment.start) && this->contains(segment.end) && (xieite::geometry::intersections(*this, segment).size() < 2);
		}

		[[nodiscard]] constexpr bool contains(const xieite::geometry::Polygon<Arithmetic>& polygon) const noexcept {
			return polygon.points.size() && this->contains(polygon.points[0]) && (xieite::geometry::intersections(*this, polygon).size() < 2);
		}
	};
}
