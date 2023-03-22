#pragma once

#include <concepts>
#include <limits>
#include <xieite/geometry/LineLike.hpp>
#include <xieite/geometry/Segment.hpp>
#include <xieite/geometry/getDistance.hpp>

namespace xieite::geometry {
	[[nodiscard]]
	constexpr double getLength(const std::derived_from<xieite::geometry::LineLike> auto&) noexcept {
		return std::numeric_limits<double>::infinity();
	}

	[[nodiscard]]
	constexpr double getLength(const xieite::geometry::Segment& segment) noexcept {
		return xieite::geometry::getDistance(segment.start, segment.end);
	}
}
