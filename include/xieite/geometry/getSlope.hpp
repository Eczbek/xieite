#pragma once

#include <cmath>
#include <xieite/concepts/LinearShape.hpp>
#include <xieite/geometry/Point.hpp>

namespace xieite::geometry {
	[[nodiscard]]
	constexpr double getSlope(const xieite::geometry::Point point1, const xieite::geometry::Point point2) noexcept {
		return (point2.y - point1.y) / (point2.x - point1.x);
	}

	[[nodiscard]]
	constexpr double getSlope(const xieite::concepts::LinearShape auto& linearShape) noexcept {
		return xieite::geometry::getSlope(linearShape.start, linearShape.end);
	}
}
