#ifndef DETAIL_XIEITE_HEADER_MATH_SCALE2D
#	define DETAIL_XIEITE_HEADER_MATH_SCALE2D
#
#	include <type_traits>
#	include "../math/polygon2d.hpp"
#	include "../math/point2d.hpp"
#	include "../trait/is_linear2d.hpp"

namespace xieite {
	template<typename Arith = double>
	[[nodiscard]] constexpr xieite::point2d<Arith> scale2d(xieite::point2d<Arith> point, std::common_type_t<Arith, double> scale, xieite::point2d<Arith> origin = {}) noexcept {
		return xieite::point2d<Arith>((point.x - origin.x) * scale + origin.x, (point.y - origin.y) * scale + origin.y);
	}

	template<typename Arith = double, xieite::is_linear2d<Arith> Line>
	[[nodiscard]] constexpr Line scale2d(const Line& line, std::common_type_t<Arith, double> scale, xieite::point2d<Arith> origin = {}) noexcept {
		return Line(xieite::scale2d(line.a, scale, origin), xieite::scale2d(line.b, scale, origin));
	}

	template<typename Arith = double>
	[[nodiscard]] constexpr xieite::polygon2d<Arith> scale(xieite::polygon2d<Arith> polygon, std::common_type_t<Arith, double> scale, xieite::point2d<Arith> origin = {}) noexcept {
		for (xieite::point2d<Arith>& point : polygon.points) {
			point = xieite::scale2d(point, scale, origin);
		}
		return polygon;
	}
}

#endif
