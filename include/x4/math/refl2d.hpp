#pragma once

#include "../math/poly2d.hpp"
#include "../math/pt2d.hpp"
#include "../math/rot2d.hpp"
#include "../trait/islinear2d.hpp"

namespace x4 {
	template<typename T = double, x4::islinear2d<T> Line>
	[[nodiscard]] constexpr x4::pt2d<T> refl2d(x4::pt2d<T> pt, const Line& mirror) noexcept {
		return x4::rot2d(pt, (mirror.angle() - mirror.a.angle_to(pt)) * 2);
	}

	template<typename T = double, x4::islinear2d<T> Line0, x4::islinear2d<T> Line1>
	[[nodiscard]] constexpr Line0 refl2d(const Line0& line, const Line1& mirror) noexcept {
		return Line0(
			x4::rot2d(line.a, (mirror.angle() - mirror.a.angle_to(line.a)) * 2),
			x4::rot2d(line.b, (mirror.angle() - mirror.a.angle_to(line.b)) * 2)
		);
	}

	template<typename T = double, x4::islinear2d<T> Line>
	[[nodiscard]] constexpr x4::poly2d<T> refl2d(x4::poly2d<T> poly, const Line& mirror) noexcept {
		for (x4::pt2d<T>& pt : poly.pts) {
			pt = x4::rot2d(pt, (mirror.angle() - mirror.a.angle_to(pt)) * 2);
		}
		return poly;
	}
}
