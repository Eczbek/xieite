export module xieite:intxn2d;

import std;
import :almost_eq;
import :is_arith;
import :is_linear2d;
import :pt2d;

export namespace xieite {
	template<xieite::is_arith>
	struct poly2d;

	template<typename T = double>
	[[nodiscard]] constexpr std::vector<xieite::pt2d<T>> intxn2d(xieite::pt2d<T> pt0, xieite::pt2d<T> pt1) noexcept {
		return (pt0 == pt1)
			? std::vector<xieite::pt2d<T>> { pt0 }
			: std::vector<xieite::pt2d<T>>();
	}

	template<typename T = double, xieite::is_linear2d<T> L>
	[[nodiscard]] constexpr std::vector<xieite::pt2d<T>> intxn2d(xieite::pt2d<T> pt, const L& line) noexcept {
		return line.contains(pt)
			? std::vector<xieite::pt2d<T>> { pt }
			: std::vector<xieite::pt2d<T>>();
	}

	template<typename T = double>
	[[nodiscard]] constexpr std::vector<xieite::pt2d<T>> intxn2d(xieite::pt2d<T> pt, const xieite::pt2d<T>& poly) noexcept {
		std::vector<xieite::pt2d<T>> result;
		for (const xieite::segm2d<T>& side : poly.sides()) {
			result.insert_range(result.end(), xieite::intxn2d(pt, side));
		}
		return result;
	}

	template<typename T = double, xieite::is_linear2d<T> L>
	[[nodiscard]] constexpr std::vector<xieite::pt2d<T>> intxn2d(const L& line, xieite::pt2d<T> pt) noexcept {
		return xieite::intxn2d(pt, line);
	}

	template<typename T = double, xieite::is_linear2d<T> L0, xieite::is_linear2d<T> L1>
	[[nodiscard]] constexpr std::vector<xieite::pt2d<T>> intxn2d(const L0& line0, const L1& line1) noexcept {
		const double d = (line0.a.x - line0.b.x) * (line1.a.y - line1.b.y) - (line0.a.y - line0.b.y) * (line1.a.x - line1.b.x);
		if (!xieite::almost_eq<T>(d, 0)) {
			if (const auto intxn = xieite::pt2d<T>(((line1.a.x - line1.b.x) * (line0.a.x * line0.b.y - line0.a.y * line0.b.x) - (line0.a.x - line0.b.x) * (line1.a.x * line1.b.y - line1.a.y * line1.b.x)) / d, ((line1.a.y - line1.b.y) * (line0.a.x * line0.b.y - line0.a.y * line0.b.x) - (line0.a.y - line0.b.y) * (line1.a.x * line1.b.y - line1.a.y * line1.b.x)) / d); line0.contains(intxn) && line1.contains(intxn)) {
				return std::vector<xieite::pt2d<T>> { intxn };
			}
		}
		return std::vector<xieite::pt2d<T>>();
	}

	template<typename T = double, xieite::is_linear2d<T> L>
	[[nodiscard]] constexpr std::vector<xieite::pt2d<T>> intxn2d(const L& line, const xieite::pt2d<T>& poly) noexcept {
		std::vector<xieite::pt2d<T>> result;
		for (const xieite::segm2d<T>& side : poly.sides()) {
			result.insert_range(result.end(), xieite::intxn2d(line, side));
		}
		return result;
	}

	template<typename T = double>
	[[nodiscard]] constexpr std::vector<xieite::pt2d<T>> intxn2d(const xieite::pt2d<T>& poly, xieite::pt2d<T> pt) noexcept {
		return xieite::intxn2d(pt, poly);
	}

	template<typename T = double, xieite::is_linear2d<T> L>
	[[nodiscard]] constexpr std::vector<xieite::pt2d<T>> intxn2d(const xieite::pt2d<T>& poly, const L& line) noexcept {
		return xieite::intxn2d(line, poly);
	}

	template<typename T = double>
	[[nodiscard]] constexpr std::vector<xieite::pt2d<T>> intxn2d(const xieite::pt2d<T>& poly0, const xieite::pt2d<T>& poly1) noexcept {
		std::vector<xieite::pt2d<T>> result;
		const std::vector<xieite::segm2d<T>> sides2 = poly1.sides();
		for (const xieite::segm2d<T>& side1 : poly0.sides()) {
			for (const xieite::segm2d<T>& side2 : sides2) {
				result.insert_range(result.end(), xieite::intxn2d(side1, side2));
			}
		}
		return result;
	}
}
