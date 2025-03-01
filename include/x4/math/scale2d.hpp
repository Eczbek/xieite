#pragma once

#include <type_traits>
#include "../math/poly2d.hpp"
#include "../math/pt2d.hpp"
#include "../trait/islinear2d.hpp"

namespace x4 {
	template<typename T = double>
	[[nodiscard]] constexpr x4::pt2d<T> scale2d(x4::pt2d<T> pt, std::common_type_t<T, double> scale, x4::pt2d<T> origin = {}) noexcept {
		return x4::pt2d<T>((pt.x - origin.x) * scale + origin.x, (pt.y - origin.y) * scale + origin.y);
	}

	template<typename T = double, x4::islinear2d<T> Line>
	[[nodiscard]] constexpr Line scale2d(const Line& line, std::common_type_t<T, double> scale, x4::pt2d<T> origin = {}) noexcept {
		return Line(x4::scale2d(line.a, scale, origin), x4::scale2d(line.b, scale, origin));
	}

	template<typename T = double>
	[[nodiscard]] constexpr x4::poly2d<T> scale(x4::poly2d<T> poly, std::common_type_t<T, double> scale, x4::pt2d<T> origin = {}) noexcept {
		for (x4::pt2d<T>& pt : poly.pts) {
			pt = x4::scale2d(pt, scale, origin);
		}
		return poly;
	}
}
