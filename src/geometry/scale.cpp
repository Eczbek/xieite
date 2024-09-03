export module xieite:geometry.scale;

import std;
import :concepts.LinearShape;
import :geometry.Point;
import :geometry.Polygon;

export namespace xieite::geometry {
	template<typename Arithmetic = double>
	[[nodiscard]] constexpr xieite::geometry::Point<Arithmetic> scale(const xieite::geometry::Point<Arithmetic> point, const std::conditional_t<std::floating_point<Arithmetic>, Arithmetic, double> scale, const xieite::geometry::Point<Arithmetic> origin = xieite::geometry::Point<Arithmetic>()) noexcept {
		return xieite::geometry::Point<Arithmetic>((point.x - origin.x) * scale + origin.x, (point.y - origin.y) * scale + origin.y);
	}

	template<typename Arithmetic = double, xieite::concepts::LinearShape<Arithmetic> LinearShape>
	[[nodiscard]] constexpr LinearShape scale(const LinearShape& line, const std::conditional_t<std::floating_point<Arithmetic>, Arithmetic, double> scale, const xieite::geometry::Point<Arithmetic> origin = xieite::geometry::Point<Arithmetic>()) noexcept {
		return LinearShape(xieite::geometry::scale(line.start, scale, origin), xieite::geometry::scale(line.end, scale, origin));
	}

	template<typename Arithmetic = double>
	[[nodiscard]] constexpr xieite::geometry::Polygon<Arithmetic> scale(xieite::geometry::Polygon<Arithmetic> polygon, std::conditional_t<std::floating_point<Arithmetic>, Arithmetic, double> scale, xieite::geometry::Point<Arithmetic> origin = xieite::geometry::Point<Arithmetic>()) noexcept {
		for (xieite::geometry::Point<Arithmetic>& point : polygon.points) {
			point = xieite::geometry::scale(point, scale, origin);
		}
		return polygon;
	}
}
