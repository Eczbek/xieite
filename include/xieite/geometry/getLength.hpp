#pragma once
#include <limits> // std::numeric_limits
#include <xieite/geometry/Line.hpp>
#include <xieite/geometry/Ray.hpp>
#include <xieite/geometry/Segment.hpp>
#include <xieite/geometry/getDistance.hpp>

namespace xieite::geometry {
	[[nodiscard]]
	constexpr double getLength(const xieite::geometry::Line&) noexcept {
		return std::numeric_limits<double>::infinity();
	}

	[[nodiscard]]
	constexpr double getLength(const xieite::geometry::Ray&) noexcept {
		return std::numeric_limits<double>::infinity();
	}

	[[nodiscard]]
	constexpr double getLength(const xieite::geometry::Segment& segment) noexcept {
		return xieite::geometry::getDistance(segment.start, segment.end);
	}
}
