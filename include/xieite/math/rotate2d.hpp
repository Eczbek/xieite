#ifndef DETAIL_XIEITE_HEADER_MATH_ROTATE2D
#	define DETAIL_XIEITE_HEADER_MATH_ROTATE2D
#
#	include <cmath>
#	include <type_traits>
#	include "../math/polygon2d.hpp"
#	include "../math/point2d.hpp"
#	include "../trait/is_linear2d.hpp"

namespace xieite {
	template<typename Arith = double>
	[[nodiscard]] constexpr xieite::point2d<Arith> rotate2d(xieite::point2d<Arith> point, std::common_type_t<Arith, double> angle, xieite::point2d<Arith> pivot = {}) noexcept {
		return xieite::point2d<Arith>(
			pivot.x + std::cos(angle) * (point.x - pivot.x) - std::sin(angle) * (point.y - pivot.y),
			pivot.y + std::sin(angle) * (point.x - pivot.x) + std::cos(angle) * (point.y - pivot.y)
		);
	}

	template<typename Arith = double, xieite::is_linear2d<Arith> Line>
	[[nodiscard]] constexpr Line rotate2d(const Line& line, std::common_type_t<Arith, double> angle, xieite::point2d<Arith> pivot = {}) noexcept {
		return Line(
			xieite::rotate2d(line.a, angle, pivot),
			xieite::rotate2d(line.b, angle, pivot)
		);
	}

	template<typename Arith = double>
	[[nodiscard]] constexpr xieite::polygon2d<Arith> rotate2d(xieite::polygon2d<Arith> polygon, std::common_type_t<Arith, double> angle, xieite::point2d<Arith> pivot = {}) noexcept {
		for (xieite::point2d<Arith>& point : polygon.points) {
			point = xieite::rotate2d(point, angle, pivot);
		}
		return polygon;
	}
}

#endif
