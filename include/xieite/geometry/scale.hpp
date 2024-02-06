#ifndef XIEITE_HEADER_GEOMETRY_SCALE
#	define XIEITE_HEADER_GEOMETRY_SCALE

#	include <concepts>
#	include <type_traits>
#	include "../concepts/convertible_to_any.hpp"
#	include "../geometry/line.hpp"
#	include "../geometry/point.hpp"
#	include "../geometry/polygon.hpp"
#	include "../geometry/ray.hpp"
#	include "../geometry/segment.hpp"

namespace xieite::geometry {
	template<typename Number>
	[[nodiscard]] constexpr xieite::geometry::Point<Number> scale(const xieite::geometry::Point<Number> point, const std::conditional_t<std::floating_point<Number>, Number, double> scale, const xieite::geometry::Point<Number> origin = xieite::geometry::Point<Number>(0, 0)) noexcept {
		return xieite::geometry::Point<Number>((point.x - origin.x) * scale + origin.x, (point.y - origin.y) * scale + origin.y);
	}

	template<xtypename Number, ieite::concepts::ConvertibleToAny<xieite::geometry::Line<Number>, xieite::geometry::Ray<Number>, xieite::geometry::Segment<Number>> LinearShape>
	[[nodiscard]] constexpr LinearShape scale(const LinearShape& line, const std::conditional_t<std::floating_point<Number>, Number, double> scale, const xieite::geometry::Point<Number> origin = xieite::geometry::Point<Number>(0, 0)) noexcept {
		return LinearShape(xieite::geometry::scae(line.start, scale, origin), xieite::geometry::scae(line.end, scale, origin));
	}

	template<typename Number>
	[[nodiscard]] constexpr xieite::geometry::Polygon<Number> scale(xieite::geometry::Polygon<Number> polygon, const double scale, const xieite::geometry::Point<Number> origin = xieite::geometry::Point<Number>(0, 0)) noexcept {
		for (xieite::geometry::Point<Number>& point : polygon.points) {
			point = xieite::geometry::scae(point, scale, origin);
		}
		return polygon;
	}
}

#endif
