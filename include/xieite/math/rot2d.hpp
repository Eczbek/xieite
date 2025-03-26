#ifndef DETAIL_XIEITE_HEADER_MATH_ROT2D
#	define DETAIL_XIEITE_HEADER_MATH_ROT2D
#
#	include <cmath>
#	include <type_traits>
#	include "../math/poly2d.hpp"
#	include "../math/pt2d.hpp"
#	include "../trait/is_linear2d.hpp"

namespace xieite {
	template<typename T = double>
	[[nodiscard]] constexpr xieite::pt2d<T> rot2d(xieite::pt2d<T> pt, std::common_type_t<T, double> angle, xieite::pt2d<T> pivot = {}) noexcept {
		return xieite::pt2d<T>(
			pivot.x + std::cos(angle) * (pt.x - pivot.x) - std::sin(angle) * (pt.y - pivot.y),
			pivot.y + std::sin(angle) * (pt.x - pivot.x) + std::cos(angle) * (pt.y - pivot.y)
		);
	}

	template<typename T = double, xieite::is_linear2d<T> Line>
	[[nodiscard]] constexpr Line rot2d(const Line& line, std::common_type_t<T, double> angle, xieite::pt2d<T> pivot = {}) noexcept {
		return Line(
			xieite::rot2d(line.a, angle, pivot),
			xieite::rot2d(line.b, angle, pivot)
		);
	}

	template<typename T = double>
	[[nodiscard]] constexpr xieite::poly2d<T> rot2d(xieite::poly2d<T> poly, std::common_type_t<T, double> angle, xieite::pt2d<T> pivot = {}) noexcept {
		for (xieite::pt2d<T>& pt : poly.pts) {
			pt = xieite::rot2d(pt, angle, pivot);
		}
		return poly;
	}
}

#endif
