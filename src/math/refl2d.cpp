export module xieite:refl2d;

import :is_linear2d;
import :point2d;
import :poly2d;
import :rotate2d;

export namespace xieite {
	template<typename T = double, xieite::is_linear2d<T> L>
	[[nodiscard]] constexpr xieite::point2d<T> refl2d(xieite::point2d<T> point, const L& mirror) noexcept {
		return xieite::rotate2d(point, (mirror.angle() - mirror.start.angle_to(point)) * 2);
	}

	template<typename T = double, xieite::is_linear2d<T> L1, xieite::is_linear2d<T> L2>
	[[nodiscard]] constexpr L1 refl2d(const L1& line, const L2& mirror) noexcept {
		return L1(
			xieite::rotate2d(line.start, (mirror.angle() - mirror.start.angle_to(line.start)) * 2),
			xieite::rotate2d(line.end, (mirror.angle() - mirror.start.angle_to(line.end)) * 2)
		);
	}

	template<typename T = double, xieite::is_linear2d<T> L>
	[[nodiscard]] constexpr xieite::poly2d<T> refl2d(xieite::poly2d<T> poly, const L& mirror) noexcept {
		for (xieite::point2d<T>& point : poly.points) {
			point = xieite::rotate2d(point, (mirror.angle() - mirror.start.angle_to(point)) * 2);
		}
		return poly;
	}
}
