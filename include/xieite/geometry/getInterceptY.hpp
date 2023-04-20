#pragma once

#include <cmath>
#include <optional>
#include <xieite/concepts/LinearShape.hpp>
#include <xieite/geometry/Point.hpp>
#include <xieite/geometry/getSlope.hpp>

namespace xieite::geometry {
	[[nodiscard]]
	constexpr std::optional<xieite::geometry::Point> getInterceptY(const xieite::concepts::LinearShape auto& linearShape) noexcept {
		return std::isinf(xieite::geometry::getSlope(linearShape)) ? std::nullopt : std::optional(xieite::geometry::Point(0.0, linearShape.start.y - linearShape.start.x * (linearShape.end.y - linearShape.start.y) / (linearShape.end.x - linearShape.start.x)));
	}
}
