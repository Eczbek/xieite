#ifndef XIEITE_HEADER_GEOMETRY_TRANSLATE
#	define XIEITE_HEADER_GEOMETRY_TRANSLATE

#	include "../concepts/linear_shape.hpp"
#	include "../geometry/line.hpp"
#	include "../geometry/point.hpp"
#	include "../geometry/polygon.hpp"
#	include "../geometry/ray.hpp"
#	include "../geometry/segment.hpp"

namespace xieite::geometry {
	template<typename Arithmetic_ = double>
	[[nodiscard]] constexpr xieite::geometry::Point<Arithmetic_> translate(const xieite::geometry::Point<Arithmetic_> point, const xieite::geometry::Point<Arithmetic_> difference) noexcept {
		return xieite::geometry::Point<Arithmetic_>(point.x + difference.x, point.y + difference.y);
	}

	template<typename Arithmetic_ = double, xieite::concepts::LinearShape<Arithmetic_> LinearShape_>
	[[nodiscard]] constexpr LinearShape_ translate(const LinearShape_& line, const xieite::geometry::Point<Arithmetic_> difference) noexcept {
		return LinearShape_(xieite::geometry::translate(line.start, difference), xieite::geometry::translate(line.end, difference));
	}

	template<typename Arithmetic_ = double>
	[[nodiscard]] constexpr xieite::geometry::Polygon<Arithmetic_> translate(xieite::geometry::Polygon<Arithmetic_> polygon, const xieite::geometry::Point<Arithmetic_> difference) noexcept {
		for (xieite::geometry::Point<Arithmetic_>& point : polygon.points) {
			point = xieite::geometry::translate(point, difference);
		}
		return polygon;
	}
}

#endif
