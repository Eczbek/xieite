export module xieite:scale2d;

import std;
import :is_linear2d;
import :point2d;
import :poly2d;

export namespace xieite {
	template<typename T = double>
	[[nodiscard]] constexpr xieite::pt2d<T> scale2d(xieite::pt2d<T> pt, std::common_type_t<T, double> scale, xieite::pt2d<T> origin = {}) noexcept {
		return xieite::pt2d<T>((pt.x - origin.x) * scale + origin.x, (pt.y - origin.y) * scale + origin.y);
	}

	template<typename T = double, xieite::is_linear2d<T> L>
	[[nodiscard]] constexpr L scale2d(const L& line, std::common_type_t<T, double> scale, xieite::pt2d<T> origin = {}) noexcept {
		return L(xieite::scale2d(line.a, scale, origin), xieite::scale2d(line.b, scale, origin));
	}

	template<typename T = double>
	[[nodiscard]] constexpr xieite::poly2d<T> scale(xieite::poly2d<T> poly, std::common_type_t<T, double> scale, xieite::pt2d<T> origin = {}) noexcept {
		for (xieite::pt2d<T>& pt : poly.pts) {
			pt = xieite::scale2d(pt, scale, origin);
		}
		return poly;
	}
}
