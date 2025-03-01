#pragma once

#include <cmath>
#include <type_traits>
#include "../math/poly2d.hpp"
#include "../math/pt2d.hpp"
#include "../trait/islinear2d.hpp"

namespace x4 {
	template<typename T = double>
	[[nodiscard]] constexpr x4::pt2d<T> rot2d(x4::pt2d<T> pt, std::common_type_t<T, double> angle, x4::pt2d<T> pivot = {}) noexcept {
		return x4::pt2d<T>(
			pivot.x + std::cos(angle) * (pt.x - pivot.x) - std::sin(angle) * (pt.y - pivot.y),
			pivot.y + std::sin(angle) * (pt.x - pivot.x) + std::cos(angle) * (pt.y - pivot.y)
		);
	}

	template<typename T = double, x4::islinear2d<T> Line>
	[[nodiscard]] constexpr Line rot2d(const Line& line, std::common_type_t<T, double> angle, x4::pt2d<T> pivot = {}) noexcept {
		return Line(
			x4::rot2d(line.a, angle, pivot),
			x4::rot2d(line.b, angle, pivot)
		);
	}

	template<typename T = double>
	[[nodiscard]] constexpr x4::poly2d<T> rot2d(x4::poly2d<T> poly, std::common_type_t<T, double> angle, x4::pt2d<T> pivot = {}) noexcept {
		for (x4::pt2d<T>& pt : poly.pts) {
			pt = x4::rot2d(pt, angle, pivot);
		}
		return poly;
	}
}
