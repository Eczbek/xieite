export module xieite:geometry.translate;

import :concepts.LinearShape;
import :geometry.Point;
import :geometry.Polygon;

export namespace xieite::geometry {
	template<typename Arithmetic = double>
	[[nodiscard]] constexpr xieite::geometry::Point<Arithmetic> translate(const xieite::geometry::Point<Arithmetic> point, const xieite::geometry::Point<Arithmetic> difference) noexcept {
		return xieite::geometry::Point<Arithmetic>(point.x + difference.x, point.y + difference.y);
	}

	template<typename Arithmetic = double, xieite::concepts::LinearShape<Arithmetic> LinearShape>
	[[nodiscard]] constexpr LinearShape translate(const LinearShape& line, const xieite::geometry::Point<Arithmetic> difference) noexcept {
		return LinearShape(xieite::geometry::translate(line.start, difference), xieite::geometry::translate(line.end, difference));
	}

	template<typename Arithmetic = double>
	[[nodiscard]] constexpr xieite::geometry::Polygon<Arithmetic> translate(xieite::geometry::Polygon<Arithmetic> polygon, const xieite::geometry::Point<Arithmetic> difference) noexcept {
		for (xieite::geometry::Point<Arithmetic>& point : polygon.points) {
			point = xieite::geometry::translate(point, difference);
		}
		return polygon;
	}
}
