#pragma once

#include "../math/poly2d.hpp"
#include "../math/pt2d.hpp"
#include "../trait/islinear2d.hpp"

namespace x4 {
	template<typename T = double>
	[[nodiscard]] constexpr x4::pt2d<T> xlat2d(x4::pt2d<T> pt, x4::pt2d<T> diff) noexcept {
		return x4::pt2d<T>(pt.x + diff.x, pt.y + diff.y);
	}

	template<typename T = double, x4::islinear2d<T> Line>
	[[nodiscard]] constexpr Line xlat2d(const Line& line, x4::pt2d<T> diff) noexcept {
		return Line(x4::xlat2d(line.a, diff), x4::xlat2d(line.b, diff));
	}

	template<typename T = double>
	[[nodiscard]] constexpr x4::poly2d<T> xlat2d(x4::poly2d<T> poly, x4::pt2d<T> diff) noexcept {
		for (x4::pt2d<T>& pt : poly.pts) {
			pt = x4::xlat2d(pt, diff);
		}
		return poly;
	}
}
