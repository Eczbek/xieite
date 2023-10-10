#pragma once

#include <cmath>
#include "../math/almost_equal.hpp"
#include "../math/pi.hpp"
#include "../math/tau.hpp"

namespace xieite::geometry {
	struct Point {
		double x;
		double y;

		constexpr Point(const double x = 0, const double y = 0) noexcept
		: x(x), y(y) {}

		[[nodiscard]] friend constexpr bool operator==(const xieite::geometry::Point point1, const xieite::geometry::Point point2) noexcept {
			return xieite::math::almostEqual(point1.x, point2.x) && xieite::math::almostEqual(point1.y, point2.y);
		}

		[[nodiscard]] constexpr double angleTo(const xieite::geometry::Point point) const noexcept {
			return std::fmod(std::atan2(this->y - point.y, this->x - point.x) + xieite::math::pi<double>, xieite::math::tau<double>);
		}

		[[nodiscard]] constexpr double distanceTo(const xieite::geometry::Point point) const noexcept {
			return std::hypot(this->x - point.x, this->y - point.y);
		}

		[[nodiscard]] constexpr double slopeTo(const xieite::geometry::Point point) const noexcept {
			return xieite::math::almostEqual(this->x, point.x) ? std::numeric_limits<double>::infinity() : ((point.y - this->y) / (point.x - this->x));
		}
	};
}
