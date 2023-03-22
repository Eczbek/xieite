#pragma once

#include <cmath>
#include <concepts>
#include <optional>
#include <xieite/geometry/LineLike.hpp>
#include <xieite/geometry/Point.hpp>
#include <xieite/geometry/getSlope.hpp>

namespace xieite::geometry {
	[[nodiscard]]
	constexpr std::optional<xieite::geometry::Point> getInterceptY(const std::derived_from<xieite::geometry::LineLike> auto& lineLike) noexcept {
		return std::isinf(xieite::geometry::getSlope(lineLike)) ? std::nullopt : std::optional(xieite::geometry::Point(0.0, lineLike.start.y - lineLike.start.x * (lineLike.end.y - lineLike.start.y) / (lineLike.end.x - lineLike.start.x)));
	}
}
