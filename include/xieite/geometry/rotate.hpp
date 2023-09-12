#ifndef XIEITE_HEADER__GEOMETRY__ROTATE
#	define XIEITE_HEADER__GEOMETRY__ROTATE

#	include <cmath>
#	include "../concepts/LinearShape.hpp"
#	include "../geometry/Point.hpp"
#	include "../geometry/Polygon.hpp"
#	include "../math/tau.hpp"

namespace xieite::geometry {
	constexpr xieite::geometry::Point rotate(const xieite::geometry::Point point, const double angle, const xieite::geometry::Point pivot = xieite::geometry::Point(0, 0)) noexcept {
		return xieite::geometry::Point(pivot.x + std::cos(angle) * (point.x - pivot.x) - std::sin(angle) * (point.y - pivot.y), pivot.y + std::sin(angle) * (point.x - pivot.x) + std::cos(angle) * (point.y - pivot.y));
	}

	template<xieite::concepts::LinearShape LinearShape>
	constexpr LinearShape rotate(const LinearShape& linearShape, const double angle, const xieite::geometry::Point pivot = xieite::geometry::Point(0, 0)) noexcept {
		return LinearShape(xieite::geometry::rotate(linearShape.start, angle, pivot), xieite::geometry::rotate(linearShape.end, angle, pivot));
	}

	constexpr xieite::geometry::Polygon rotate(xieite::geometry::Polygon polygon, const double angle, const xieite::geometry::Point pivot = xieite::geometry::Point(0, 0)) noexcept {
		for (xieite::geometry::Point& point : polygon.points) {
			point = xieite::geometry::rotate(point, angle, pivot);
		}
		return polygon;
	}
}

#endif
