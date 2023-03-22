#pragma once

#include <concepts>
#include <cmath>
#include <xieite/geometry/LineLike.hpp>
#include <xieite/geometry/Point.hpp>

namespace xieite::geometry {
	[[nodiscard]]
	constexpr double getSlope(const xieite::geometry::Point point1, const xieite::geometry::Point point2) noexcept {
		return (point2.y - point1.y) / (point2.x - point1.x);
	}

	[[nodiscard]]
	constexpr double getSlope(const std::derived_from<xieite::geometry::LineLike> auto& lineLike) noexcept {
		return xieite::geometry::getSlope(lineLike.start, lineLike.end);
	}
}
