#pragma once
#include <cmath>
#include <xieite/math/approxEqual.hpp>

namespace xieite::geometry {
	struct Point final {
		double x;
		double y;

		constexpr Point(const double x = 0, const double y = 0) noexcept
		: x(x), y(y) {}

		[[nodiscard]]
		constexpr bool operator==(const xieite::geometry::Point other) const noexcept {
			return xieite::math::approxEqual(x, other.x) && xieite::math::approxEqual(y, other.y);
		}

		[[nodiscard]]
		constexpr bool operator!=(const xieite::geometry::Point other) const noexcept {
			return !operator==(other);
		}

		[[nodiscard]]
		constexpr xieite::geometry::Point rotate(const double angle, const xieite::geometry::Point pivot = xieite::geometry::Point(0, 0)) const noexcept {
			return xieite::geometry::Point(pivot.x + std::cos(angle) * (x - pivot.x) - std::sin(angle) * (y - pivot.y), pivot.y + std::cos(angle) * (y - pivot.y) + std::sin(angle) * (x - pivot.x));
		}
	};
}
