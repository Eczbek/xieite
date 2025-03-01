#pragma once

#include <vector>
#include "../math/almosteq.hpp"
#include "../math/pt2d.hpp"
#include "../math/segm2d.hpp"
#include "../trait/isarith.hpp"
#include "../trait/islinear2d.hpp"

namespace x4 {
	template<x4::isarith>
	struct poly2d;

	template<typename T = double>
	[[nodiscard]] constexpr std::vector<x4::pt2d<T>> intxn2d(x4::pt2d<T> pt0, x4::pt2d<T> pt1) noexcept {
		return (pt0 == pt1)
			? std::vector<x4::pt2d<T>> { pt0 }
			: std::vector<x4::pt2d<T>>();
	}

	template<typename T = double, x4::islinear2d<T> Line>
	[[nodiscard]] constexpr std::vector<x4::pt2d<T>> intxn2d(x4::pt2d<T> pt, const Line& line) noexcept {
		return line.contains(pt)
			? std::vector<x4::pt2d<T>> { pt }
			: std::vector<x4::pt2d<T>>();
	}

	template<typename T = double>
	[[nodiscard]] constexpr std::vector<x4::pt2d<T>> intxn2d(x4::pt2d<T> pt, const x4::pt2d<T>& poly) noexcept {
		std::vector<x4::pt2d<T>> result;
		for (const x4::segm2d<T>& side : poly.sides()) {
			result.insert_range(result.end(), x4::intxn2d(pt, side));
		}
		return result;
	}

	template<typename T = double, x4::islinear2d<T> Line>
	[[nodiscard]] constexpr std::vector<x4::pt2d<T>> intxn2d(const Line& line, x4::pt2d<T> pt) noexcept {
		return x4::intxn2d(pt, line);
	}

	template<typename T = double, x4::islinear2d<T> Line0, x4::islinear2d<T> Line1>
	[[nodiscard]] constexpr std::vector<x4::pt2d<T>> intxn2d(const Line0& line0, const Line1& line1) noexcept {
		const T d = (line0.a.x - line0.b.x) * (line1.a.y - line1.b.y) - (line0.a.y - line0.b.y) * (line1.a.x - line1.b.x);
		if (!x4::almosteq(d, static_cast<T>(0))) {
			if (const auto intxn = x4::pt2d<T>(((line1.a.x - line1.b.x) * (line0.a.x * line0.b.y - line0.a.y * line0.b.x) - (line0.a.x - line0.b.x) * (line1.a.x * line1.b.y - line1.a.y * line1.b.x)) / d, ((line1.a.y - line1.b.y) * (line0.a.x * line0.b.y - line0.a.y * line0.b.x) - (line0.a.y - line0.b.y) * (line1.a.x * line1.b.y - line1.a.y * line1.b.x)) / d); line0.contains(intxn) && line1.contains(intxn)) {
				return std::vector<x4::pt2d<T>> { intxn };
			}
		}
		return std::vector<x4::pt2d<T>>();
	}

	template<typename T = double, x4::islinear2d<T> Line>
	[[nodiscard]] constexpr std::vector<x4::pt2d<T>> intxn2d(const Line& line, const x4::pt2d<T>& poly) noexcept {
		std::vector<x4::pt2d<T>> result;
		for (const x4::segm2d<T>& side : poly.sides()) {
			result.insert_range(result.end(), x4::intxn2d(line, side));
		}
		return result;
	}

	template<typename T = double>
	[[nodiscard]] constexpr std::vector<x4::pt2d<T>> intxn2d(const x4::pt2d<T>& poly, x4::pt2d<T> pt) noexcept {
		return x4::intxn2d(pt, poly);
	}

	template<typename T = double, x4::islinear2d<T> Line>
	[[nodiscard]] constexpr std::vector<x4::pt2d<T>> intxn2d(const x4::pt2d<T>& poly, const Line& line) noexcept {
		return x4::intxn2d(line, poly);
	}

	template<typename T = double>
	[[nodiscard]] constexpr std::vector<x4::pt2d<T>> intxn2d(const x4::pt2d<T>& poly0, const x4::pt2d<T>& poly1) noexcept {
		std::vector<x4::pt2d<T>> result;
		const std::vector<x4::segm2d<T>> sides2 = poly1.sides();
		for (const x4::segm2d<T>& side1 : poly0.sides()) {
			for (const x4::segm2d<T>& side2 : sides2) {
				result.insert_range(result.end(), x4::intxn2d(side1, side2));
			}
		}
		return result;
	}
}
