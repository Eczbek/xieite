#pragma once
#include <concepts> // std::derived_from
#include <optional> // std::nullopt, std::optional
#include <xieite/geometry/LineLike.hpp>
#include <xieite/geometry/Point.hpp>
#include <xieite/geometry/getSlope.hpp>
#include <xieite/math/approximatelyEqual.hpp>

namespace xieite::geometry {
	template<std::derived_from<xieite::geometry::LineLike> L>
	[[nodiscard]]
	constexpr std::optional<xieite::geometry::Point> getInterceptX(const L& lineLike) noexcept {
		return xieite::math::approximatelyEqual(xieite::geometry::getSlope(lineLike), 0) ? std::nullopt : std::optional(xieite::geometry::Point(lineLike.start.x - lineLike.start.y * (lineLike.end.x - lineLike.start.x) / (lineLike.end.y - lineLike.start.y), 0));
	}
}
