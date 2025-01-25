#pragma once

#include <type_traits>
#include "../math/poly2d.hpp"
#include "../math/pt2d.hpp"
#include "../trait/is_linear2d.hpp"

namespace xieite {
	template<typename T = double>
	[[nodiscard]] constexpr xieite::pt2d<T> scale2d(xieite::pt2d<T> pt, std::common_type_t<T, double> scale, xieite::pt2d<T> origin = {}) noexcept {
		return xieite::pt2d<T>((pt.x - origin.x) * scale + origin.x, (pt.y - origin.y) * scale + origin.y);
	}

	template<typename T = double, xieite::is_linear2d<T> Line>
	[[nodiscard]] constexpr Line scale2d(const Line& line, std::common_type_t<T, double> scale, xieite::pt2d<T> origin = {}) noexcept {
		return Line(xieite::scale2d(line.a, scale, origin), xieite::scale2d(line.b, scale, origin));
	}

	template<typename T = double>
	[[nodiscard]] constexpr xieite::poly2d<T> scale(xieite::poly2d<T> poly, std::common_type_t<T, double> scale, xieite::pt2d<T> origin = {}) noexcept {
		for (xieite::pt2d<T>& pt : poly.pts) {
			pt = xieite::scale2d(pt, scale, origin);
		}
		return poly;
	}
}
