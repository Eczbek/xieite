export module xieite:geometry.intersections;

import std;
import :concepts.Arithmetic;
import :concepts.LinearShape;
import :geometry.Point;
import :math.almostEqual;

export namespace xieite::geometry {
	template<xieite::concepts::Arithmetic>
	struct Polygon;

	template<typename Arithmetic = double>
	[[nodiscard]] constexpr std::vector<xieite::geometry::Point<Arithmetic>> intersections(const xieite::geometry::Point<Arithmetic> point1, const xieite::geometry::Point<Arithmetic> point2) noexcept {
		return (point1 == point2)
			? std::vector<xieite::geometry::Point<Arithmetic>> { point1 }
			: std::vector<xieite::geometry::Point<Arithmetic>>();
	}

	template<typename Arithmetic = double, xieite::concepts::LinearShape<Arithmetic> LinearShape>
	[[nodiscard]] constexpr std::vector<xieite::geometry::Point<Arithmetic>> intersections(const xieite::geometry::Point<Arithmetic> point, const LinearShape& linearShape) noexcept {
		return linearShape.contains(point)
			? std::vector<xieite::geometry::Point<Arithmetic>> { point }
			: std::vector<xieite::geometry::Point<Arithmetic>>();
	}

	template<typename Arithmetic = double>
	[[nodiscard]] constexpr std::vector<xieite::geometry::Point<Arithmetic>> intersections(const xieite::geometry::Point<Arithmetic> point, const xieite::geometry::Polygon<Arithmetic>& polygon) noexcept {
		std::vector<xieite::geometry::Point<Arithmetic>> totalIntersections;
		for (const xieite::geometry::Segment<Arithmetic>& side : polygon.sides()) {
			const std::vector<xieite::geometry::Point<Arithmetic>> localIntersections = xieite::geometry::intersections(point, side);
			totalIntersections.insert(totalIntersections.end(), localIntersections.begin(), localIntersections.end());
		}
		return totalIntersections;
	}

	template<typename Arithmetic = double, xieite::concepts::LinearShape<Arithmetic> LinearShape>
	[[nodiscard]] constexpr std::vector<xieite::geometry::Point<Arithmetic>> intersections(const LinearShape& linearShape, const xieite::geometry::Point<Arithmetic> point) noexcept {
		return xieite::geometry::intersections(point, linearShape);
	}

	template<typename Arithmetic = double, xieite::concepts::LinearShape<Arithmetic> LinearShape1, xieite::concepts::LinearShape<Arithmetic> LinearShape2>
	[[nodiscard]] constexpr std::vector<xieite::geometry::Point<Arithmetic>> intersections(const LinearShape1& linearShape1, const LinearShape2& linearShape2) noexcept {
		const double discriminator = (linearShape1.start.x - linearShape1.end.x) * (linearShape2.start.y - linearShape2.end.y) - (linearShape1.start.y - linearShape1.end.y) * (linearShape2.start.x - linearShape2.end.x);
		if (!xieite::math::almostEqual<Arithmetic>(discriminator, 0)) {
			const auto intersection = xieite::geometry::Point<Arithmetic>(((linearShape2.start.x - linearShape2.end.x) * (linearShape1.start.x * linearShape1.end.y - linearShape1.start.y * linearShape1.end.x) - (linearShape1.start.x - linearShape1.end.x) * (linearShape2.start.x * linearShape2.end.y - linearShape2.start.y * linearShape2.end.x)) / discriminator, ((linearShape2.start.y - linearShape2.end.y) * (linearShape1.start.x * linearShape1.end.y - linearShape1.start.y * linearShape1.end.x) - (linearShape1.start.y - linearShape1.end.y) * (linearShape2.start.x * linearShape2.end.y - linearShape2.start.y * linearShape2.end.x)) / discriminator);
			if (linearShape1.contains(intersection) && linearShape2.contains(intersection)) {
				return std::vector<xieite::geometry::Point<Arithmetic>> {
					intersection
				};
			}
		}
		return std::vector<xieite::geometry::Point<Arithmetic>>();
	}

	template<typename Arithmetic = double, xieite::concepts::LinearShape<Arithmetic> LinearShape>
	[[nodiscard]] constexpr std::vector<xieite::geometry::Point<Arithmetic>> intersections(const LinearShape& linearShape, const xieite::geometry::Polygon<Arithmetic>& polygon) noexcept {
		std::vector<xieite::geometry::Point<Arithmetic>> totalIntersections;
		for (const xieite::geometry::Segment<Arithmetic>& side : polygon.sides()) {
			const std::vector<xieite::geometry::Point<Arithmetic>> localIntersections = xieite::geometry::intersections(linearShape, side);
			totalIntersections.insert(totalIntersections.end(), localIntersections.begin(), localIntersections.end());
		}
		return totalIntersections;
	}

	template<typename Arithmetic = double>
	[[nodiscard]] constexpr std::vector<xieite::geometry::Point<Arithmetic>> intersections(const xieite::geometry::Polygon<Arithmetic>& polygon, const xieite::geometry::Point<Arithmetic> point) noexcept {
		return xieite::geometry::intersections(point, polygon);
	}

	template<typename Arithmetic = double, xieite::concepts::LinearShape<Arithmetic> LinearShape>
	[[nodiscard]] constexpr std::vector<xieite::geometry::Point<Arithmetic>> intersections(const xieite::geometry::Polygon<Arithmetic>& polygon, const LinearShape& linearShape) noexcept {
		return xieite::geometry::intersections(linearShape, polygon);
	}

	template<typename Arithmetic = double>
	[[nodiscard]] constexpr std::vector<xieite::geometry::Point<Arithmetic>> intersections(const xieite::geometry::Polygon<Arithmetic>& polygon1, const xieite::geometry::Polygon<Arithmetic>& polygon2) noexcept {
		std::vector<xieite::geometry::Point<Arithmetic>> totalIntersections;
		const std::vector<xieite::geometry::Segment<Arithmetic>> sides2 = polygon2.sides();
		for (const xieite::geometry::Segment<Arithmetic>& side1 : polygon1.sides()) {
			for (const xieite::geometry::Segment<Arithmetic>& side2 : sides2) {
				const std::vector<xieite::geometry::Point<Arithmetic>> localIntersections = xieite::geometry::intersections(side1, side2);
				totalIntersections.insert(totalIntersections.end(), localIntersections.begin(), localIntersections.end());
			}
		}
		return totalIntersections;
	}
}
