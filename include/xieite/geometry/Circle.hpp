#pragma once

#include <xieite/geometry/Point.hpp>
#include <xieite/math/approximatelyEqual.hpp>

namespace xieite::geometry {
	struct Circle {
		xieite::geometry::Point center;
		double radius;

		constexpr Circle(const xieite::geometry::Point center, const double radius) noexcept
		: center(center), radius(radius) {}

		[[nodiscard]]
		constexpr bool operator==(const xieite::geometry::Circle& circle) const noexcept {
			return (this->center == circle.center) && xieite::math::approximatelyEqual(this->radius, circle.radius);
		}
	};
}
