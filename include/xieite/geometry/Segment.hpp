#pragma once
#include <cmath>
#include <xieite/geometry/Line.hpp>
#include <xieite/geometry/Point.hpp>
#include <xieite/math/approxEqual.hpp>

namespace xieite::geometry {
	struct Segment: public xieite::geometry::Line {
		constexpr Segment(const xieite::geometry::Point start, const xieite::geometry::Point end) noexcept
		: xieite::geometry::Line(start, end) {}

		[[nodiscard]]
		constexpr bool operator==(const xieite::geometry::Segment& other) const noexcept {
			return start == other.start && end == other.end || start == other.end && end == other.start;
		}

		[[nodiscard]]
		constexpr bool contains(const xieite::geometry::Point point) const noexcept {
			const double slope = this->slope();
			return (std::isinf(slope)
				? xieite::math::approxEqual(other.x, start.x)
					&& (other.y >= start.y && other.y <= end.y || other.y <= start.y && other.y >= end.y)
				: xieite::math::approxEqual(other.y, other.x * slope - start.x * slope + start.y))
					&& (start.x < end.x
						? other.x >= start.x && other.x <= end.x
						: other.x <= start.x && other.x >= end.x)
					&& (start.y < end.y
						? other.y >= start.y && other.y <= end.y
						: other.y <= start.y && other.y >= end.y);
		}

		[[nodiscard]]
		constexpr double length() const noexcept {
			return std::hypot(start.x - end.x, start.y - end.y);
		}
	};
};
