#pragma once

#include <cmath>
#include <xieite/geometry/Point.hpp>
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
			return (this->start == ray.start) && xieite::math::approximatelyEqual((this->end.y - this->start.y) / (this->end.x - this->start.x), (ray.end.y - ray.start.y) / (ray.end.x - ray.start.x));
		}
	};
}
