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
	template<typename Arithmetic_ = double>
	[[nodiscard]] constexpr xieite::geometry::Point<Arithmetic_> scale(const xieite::geometry::Point<Arithmetic_> point, const std::conditional_t<std::floating_point<Arithmetic_>, Arithmetic_, double> scale, const xieite::geometry::Point<Arithmetic_> origin = xieite::geometry::Point<Arithmetic_>()) noexcept {
		return xieite::geometry::Point<Arithmetic_>((point.x - origin.x) * scale + origin.x, (point.y - origin.y) * scale + origin.y);
	}

	template<typename Arithmetic_ = double, xieite::concepts::LinearShape<Arithmetic_> LinearShape_>
	[[nodiscard]] constexpr LinearShape_ scale(const LinearShape_& line, const std::conditional_t<std::floating_point<Arithmetic_>, Arithmetic_, double> scale, const xieite::geometry::Point<Arithmetic_> origin = xieite::geometry::Point<Arithmetic_>()) noexcept {
		return LinearShape_(xieite::geometry::scale(line.start, scale, origin), xieite::geometry::scale(line.end, scale, origin));
	}

	template<typename Arithmetic_ = double>
	[[nodiscard]] constexpr xieite::geometry::Polygon<Arithmetic_> scale(xieite::geometry::Polygon<Arithmetic_> polygon, std::conditional_t<std::floating_point<Arithmetic_>, Arithmetic_, double> scale, xieite::geometry::Point<Arithmetic_> origin = xieite::geometry::Point<Arithmetic_>()) noexcept {
		for (xieite::geometry::Point<Arithmetic_>& point : polygon.points) {
			point = xieite::geometry::scale(point, scale, origin);
		}
		return polygon;
	}
}

#endif
