#ifndef DETAIL_XIEITE_HEADER_MATH_TRANSLATE2D
#	define DETAIL_XIEITE_HEADER_MATH_TRANSLATE2D
#
#	include "../math/polygon2d.hpp"
#	include "../math/point2d.hpp"
#	include "../trait/is_linear2d.hpp"

namespace xieite {
	template<typename Arith = double>
	[[nodiscard]] constexpr xieite::point2d<Arith> translate2d(xieite::point2d<Arith> point, xieite::point2d<Arith> diff) noexcept {
		return xieite::point2d<Arith>(point.x + diff.x, point.y + diff.y);
	}

	template<typename Arith = double, xieite::is_linear2d<Arith> Line>
	[[nodiscard]] constexpr Line translate2d(const Line& line, xieite::point2d<Arith> diff) noexcept {
		return Line(xieite::translate2d(line.a, diff), xieite::translate2d(line.b, diff));
	}

	template<typename Arith = double>
	[[nodiscard]] constexpr xieite::polygon2d<Arith> translate2d(xieite::polygon2d<Arith> polygon, xieite::point2d<Arith> diff) noexcept {
		for (xieite::point2d<Arith>& point : polygon.points) {
			point = xieite::translate2d(point, diff);
		}
		return polygon;
	}
}

#endif
