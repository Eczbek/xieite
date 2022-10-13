#pragma once
#include <cmath>
#include <gcufl/math/approxEqual.hpp>

namespace gcufl::geometry {
	struct Point final {
		double x;
		double y;

		constexpr Point(const double x = 0, const double y = 0) noexcept
		: x(x), y(y) {}

		constexpr bool operator==(const gcufl::geometry::Point other) const noexcept {
			return gcufl::math::approxEqual(x, other.x) && gcufl::math::approxEqual(y, other.y);
		}

		constexpr bool operator!=(const gcufl::geometry::Point other) const noexcept {
			return !operator==(other);
		}

		constexpr gcufl::geometry::Point rotate(const double angle, const gcufl::geometry::Point pivot = gcufl::geometry::Point(0, 0)) const noexcept {
			return gcufl::geometry::Point(pivot.x + std::cos(angle) * (x - pivot.x) - std::sin(angle) * (y - pivot.y), pivot.y + std::cos(angle) * (y - pivot.y) + std::sin(angle) * (x - pivot.x));
		}
	};
}
