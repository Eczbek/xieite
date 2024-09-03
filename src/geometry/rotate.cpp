export module xieite:geometry.rotate;

import std;
import :concepts.LinearShape;
import :geometry.Point;
import :geometry.Polygon;

export namespace xieite::geometry {
	template<typename Arithmetic = double>
	[[nodiscard]] constexpr xieite::geometry::Point<Arithmetic> rotate(const xieite::geometry::Point<Arithmetic> point, const std::conditional_t<std::floating_point<Arithmetic>, Arithmetic, double> angle, const xieite::geometry::Point<Arithmetic> pivot = xieite::geometry::Point<Arithmetic>()) noexcept {
		return xieite::geometry::Point<Arithmetic>(pivot.x + std::cos(angle) * (point.x - pivot.x) - std::sin(angle) * (point.y - pivot.y), pivot.y + std::sin(angle) * (point.x - pivot.x) + std::cos(angle) * (point.y - pivot.y));
	}

	template<typename Arithmetic = double, xieite::concepts::LinearShape<Arithmetic> LinearShape>
	[[nodiscard]] constexpr LinearShape rotate(const LinearShape& linearShape, const std::conditional_t<std::floating_point<Arithmetic>, Arithmetic, double> angle, const xieite::geometry::Point<Arithmetic> pivot = xieite::geometry::Point<Arithmetic>()) noexcept {
		return LinearShape(xieite::geometry::rotate(linearShape.start, angle, pivot), xieite::geometry::rotate(linearShape.end, angle, pivot));
	}

	template<typename Arithmetic = double>
	[[nodiscard]] constexpr xieite::geometry::Polygon<Arithmetic> rotate(xieite::geometry::Polygon<Arithmetic> polygon, const std::conditional_t<std::floating_point<Arithmetic>, Arithmetic, double> angle, const xieite::geometry::Point<Arithmetic> pivot = xieite::geometry::Point<Arithmetic>()) noexcept {
		for (xieite::geometry::Point<Arithmetic>& point : polygon.points) {
			point = xieite::geometry::rotate(point, angle, pivot);
		}
		return polygon;
	}
}
