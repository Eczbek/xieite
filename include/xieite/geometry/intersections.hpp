#ifndef XIEITE_HEADER_GEOMETRY_INTERSECTIONS
#	define XIEITE_HEADER_GEOMETRY_INTERSECTIONS

#	include <cmath>
#	include <vector>
#	include "../concepts/arithmetic.hpp"
#	include "../concepts/linear_shape.hpp"
#	include "../geometry/point.hpp"
#	include "../math/almost_equal.hpp"

namespace xieite::geometry {
	template<xieite::concepts::Arithmetic>
	struct Polygon;

	template<typename Arithmetic_ = double>
	[[nodiscard]] constexpr std::vector<xieite::geometry::Point<Arithmetic_>> intersections(const xieite::geometry::Point<Arithmetic_> point1, const xieite::geometry::Point<Arithmetic_> point2) noexcept {
		return (point1 == point2) ? std::vector<xieite::geometry::Point<Arithmetic_>> {
			point1
		} : std::vector<xieite::geometry::Point<Arithmetic_>>();
	}

	template<typename Arithmetic_ = double, xieite::concepts::LinearShape<Arithmetic_> LinearShape_>
	[[nodiscard]] constexpr std::vector<xieite::geometry::Point<Arithmetic_>> intersections(const xieite::geometry::Point<Arithmetic_> point, const LinearShape_& linearShape) noexcept {
		return linearShape.contains(point) ? std::vector<xieite::geometry::Point<Arithmetic_>> {
			point
		} : std::vector<xieite::geometry::Point<Arithmetic_>>();
	}

	template<typename Arithmetic_ = double>
	[[nodiscard]] constexpr std::vector<xieite::geometry::Point<Arithmetic_>> intersections(const xieite::geometry::Point<Arithmetic_> point, const xieite::geometry::Polygon<Arithmetic_>& polygon) noexcept {
		std::vector<xieite::geometry::Point<Arithmetic_>> totalIntersections;
		for (const xieite::geometry::Segment<Arithmetic_>& side : polygon.sides()) {
			const std::vector<xieite::geometry::Point<Arithmetic_>> localIntersections = xieite::geometry::intersections(point, side);
			totalIntersections.insert(totalIntersections.end(), localIntersections.begin(), localIntersections.end());
		}
		return totalIntersections;
	}

	template<typename Arithmetic_ = double, xieite::concepts::LinearShape<Arithmetic_> LinearShape_>
	[[nodiscard]] constexpr std::vector<xieite::geometry::Point<Arithmetic_>> intersections(const LinearShape_& linearShape, const xieite::geometry::Point<Arithmetic_> point) noexcept {
		return xieite::geometry::intersections(point, linearShape);
	}

	template<typename Arithmetic_ = double, xieite::concepts::LinearShape<Arithmetic_> LinearShape1, xieite::concepts::LinearShape<Arithmetic_> LinearShape2>
	[[nodiscard]] constexpr std::vector<xieite::geometry::Point<Arithmetic_>> intersections(const LinearShape1& linearShape1, const LinearShape2& linearShape2) noexcept {
		const double discriminator = (linearShape1.start.x - linearShape1.end.x) * (linearShape2.start.y - linearShape2.end.y) - (linearShape1.start.y - linearShape1.end.y) * (linearShape2.start.x - linearShape2.end.x);
		if (!xieite::math::almostEqual<Arithmetic_>(discriminator, 0)) {
			const auto intersection = xieite::geometry::Point<Arithmetic_>(((linearShape2.start.x - linearShape2.end.x) * (linearShape1.start.x * linearShape1.end.y - linearShape1.start.y * linearShape1.end.x) - (linearShape1.start.x - linearShape1.end.x) * (linearShape2.start.x * linearShape2.end.y - linearShape2.start.y * linearShape2.end.x)) / discriminator, ((linearShape2.start.y - linearShape2.end.y) * (linearShape1.start.x * linearShape1.end.y - linearShape1.start.y * linearShape1.end.x) - (linearShape1.start.y - linearShape1.end.y) * (linearShape2.start.x * linearShape2.end.y - linearShape2.start.y * linearShape2.end.x)) / discriminator);
			if (linearShape1.contains(intersection) && linearShape2.contains(intersection)) {
				return std::vector<xieite::geometry::Point<Arithmetic_>> {
					intersection
				};
			}
		}
		return std::vector<xieite::geometry::Point<Arithmetic_>>();
	}

	template<typename Arithmetic_ = double, xieite::concepts::LinearShape<Arithmetic_> LinearShape_>
	[[nodiscard]] constexpr std::vector<xieite::geometry::Point<Arithmetic_>> intersections(const LinearShape_& linearShape, const xieite::geometry::Polygon<Arithmetic_>& polygon) noexcept {
		std::vector<xieite::geometry::Point<Arithmetic_>> totalIntersections;
		for (const xieite::geometry::Segment<Arithmetic_>& side : polygon.sides()) {
			const std::vector<xieite::geometry::Point<Arithmetic_>> localIntersections = xieite::geometry::intersections(linearShape, side);
			totalIntersections.insert(totalIntersections.end(), localIntersections.begin(), localIntersections.end());
		}
		return totalIntersections;
	}

	template<typename Arithmetic_ = double>
	[[nodiscard]] constexpr std::vector<xieite::geometry::Point<Arithmetic_>> intersections(const xieite::geometry::Polygon<Arithmetic_>& polygon, const xieite::geometry::Point<Arithmetic_> point) noexcept {
		return xieite::geometry::intersections(point, polygon);
	}

	template<typename Arithmetic_ = double, xieite::concepts::LinearShape<Arithmetic_> LinearShape_>
	[[nodiscard]] constexpr std::vector<xieite::geometry::Point<Arithmetic_>> intersections(const xieite::geometry::Polygon<Arithmetic_>& polygon, const LinearShape_& linearShape) noexcept {
		return xieite::geometry::intersections(linearShape, polygon);
	}

	template<typename Arithmetic_ = double>
	[[nodiscard]] constexpr std::vector<xieite::geometry::Point<Arithmetic_>> intersections(const xieite::geometry::Polygon<Arithmetic_>& polygon1, const xieite::geometry::Polygon<Arithmetic_>& polygon2) noexcept {
		std::vector<xieite::geometry::Point<Arithmetic_>> totalIntersections;
		const std::vector<xieite::geometry::Segment<Arithmetic_>> sides2 = polygon2.sides();
		for (const xieite::geometry::Segment<Arithmetic_>& side1 : polygon1.sides()) {
			for (const xieite::geometry::Segment<Arithmetic_>& side2 : sides2) {
				const std::vector<xieite::geometry::Point<Arithmetic_>> localIntersections = xieite::geometry::intersections(side1, side2);
				totalIntersections.insert(totalIntersections.end(), localIntersections.begin(), localIntersections.end());
			}
		}
		return totalIntersections;
	}
}

#endif
