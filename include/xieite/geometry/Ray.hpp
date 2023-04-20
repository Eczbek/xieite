#pragma once

#include <cmath>
#include <xieite/geometry/Point.hpp>
#include <xieite/geometry/getSlope.hpp>
#include <xieite/math/approximatelyEqual.hpp>

namespace xieite::geometry {
	struct Ray {
		xieite::geometry::Point start;
		xieite::geometry::Point end;

		constexpr Ray(const xieite::geometry::Point start, const xieite::geometry::Point end) noexcept
		: start(start), end(end) {}

		constexpr Ray(const xieite::geometry::Point start, const double angle) noexcept
		: start(start), end(std::cos(angle), std::sin(angle)) {}

		[[nodiscard]]
		constexpr bool operator==(const xieite::geometry::Ray& ray) const noexcept {
			return (this->start == ray.start) && xieite::math::approximatelyEqual(xieite::geometry::getSlope(*this), xieite::geometry::getSlope(ray));
		}
	};
}
