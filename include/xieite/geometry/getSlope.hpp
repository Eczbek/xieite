#pragma once
#include <concepts> // std::derived_from
#include <cmath> // std::abs
#include <xieite/geometry/LineLike.hpp>
#include <xieite/geometry/Point.hpp>

namespace xieite::geometry {
	[[nodiscard]]
	constexpr double getSlope(const xieite::geometry::Point point1, const xieite::geometry::Point point2) noexcept {
		return (point2.y - point1.y) / (point2.x - point1.x);
	}

	template<std::derived_from<xieite::geometry::LineLike> L>
	[[nodiscard]]
	constexpr double getSlope(const L& lineLike) noexcept {
		return xieite::geometry::getSlope(lineLike.start, lineLike.end);
	}
}
