#pragma once

#include <optional>
#include <xieite/concepts/LinearShape.hpp>
#include <xieite/geometry/Point.hpp>
#include <xieite/geometry/getSlope.hpp>
#include <xieite/math/approximatelyEqual.hpp>

namespace xieite::geometry {
	[[nodiscard]]
	constexpr std::optional<xieite::geometry::Point> getInterceptX(const xieite::concepts::LinearShape auto& linearShape) noexcept {
		return xieite::math::approximatelyEqual(xieite::geometry::getSlope(linearShape), 0.0) ? std::nullopt : std::optional(xieite::geometry::Point(linearShape.start.x - linearShape.start.y * (linearShape.end.x - linearShape.start.x) / (linearShape.end.y - linearShape.start.y), 0.0));
	}
}
