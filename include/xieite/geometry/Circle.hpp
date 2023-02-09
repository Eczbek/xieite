#pragma once
#include <xieite/geometry/Point.hpp>
#include <xieite/math/approximatelyEqual.hpp>

namespace xieite::geometry {
	struct Circle {
		xieite::geometry::Point center;
		long double radius;

		constexpr Circle(const xieite::geometry::Point center, const long double radius) noexcept
		: center(center), radius(radius) {}

		[[nodiscard]]
		constexpr bool operator==(const xieite::geometry::Circle& other) const noexcept {
			return (center == other.center) && xieite::math::approximatelyEqual(radius, other.radius);
		}
	};
}
