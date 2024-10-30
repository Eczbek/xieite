export module xieite:xlat2d;

import :is_linear2d;
import :point2d;
import :poly2d;

export namespace xieite {
	template<typename T = double>
	[[nodiscard]] constexpr xieite::point2d<T> xlat2d(xieite::point2d<T> point, xieite::point2d<T> diff) noexcept {
		return xieite::point2d<T>(point.x + diff.x, point.y + diff.y);
	}

	template<typename T = double, xieite::is_linear2d<T> L>
	[[nodiscard]] constexpr L xlat2d(const L& line, xieite::point2d<T> diff) noexcept {
		return L(xieite::xlat2d(line.start, diff), xieite::xlat2d(line.end, diff));
	}

	template<typename T = double>
	[[nodiscard]] constexpr xieite::poly2d<T> xlat2d(xieite::poly2d<T> poly, xieite::point2d<T> diff) noexcept {
		for (xieite::point2d<T>& point : poly.points) {
			point = xieite::xlat2d(point, diff);
		}
		return poly;
	}
}
