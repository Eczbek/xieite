#ifndef XIEITE_HEADER_GEOMETRY_ROTATE
#	define XIEITE_HEADER_GEOMETRY_ROTATE

#	include <cmath>
#	include <concepts>
#	include <type_traits>
#	include "../concepts/linear_shape.hpp"
#	include "../geometry/line.hpp"
#	include "../geometry/point.hpp"
#	include "../geometry/polygon.hpp"
#	include "../geometry/ray.hpp"
#	include "../geometry/segment.hpp"
#	include "../math/tau.hpp"

namespace xieite::geometry {
	template<typename Number = double>
	[[nodiscard]] constexpr xieite::geometry::Point<Number> rotate(const xieite::geometry::Point<Number> point, const std::conditional_t<std::floating_point<Number>, Number, double> angle, const xieite::geometry::Point<Number> pivot = xieite::geometry::Point<Number>()) noexcept {
		return xieite::geometry::Point<Number>(pivot.x + std::cos(angle) * (point.x - pivot.x) - std::sin(angle) * (point.y - pivot.y), pivot.y + std::sin(angle) * (point.x - pivot.x) + std::cos(angle) * (point.y - pivot.y));
	}

	template<typename Number = double, xieite::concepts::LinearShape<Number> LinearShape>
	[[nodiscard]] constexpr LinearShape rotate(const LinearShape& linearShape, const std::conditional_t<std::floating_point<Number>, Number, double> angle, const xieite::geometry::Point<Number> pivot = xieite::geometry::Point<Number>()) noexcept {
		return LinearShape(xieite::geometry::rotate(linearShape.start, angle, pivot), xieite::geometry::rotate(linearShape.end, angle, pivot));
	}

	template<typename Number = double>
	[[nodiscard]] constexpr xieite::geometry::Polygon<Number> rotate(xieite::geometry::Polygon<Number> polygon, const std::conditional_t<std::floating_point<Number>, Number, double> angle, const xieite::geometry::Point<Number> pivot = xieite::geometry::Point<Number>()) noexcept {
		for (xieite::geometry::Point<Number>& point : polygon.points) {
			point = xieite::geometry::rotate(point, angle, pivot);
		}
		return polygon;
	}
}

#endif
