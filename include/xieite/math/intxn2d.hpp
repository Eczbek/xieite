#pragma once

#include <vector>
#include "../math/almost_eq.hpp"
#include "../math/pt2d.hpp"
#include "../math/segm2d.hpp"
#include "../trait/is_arith.hpp"
#include "../trait/is_linear2d.hpp"

namespace xieite {
	template<xieite::is_arith>
	struct poly2d;

	template<typename T = double>
	[[nodiscard]] constexpr std::vector<xieite::pt2d<T>> intxn2d(xieite::pt2d<T> pt0, xieite::pt2d<T> pt1) noexcept {
		return (pt0 == pt1)
			? std::vector<xieite::pt2d<T>> { pt0 }
			: std::vector<xieite::pt2d<T>>();
	}

	template<typename T = double, xieite::is_linear2d<T> Line>
	[[nodiscard]] constexpr std::vector<xieite::pt2d<T>> intxn2d(xieite::pt2d<T> pt, const Line& line) noexcept {
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

	template<typename T = double, xieite::is_linear2d<T> Line>
	[[nodiscard]] constexpr std::vector<xieite::pt2d<T>> intxn2d(const Line& line, xieite::pt2d<T> pt) noexcept {
		return xieite::intxn2d(pt, line);
	}

	template<typename T = double, xieite::is_linear2d<T> Line0, xieite::is_linear2d<T> Line1>
	[[nodiscard]] constexpr std::vector<xieite::pt2d<T>> intxn2d(const Line0& line0, const Line1& line1) noexcept {
		const T d = (line0.a.x - line0.b.x) * (line1.a.y - line1.b.y) - (line0.a.y - line0.b.y) * (line1.a.x - line1.b.x);
		if (!xieite::almost_eq(d, static_cast<T>(0))) {
			if (const auto intxn = xieite::pt2d<T>(((line1.a.x - line1.b.x) * (line0.a.x * line0.b.y - line0.a.y * line0.b.x) - (line0.a.x - line0.b.x) * (line1.a.x * line1.b.y - line1.a.y * line1.b.x)) / d, ((line1.a.y - line1.b.y) * (line0.a.x * line0.b.y - line0.a.y * line0.b.x) - (line0.a.y - line0.b.y) * (line1.a.x * line1.b.y - line1.a.y * line1.b.x)) / d); line0.contains(intxn) && line1.contains(intxn)) {
				return std::vector<xieite::pt2d<T>> { intxn };
			}
		}
		return std::vector<xieite::pt2d<T>>();
	}

	template<typename T = double, xieite::is_linear2d<T> Line>
	[[nodiscard]] constexpr std::vector<xieite::pt2d<T>> intxn2d(const Line& line, const xieite::pt2d<T>& poly) noexcept {
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

	template<typename T = double, xieite::is_linear2d<T> Line>
	[[nodiscard]] constexpr std::vector<xieite::pt2d<T>> intxn2d(const xieite::pt2d<T>& poly, const Line& line) noexcept {
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
