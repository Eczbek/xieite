#ifndef XIEITE_HEADER_GEOMETRY_INTERSECTIONS
#	define XIEITE_HEADER_GEOMETRY_INTERSECTIONS

#	include <cmath>
#	include <vector>
#	include "../concepts/arithmetic.hpp"
#	include "../concepts/convertible_to_any.hpp"
#	include "../math/almost_equal.hpp"

namespace xieite::geometry {
	template<xieite::concepts::Arithmetic>
	struct Point;

	template<xieite::concepts::Arithmetic>
	struct Line;

	template<xieite::concepts::Arithmetic>
	struct Ray;

	template<xieite::concepts::Arithmetic>
	struct Segment;

	template<xieite::concepts::Arithmetic>
	struct Polygon;

	template<typename Number>
	[[nodiscard]] constexpr std::vector<xieite::geometry::Point<Number>> intersections(const xieite::geometry::Point<Number> point1, const xieite::geometry::Point<Number> point2) noexcept {
		return (point1 == point2) ? std::vector<xieite::geometry::Point<Number>> {
			point1
		} : std::vector<xieite::geometry::Point<Number>>();
	}

	template<typename Number, xieite::concepts::ConvertibleToAny<xieite::geometry::Line<Number>, xieite::geometry::Ray<Number>, xieite::geometry::Segment<Number>> LinearShape>
	[[nodiscard]] constexpr std::vector<xieite::geometry::Point<Number>> intersections(const xieite::geometry::Point<Number> point, const LinearShape& linearShape) noexcept {
		return linearShape.contains(point) ? std::vector<xieite::geometry::Point<Number>> {
			point
		} : std::vector<xieite::geometry::Point<Number>>();
	}

	template<typename Number>
	[[nodiscard]] constexpr std::vector<xieite::geometry::Point<Number>> intersections(const xieite::geometry::Point<Number> point, const xieite::geometry::Polygon<Number>& polygon) noexcept {
		std::vector<xieite::geometry::Point<Number>> totalIntersections;
		for (const xieite::geometry::Segment<Number>& side : polygon.sides()) {
			const std::vector<xieite::geometry::Point<Number>> localIntersections = xieite::geometry::intersections(point, side);
			totalIntersections.insert(totalIntersections.end(), localIntersections.begin(), localIntersections.end());
		}
		return totalIntersections;
	}

	template<typename Number, xieite::concepts::ConvertibleToAny<xieite::geometry::Line<Number>, xieite::geometry::Ray<Number>, xieite::geometry::Segment<Number>> LinearShape>
	[[nodiscard]] constexpr std::vector<xieite::geometry::Point<Number>> intersections(const LinearShape& linearShape, const xieite::geometry::Point<Number> point) noexcept {
		return xieite::geometry::intersections(point, linearShape);
	}

	template<typename Number, xieite::concepts::ConvertibleToAny<xieite::geometry::Line<Number>, xieite::geometry::Ray<Number>, xieite::geometry::Segment<Number>> LinearShape1, xieite::concepts::ConvertibleToAny<xieite::geometry::Line<Number>, xieite::geometry::Ray<Number>, xieite::geometry::Segment<Number>> LinearShape2>
	[[nodiscard]] constexpr std::vector<xieite::geometry::Point<Number>> intersections(const LinearShape1& linearShape1, const LinearShape2& linearShape2) noexcept {
		const double discriminator = (linearShape1.start.x - linearShape1.end.x) * (linearShape2.start.y - linearShape2.end.y) - (linearShape1.start.y - linearShape1.end.y) * (linearShape2.start.x - linearShape2.end.x);
		if (!xieite::math::almostEqual(discriminator, 0)) {
			const auto intersection = xieite::geometry::Point<Number>(((linearShape2.start.x - linearShape2.end.x) * (linearShape1.start.x * linearShape1.end.y - linearShape1.start.y * linearShape1.end.x) - (linearShape1.start.x - linearShape1.end.x) * (linearShape2.start.x * linearShape2.end.y - linearShape2.start.y * linearShape2.end.x)) / discriminator, ((linearShape2.start.y - linearShape2.end.y) * (linearShape1.start.x * linearShape1.end.y - linearShape1.start.y * linearShape1.end.x) - (linearShape1.start.y - linearShape1.end.y) * (linearShape2.start.x * linearShape2.end.y - linearShape2.start.y * linearShape2.end.x)) / discriminator);
			if (linearShape1.contains(intersection) && linearShape2.contains(intersection)) {
				return std::vector<xieite::geometry::Point<Number>> {
					intersection
				};
			}
		}
		return std::vector<xieite::geometry::Point<Number>>();
	}

	template<typename Number, xieite::concepts::ConvertibleToAny<xieite::geometry::Line<Number>, xieite::geometry::Ray<Number>, xieite::geometry::Segment<Number>> LinearShape>
	[[nodiscard]] constexpr std::vector<xieite::geometry::Point<Number>> intersections(const LinearShape& linearShape, const xieite::geometry::Polygon<Number>& polygon) noexcept {
		std::vector<xieite::geometry::Point<Number>> totalIntersections;
		for (const xieite::geometry::Segment<Number>& side : polygon.sides()) {
			const std::vector<xieite::geometry::Point<Number>> localIntersections = xieite::geometry::intersections(linearShape, side);
			totalIntersections.insert(totalIntersections.end(), localIntersections.begin(), localIntersections.end());
		}
		return totalIntersections;
	}

	template<typename Number>
	[[nodiscard]] constexpr std::vector<xieite::geometry::Point<Number>> intersections(const xieite::geometry::Polygon<Number>& polygon, const xieite::geometry::Point<Number> point) noexcept {
		return xieite::geometry::intersections(point, polygon);
	}

	template<typename Number, xieite::concepts::ConvertibleToAny<xieite::geometry::Line<Number>, xieite::geometry::Ray<Number>, xieite::geometry::Segment<Number>> LinearShape>
	[[nodiscard]] constexpr std::vector<xieite::geometry::Point<Number>> intersections(const xieite::geometry::Polygon<Number>& polygon, const LinearShape& linearShape) noexcept {
		return xieite::geometry::intersections(linearShape, polygon);
	}

	template<typename Number>
	[[nodiscard]] constexpr std::vector<xieite::geometry::Point<Number>> intersections(const xieite::geometry::Polygon<Number>& polygon1, const xieite::geometry::Polygon<Number>& polygon2) noexcept {
		std::vector<xieite::geometry::Point<Number>> totalIntersections;
		const std::vector<xieite::geometry::Segment<Number>> sides2 = polygon2.sides();
		for (const xieite::geometry::Segment<Number>& side1 : polygon1.sides()) {
			for (const xieite::geometry::Segment<Number>& side2 : sides2) {
				const std::vector<xieite::geometry::Point<Number>> localIntersections = xieite::geometry::intersections(side1, side2);
				totalIntersections.insert(totalIntersections.end(), localIntersections.begin(), localIntersections.end());
			}
		}
		return totalIntersections;
	}
}

#endif
