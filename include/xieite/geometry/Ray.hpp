#pragma once
#include <cmath> // std::cos, std::sin
#include <xieite/geometry/LineLike.hpp>
#include <xieite/geometry/Point.hpp>
#include <xieite/geometry/getSlope.hpp>
#include <xieite/math/approximatelyEqual.hpp>

namespace xieite::geometry {
	struct Ray
	: xieite::geometry::LineLike {
		constexpr Ray(const xieite::geometry::Point start, const xieite::geometry::Point end) noexcept
		: xieite::geometry::LineLike(start, end) {}

		constexpr Ray(const xieite::geometry::Point start, const double angle) noexcept
		: xieite::geometry::LineLike(start, xieite::geometry::Point(std::cos(angle), std::sin(angle))) {}

		[[nodiscard]]
		constexpr bool operator==(const xieite::geometry::Ray& other) const noexcept {
			return (start == other.start) && xieite::math::approximatelyEqual(xieite::geometry::getSlope(*this), xieite::geometry::getSlope(other));
		}
	};
}
