#pragma once

#include <limits>
#include <xieite/concepts/LinearShape.hpp>
#include <xieite/geometry/Segment.hpp>
#include <xieite/geometry/getDistance.hpp>

namespace xieite::geometry {
	[[nodiscard]]
	constexpr double getLength(const xieite::geometry::Segment& segment) noexcept {
		return xieite::geometry::getDistance(segment.start, segment.end);
	}

	[[nodiscard]]
	constexpr double getLength(const xieite::concepts::LinearShape auto&) noexcept {
		return std::numeric_limits<double>::infinity();
	}
}
