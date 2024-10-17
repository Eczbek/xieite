export module xieite:geometry.reflect;

import :concepts.LinearShape;
import :geometry.Point;
import :geometry.Polygon;
import :geometry.rotate;

export namespace xieite::geometry {
	template<typename Arithmetic = double, xieite::concepts::LinearShape<Arithmetic> LinearShape>
	[[nodiscard]] constexpr xieite::geometry::Point<Arithmetic> reflect(const xieite::geometry::Point<Arithmetic> point, const LinearShape& mirror) noexcept {
		return xieite::geometry::rotate(point, (mirror.angle() - mirror.start.angleTo(point)) * 2);
	}

	template<typename Arithmetic = double, xieite::concepts::LinearShape<Arithmetic> LinearShape1, xieite::concepts::LinearShape<Arithmetic> LinearShape2>
	[[nodiscard]] constexpr LinearShape1 reflect(const LinearShape1& line, const LinearShape2& mirror) noexcept {
		return LinearShape1(
			xieite::geometry::rotate(line.start, (mirror.angle() - mirror.start.angleTo(line.start)) * 2),
			xieite::geometry::rotate(line.end, (mirror.angle() - mirror.start.angleTo(line.end)) * 2)
		);
	}

	template<typename Arithmetic = double, xieite::concepts::LinearShape<Arithmetic> LinearShape>
	[[nodiscard]] constexpr xieite::geometry::Polygon<Arithmetic> reflect(xieite::geometry::Polygon<Arithmetic> polygon, const LinearShape& mirror) noexcept {
		for (xieite::geometry::Point<Arithmetic>& point : polygon.points) {
			point = xieite::geometry::rotate(point, (mirror.angle() - mirror.start.angleTo(point)) * 2);
		}
		return polygon;
	}
}
