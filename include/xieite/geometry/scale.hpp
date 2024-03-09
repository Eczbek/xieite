#ifndef XIEITE_HEADER_GEOMETRY_SCALE
#	define XIEITE_HEADER_GEOMETRY_SCALE

#	include <concepts>
#	include <type_traits>
#	include "../concepts/linear_shape.hpp"
#	include "../geometry/line.hpp"
#	include "../geometry/point.hpp"
#	include "../geometry/polygon.hpp"
#	include "../geometry/ray.hpp"
#	include "../geometry/segment.hpp"

namespace xieite::geometry {
	template<typename Number = double>
	[[nodiscard]] constexpr xieite::geometry::Point<Number> scale(const xieite::geometry::Point<Number> point, const std::conditional_t<std::floating_point<Number>, Number, double> scale, const xieite::geometry::Point<Number> origin = xieite::geometry::Point<Number>()) noexcept {
		return xieite::geometry::Point<Number>((point.x - origin.x) * scale + origin.x, (point.y - origin.y) * scale + origin.y);
	}

	template<typename Number = double, xieite::concepts::LinearShape<Number> LinearShape>
	[[nodiscard]] constexpr LinearShape scale(const LinearShape& line, const std::conditional_t<std::floating_point<Number>, Number, double> scale, const xieite::geometry::Point<Number> origin = xieite::geometry::Point<Number>()) noexcept {
		return LinearShape(xieite::geometry::scale(line.start, scale, origin), xieite::geometry::scale(line.end, scale, origin));
	}

	template<typename Number = double>
	[[nodiscard]] constexpr xieite::geometry::Polygon<Number> scale(xieite::geometry::Polygon<Number> polygon, std::conditional_t<std::floating_point<Number>, Number, double> scale, xieite::geometry::Point<Number> origin = xieite::geometry::Point<Number>()) noexcept {
		for (xieite::geometry::Point<Number>& point : polygon.points) {
			point = xieite::geometry::scale(point, scale, origin);
		}
		return polygon;
	}
}

#endif
