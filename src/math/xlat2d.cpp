export module xieite:xlat2d;

import :is_linear2d;
import :point2d;
import :poly2d;

export namespace xieite {
	template<typename T = double>
	[[nodiscard]] constexpr xieite::pt2d<T> xlat2d(xieite::pt2d<T> pt, xieite::pt2d<T> diff) noexcept {
		return xieite::pt2d<T>(pt.x + diff.x, pt.y + diff.y);
	}

	template<typename T = double, xieite::is_linear2d<T> L>
	[[nodiscard]] constexpr L xlat2d(const L& line, xieite::pt2d<T> diff) noexcept {
		return L(xieite::xlat2d(line.a, diff), xieite::xlat2d(line.b, diff));
	}

	template<typename T = double>
	[[nodiscard]] constexpr xieite::poly2d<T> xlat2d(xieite::poly2d<T> poly, xieite::pt2d<T> diff) noexcept {
		for (xieite::pt2d<T>& pt : poly.pts) {
			pt = xieite::xlat2d(pt, diff);
		}
		return poly;
	}
}
