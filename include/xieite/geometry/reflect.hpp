#ifndef XIEITE_HEADER_GEOMETRY_REFLECT
#	define XIEITE_HEADER_GEOMETRY_REFLECT

#	include "../concepts/linear_shape.hpp"
#	include "../geometry/line.hpp"
#	include "../geometry/point.hpp"
#	include "../geometry/polygon.hpp"
#	include "../geometry/ray.hpp"
#	include "../geometry/rotate.hpp"
#	include "../geometry/segment.hpp"

namespace xieite::geometry {
	template<typename Arithmetic_ = double, xieite::concepts::LinearShape<Arithmetic_> LinearShape_>
	[[nodiscard]] constexpr xieite::geometry::Point<Arithmetic_> reflect(const xieite::geometry::Point<Arithmetic_> point, const LinearShape_& mirror) noexcept {
		return xieite::geometry::rotate(point, (mirror.angle() - mirror.start.angleTo(point)) * 2);
	}

	template<typename Arithmetic_ = double, xieite::concepts::LinearShape<Arithmetic_> LinearShape1, xieite::concepts::LinearShape<Arithmetic_> LinearShape2>
	[[nodiscard]] constexpr LinearShape1 reflect(const LinearShape1& line, const LinearShape2& mirror) noexcept {
		return LinearShape1(xieite::geometry::rotate(line.start, (mirror.angle() - mirror.start.angleTo(line.start)) * 2), xieite::geometry::rotate(line.end, (mirror.angle() - mirror.start.angleTo(line.end)) * 2));
	}

	template<typename Arithmetic_ = double, xieite::concepts::LinearShape<Arithmetic_> LinearShape_>
	[[nodiscard]] constexpr xieite::geometry::Polygon<Arithmetic_> reflect(xieite::geometry::Polygon<Arithmetic_> polygon, const LinearShape_& mirror) noexcept {
		for (xieite::geometry::Point<Arithmetic_>& point : polygon.points) {
			point = xieite::geometry::rotate(point, (mirror.angle() - mirror.start.angleTo(point)) * 2);
		}
		return polygon;
	}
}

#endif
