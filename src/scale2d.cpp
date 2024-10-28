export module xieite:scale2d;

import std;
import :is_linear2d;
import :point2d;
import :poly2d;

export namespace xieite {
	template<typename T = double>
	[[nodiscard]] constexpr xieite::point2d<T> scale2d(xieite::point2d<T> point, std::common_type_t<T, double> scale, xieite::point2d<T> origin = {}) noexcept {
		return xieite::point2d<T>((point.x - origin.x) * scale + origin.x, (point.y - origin.y) * scale + origin.y);
	}

	template<typename T = double, xieite::is_linear2d<T> L>
	[[nodiscard]] constexpr L scale2d(const L& line, std::common_type_t<T, double> scale, xieite::point2d<T> origin = {}) noexcept {
		return L(xieite::scale2d(line.start, scale, origin), xieite::scale2d(line.end, scale, origin));
	}

	template<typename T = double>
	[[nodiscard]] constexpr xieite::poly2d<T> scale(xieite::poly2d<T> poly, std::common_type_t<T, double> scale, xieite::point2d<T> origin = {}) noexcept {
		for (xieite::point2d<T>& point : poly.points) {
			point = xieite::scale2d(point, scale, origin);
		}
		return poly;
	}
}
