#pragma once
#include <cmath> // std::cos, std::sin
#include <xieite/math/approxEqual.hpp> // xieite::math::approxEqual

namespace xieite::geometry {
	class Point {
	public:
		long double x;
		long double y;

		constexpr Point(const long double x = 0, const long double y = 0) noexcept
		: x(x), y(y) {}

		[[nodiscard]]
		constexpr bool operator==(const xieite::geometry::Point other) const noexcept {
			return xieite::math::approxEqual(x, other.x) && xieite::math::approxEqual(y, other.y);
		}

		[[nodiscard]]
		constexpr xieite::geometry::Point rotate(const long double angle, const xieite::geometry::Point pivot = xieite::geometry::Point(0, 0)) const noexcept {
			return xieite::geometry::Point(pivot.x + std::cos(angle) * (x - pivot.x) - std::sin(angle) * (y - pivot.y), pivot.y + std::cos(angle) * (y - pivot.y) + std::sin(angle) * (x - pivot.x));
		}
	};
}
