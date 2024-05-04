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
	template<typename Arithmetic_ = double>
	[[nodiscard]] constexpr xieite::geometry::Point<Arithmetic_> rotate(const xieite::geometry::Point<Arithmetic_> point, const std::conditional_t<std::floating_point<Arithmetic_>, Arithmetic_, double> angle, const xieite::geometry::Point<Arithmetic_> pivot = xieite::geometry::Point<Arithmetic_>()) noexcept {
		return xieite::geometry::Point<Arithmetic_>(pivot.x + std::cos(angle) * (point.x - pivot.x) - std::sin(angle) * (point.y - pivot.y), pivot.y + std::sin(angle) * (point.x - pivot.x) + std::cos(angle) * (point.y - pivot.y));
	}

	template<typename Arithmetic_ = double, xieite::concepts::LinearShape<Arithmetic_> LinearShape_>
	[[nodiscard]] constexpr LinearShape_ rotate(const LinearShape_& linearShape, const std::conditional_t<std::floating_point<Arithmetic_>, Arithmetic_, double> angle, const xieite::geometry::Point<Arithmetic_> pivot = xieite::geometry::Point<Arithmetic_>()) noexcept {
		return LinearShape_(xieite::geometry::rotate(linearShape.start, angle, pivot), xieite::geometry::rotate(linearShape.end, angle, pivot));
	}

	template<typename Arithmetic_ = double>
	[[nodiscard]] constexpr xieite::geometry::Polygon<Arithmetic_> rotate(xieite::geometry::Polygon<Arithmetic_> polygon, const std::conditional_t<std::floating_point<Arithmetic_>, Arithmetic_, double> angle, const xieite::geometry::Point<Arithmetic_> pivot = xieite::geometry::Point<Arithmetic_>()) noexcept {
		for (xieite::geometry::Point<Arithmetic_>& point : polygon.points) {
			point = xieite::geometry::rotate(point, angle, pivot);
		}
		return polygon;
	}
}

#endif
