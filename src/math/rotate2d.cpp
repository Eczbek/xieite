export module xieite:rotate2d;

import std;
import :is_linear2d;
import :point2d;
import :poly2d;

export namespace xieite {
	template<typename T = double>
	[[nodiscard]] constexpr xieite::point2d<T> rotate2d(xieite::point2d<T> point, std::common_type_t<T, double> angle, xieite::point2d<T> pivot = {}) noexcept {
		return xieite::point2d<T>(
			pivot.x + std::cos(angle) * (point.x - pivot.x) - std::sin(angle) * (point.y - pivot.y),
			pivot.y + std::sin(angle) * (point.x - pivot.x) + std::cos(angle) * (point.y - pivot.y)
		);
	}

	template<typename T = double, xieite::is_linear2d<T> L>
	[[nodiscard]] constexpr L rotate2d(const L& line, std::common_type_t<T, double> angle, xieite::point2d<T> pivot = {}) noexcept {
		return L(
			xieite::rotate2d(line.start, angle, pivot),
			xieite::rotate2d(line.end, angle, pivot)
		);
	}

	template<typename T = double>
	[[nodiscard]] constexpr xieite::poly2d<T> rotate2d(xieite::poly2d<T> poly, std::common_type_t<T, double> angle, xieite::point2d<T> pivot = {}) noexcept {
		for (xieite::point2d<T>& point : poly.points) {
			point = xieite::rotate2d(point, angle, pivot);
		}
		return poly;
	}
}
