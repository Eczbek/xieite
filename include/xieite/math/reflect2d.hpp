#ifndef DETAIL_XIEITE_HEADER_MATH_REFLECT2D
#	define DETAIL_XIEITE_HEADER_MATH_REFLECT2D
#
#	include "../math/polygon2d.hpp"
#	include "../math/point2d.hpp"
#	include "../math/rotate2d.hpp"
#	include "../trait/is_linear2d.hpp"

namespace xieite {
	template<typename Arith = double, xieite::is_linear2d<Arith> Line>
	[[nodiscard]] constexpr xieite::point2d<Arith> reflect2d(xieite::point2d<Arith> point, const Line& mirror) noexcept {
		return xieite::rotate2d(point, (mirror.angle() - mirror.a.angle_to(point)) * 2);
	}

	template<typename Arith = double, xieite::is_linear2d<Arith> Line0, xieite::is_linear2d<Arith> Line1>
	[[nodiscard]] constexpr Line0 reflect2d(const Line0& line, const Line1& mirror) noexcept {
		return Line0(
			xieite::rotate2d(line.a, (mirror.angle() - mirror.a.angle_to(line.a)) * 2),
			xieite::rotate2d(line.b, (mirror.angle() - mirror.a.angle_to(line.b)) * 2)
		);
	}

	template<typename Arith = double, xieite::is_linear2d<Arith> Line>
	[[nodiscard]] constexpr xieite::polygon2d<Arith> reflect2d(xieite::polygon2d<Arith> polygon, const Line& mirror) noexcept {
		for (xieite::point2d<Arith>& point : polygon.points) {
			point = xieite::rotate2d(point, (mirror.angle() - mirror.a.angle_to(point)) * 2);
		}
		return polygon;
	}
}

#endif
