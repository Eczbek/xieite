#ifndef DETAIL_XIEITE_HEADER_MATH_XLAT2D
#	define DETAIL_XIEITE_HEADER_MATH_XLAT2D
#
#	include "../math/poly2d.hpp"
#	include "../math/pt2d.hpp"
#	include "../trait/is_linear2d.hpp"

namespace xieite {
	template<typename T = double>
	[[nodiscard]] constexpr xieite::pt2d<T> xlat2d(xieite::pt2d<T> pt, xieite::pt2d<T> diff) noexcept {
		return xieite::pt2d<T>(pt.x + diff.x, pt.y + diff.y);
	}

	template<typename T = double, xieite::is_linear2d<T> Line>
	[[nodiscard]] constexpr Line xlat2d(const Line& line, xieite::pt2d<T> diff) noexcept {
		return Line(xieite::xlat2d(line.a, diff), xieite::xlat2d(line.b, diff));
	}

	template<typename T = double>
	[[nodiscard]] constexpr xieite::poly2d<T> xlat2d(xieite::poly2d<T> poly, xieite::pt2d<T> diff) noexcept {
		for (xieite::pt2d<T>& pt : poly.pts) {
			pt = xieite::xlat2d(pt, diff);
		}
		return poly;
	}
}

#endif
