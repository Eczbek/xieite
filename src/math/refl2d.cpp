export module xieite:refl2d;

import :is_linear2d;
import :pt2d;
import :poly2d;
import :rot2d;

export namespace xieite {
	template<typename T = double, xieite::is_linear2d<T> L>
	[[nodiscard]] constexpr xieite::pt2d<T> refl2d(xieite::pt2d<T> pt, const L& mirror) noexcept {
		return xieite::rot2d(pt, (mirror.angle() - mirror.a.angle_to(pt)) * 2);
	}

	template<typename T = double, xieite::is_linear2d<T> L0, xieite::is_linear2d<T> L1>
	[[nodiscard]] constexpr L0 refl2d(const L0& line, const L1& mirror) noexcept {
		return L0(
			xieite::rot2d(line.a, (mirror.angle() - mirror.a.angle_to(line.a)) * 2),
			xieite::rot2d(line.b, (mirror.angle() - mirror.a.angle_to(line.b)) * 2)
		);
	}

	template<typename T = double, xieite::is_linear2d<T> L>
	[[nodiscard]] constexpr xieite::poly2d<T> refl2d(xieite::poly2d<T> poly, const L& mirror) noexcept {
		for (xieite::pt2d<T>& pt : poly.pts) {
			pt = xieite::rot2d(pt, (mirror.angle() - mirror.a.angle_to(pt)) * 2);
		}
		return poly;
	}
}
