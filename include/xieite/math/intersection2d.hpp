#ifndef DETAIL_XIEITE_HEADER_MATH_INTERSECTION2D
#	define DETAIL_XIEITE_HEADER_MATH_INTERSECTION2D
#
#	include <vector>
#	include "../math/almost_equal.hpp"
#	include "../math/point2d.hpp"
#	include "../math/segment2d.hpp"
#	include "../trait/is_arith.hpp"
#	include "../trait/is_linear2d.hpp"

namespace xieite {
	template<xieite::is_arith>
	struct polygon2d;

	template<typename Arith = double>
	[[nodiscard]] constexpr std::vector<xieite::point2d<Arith>> intersection2d(xieite::point2d<Arith> point0, xieite::point2d<Arith> point1) noexcept {
		return (point0 == point1)
			? std::vector<xieite::point2d<Arith>> { point0 }
			: std::vector<xieite::point2d<Arith>>();
	}

	template<typename Arith = double, xieite::is_linear2d<Arith> Line>
	[[nodiscard]] constexpr std::vector<xieite::point2d<Arith>> intersection2d(xieite::point2d<Arith> point, const Line& line) noexcept {
		return line.contains(point)
			? std::vector<xieite::point2d<Arith>> { point }
			: std::vector<xieite::point2d<Arith>>();
	}

	template<typename Arith = double>
	[[nodiscard]] constexpr std::vector<xieite::point2d<Arith>> intersection2d(xieite::point2d<Arith> point, const xieite::point2d<Arith>& polygon) noexcept {
		std::vector<xieite::point2d<Arith>> result;
		for (const xieite::segment2d<Arith>& side : polygon.sides()) {
			result.insert_range(result.end(), xieite::intersection2d(point, side));
		}
		return result;
	}

	template<typename Arith = double, xieite::is_linear2d<Arith> Line>
	[[nodiscard]] constexpr std::vector<xieite::point2d<Arith>> intersection2d(const Line& line, xieite::point2d<Arith> point) noexcept {
		return xieite::intersection2d(point, line);
	}

	template<typename Arith = double, xieite::is_linear2d<Arith> Line0, xieite::is_linear2d<Arith> Line1>
	[[nodiscard]] constexpr std::vector<xieite::point2d<Arith>> intersection2d(const Line0& line0, const Line1& line1) noexcept {
		const Arith d = (line0.a.x - line0.b.x) * (line1.a.y - line1.b.y) - (line0.a.y - line0.b.y) * (line1.a.x - line1.b.x);
		if (!xieite::almost_equal(d, 0)) {
			if (const auto intxn = xieite::point2d<Arith>(((line1.a.x - line1.b.x) * (line0.a.x * line0.b.y - line0.a.y * line0.b.x) - (line0.a.x - line0.b.x) * (line1.a.x * line1.b.y - line1.a.y * line1.b.x)) / d, ((line1.a.y - line1.b.y) * (line0.a.x * line0.b.y - line0.a.y * line0.b.x) - (line0.a.y - line0.b.y) * (line1.a.x * line1.b.y - line1.a.y * line1.b.x)) / d); line0.contains(intxn) && line1.contains(intxn)) {
				return std::vector<xieite::point2d<Arith>> { intxn };
			}
		}
		return std::vector<xieite::point2d<Arith>>();
	}

	template<typename Arith = double, xieite::is_linear2d<Arith> Line>
	[[nodiscard]] constexpr std::vector<xieite::point2d<Arith>> intersection2d(const Line& line, const xieite::point2d<Arith>& polygon) noexcept {
		std::vector<xieite::point2d<Arith>> result;
		for (const xieite::segment2d<Arith>& side : polygon.sides()) {
			result.insert_range(result.end(), xieite::intersection2d(line, side));
		}
		return result;
	}

	template<typename Arith = double>
	[[nodiscard]] constexpr std::vector<xieite::point2d<Arith>> intersection2d(const xieite::point2d<Arith>& polygon, xieite::point2d<Arith> point) noexcept {
		return xieite::intersection2d(point, polygon);
	}

	template<typename Arith = double, xieite::is_linear2d<Arith> Line>
	[[nodiscard]] constexpr std::vector<xieite::point2d<Arith>> intersection2d(const xieite::point2d<Arith>& polygon, const Line& line) noexcept {
		return xieite::intersection2d(line, polygon);
	}

	template<typename Arith = double>
	[[nodiscard]] constexpr std::vector<xieite::point2d<Arith>> intersection2d(const xieite::point2d<Arith>& polygon0, const xieite::point2d<Arith>& polygon1) noexcept {
		std::vector<xieite::point2d<Arith>> result;
		const std::vector<xieite::segment2d<Arith>> sides2 = polygon1.sides();
		for (const xieite::segment2d<Arith>& side1 : polygon0.sides()) {
			for (const xieite::segment2d<Arith>& side2 : sides2) {
				result.insert_range(result.end(), xieite::intersection2d(side1, side2));
			}
		}
		return result;
	}
}

#endif
