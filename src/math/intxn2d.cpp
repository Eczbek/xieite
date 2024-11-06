export module xieite:intxn2d;

import std;
import :almost_eq;
import :is_arith;
import :is_linear2d;
import :point2d;

export namespace xieite {
	template<xieite::is_arith>
	struct poly2d;

	template<typename T = double>
	[[nodiscard]] constexpr std::vector<xieite::point2d<T>> intxn2d(xieite::point2d<T> point0, xieite::point2d<T> point1) noexcept {
		return (point0 == point1)
			? std::vector<xieite::point2d<T>> { point0 }
			: std::vector<xieite::point2d<T>>();
	}

	template<typename T = double, xieite::is_linear2d<T> L>
	[[nodiscard]] constexpr std::vector<xieite::point2d<T>> intxn2d(xieite::point2d<T> point, const L& line) noexcept {
		return line.contains(point)
			? std::vector<xieite::point2d<T>> { point }
			: std::vector<xieite::point2d<T>>();
	}

	template<typename T = double>
	[[nodiscard]] constexpr std::vector<xieite::point2d<T>> intxn2d(xieite::point2d<T> point, const xieite::point2d<T>& poly) noexcept {
		std::vector<xieite::point2d<T>> result;
		for (const xieite::segm<T>& side : poly.sides()) {
			const std::vector<xieite::point2d<T>> intxns = xieite::intxn2d(point, side);
			result.insert(result.end(), intxns.begin(), intxns.end());
		}
		return result;
	}

	template<typename T = double, xieite::is_linear2d<T> L>
	[[nodiscard]] constexpr std::vector<xieite::point2d<T>> intxn2d(const L& line, xieite::point2d<T> point) noexcept {
		return xieite::intxn2d(point, line);
	}

	template<typename T = double, xieite::is_linear2d<T> L0, xieite::is_linear2d<T> L1>
	[[nodiscard]] constexpr std::vector<xieite::point2d<T>> intxn2d(const L0& line0, const L1& line1) noexcept {
		const double d = (line0.start.x - line0.end.x) * (line1.start.y - line1.end.y) - (line0.start.y - line0.end.y) * (line1.start.x - line1.end.x);
		if (!xieite::almost_eq<T>(d, 0)) {
			const auto intxn = xieite::point2d<T>(((line1.start.x - line1.end.x) * (line0.start.x * line0.end.y - line0.start.y * line0.end.x) - (line0.start.x - line0.end.x) * (line1.start.x * line1.end.y - line1.start.y * line1.end.x)) / d, ((line1.start.y - line1.end.y) * (line0.start.x * line0.end.y - line0.start.y * line0.end.x) - (line0.start.y - line0.end.y) * (line1.start.x * line1.end.y - line1.start.y * line1.end.x)) / d);
			if (line0.contains(intxn) && line1.contains(intxn)) {
				return std::vector<xieite::point2d<T>> { intxn };
			}
		}
		return std::vector<xieite::point2d<T>>();
	}

	template<typename T = double, xieite::is_linear2d<T> L>
	[[nodiscard]] constexpr std::vector<xieite::point2d<T>> intxn2d(const L& line, const xieite::point2d<T>& poly) noexcept {
		std::vector<xieite::point2d<T>> result;
		for (const xieite::segm<T>& side : poly.sides()) {
			const std::vector<xieite::point2d<T>> intxns = xieite::intxn2d(line, side);
			result.insert(result.end(), intxns.begin(), intxns.end());
		}
		return result;
	}

	template<typename T = double>
	[[nodiscard]] constexpr std::vector<xieite::point2d<T>> intxn2d(const xieite::point2d<T>& poly, xieite::point2d<T> point) noexcept {
		return xieite::intxn2d(point, poly);
	}

	template<typename T = double, xieite::is_linear2d<T> L>
	[[nodiscard]] constexpr std::vector<xieite::point2d<T>> intxn2d(const xieite::point2d<T>& poly, const L& line) noexcept {
		return xieite::intxn2d(line, poly);
	}

	template<typename T = double>
	[[nodiscard]] constexpr std::vector<xieite::point2d<T>> intxn2d(const xieite::point2d<T>& poly0, const xieite::point2d<T>& poly1) noexcept {
		std::vector<xieite::point2d<T>> result;
		const std::vector<xieite::segm<T>> sides2 = poly1.sides();
		for (const xieite::segm<T>& side1 : poly0.sides()) {
			for (const xieite::segm<T>& side2 : sides2) {
				const std::vector<xieite::point2d<T>> intxns = xieite::intxn2d(side1, side2);
				result.insert(result.end(), intxns.begin(), intxns.end());
			}
		}
		return result;
	}
}
