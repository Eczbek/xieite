#pragma once

#include <concepts>
#include <optional>
#include <xieite/geometry/LineLike.hpp>
#include <xieite/geometry/Point.hpp>
#include <xieite/geometry/getSlope.hpp>
#include <xieite/math/approximatelyEqual.hpp>

namespace xieite::geometry {
	[[nodiscard]]
	constexpr std::optional<xieite::geometry::Point> getInterceptX(const std::derived_from<xieite::geometry::LineLike> auto& lineLike) noexcept {
		return xieite::math::approximatelyEqual(xieite::geometry::getSlope(lineLike), 0.0) ? std::nullopt : std::optional(xieite::geometry::Point(lineLike.start.x - lineLike.start.y * (lineLike.end.x - lineLike.start.x) / (lineLike.end.y - lineLike.start.y), 0.0));
	}
}
