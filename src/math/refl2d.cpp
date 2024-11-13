export module xieite:refl2d;

import :is_linear2d;
import :poly2d;
import :pt2d;
import :rot2d;

export namespace xieite {
	template<typename T = double, xieite::is_linear2d<T> Line>
	[[nodiscard]] constexpr xieite::pt2d<T> refl2d(xieite::pt2d<T> pt, const Line& mirror) noexcept {
		return xieite::rot2d(pt, (mirror.angle() - mirror.a.angle_to(pt)) * 2);
	}

	template<typename T = double, xieite::is_linear2d<T> Line0, xieite::is_linear2d<T> Line1>
	[[nodiscard]] constexpr Line0 refl2d(const Line0& line, const Line1& mirror) noexcept {
		return Line0(
			xieite::rot2d(line.a, (mirror.angle() - mirror.a.angle_to(line.a)) * 2),
			xieite::rot2d(line.b, (mirror.angle() - mirror.a.angle_to(line.b)) * 2)
		);
	}

	template<typename T = double, xieite::is_linear2d<T> Line>
	[[nodiscard]] constexpr xieite::poly2d<T> refl2d(xieite::poly2d<T> poly, const Line& mirror) noexcept {
		for (xieite::pt2d<T>& pt : poly.pts) {
			pt = xieite::rot2d(pt, (mirror.angle() - mirror.a.angle_to(pt)) * 2);
		}
		return poly;
	}
}
