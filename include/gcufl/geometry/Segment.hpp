#pragma once

#include <cmath>
#include <gcufl/geometry/Line.hpp>
#include <gcufl/geometry/Point.hpp>
#include <gcufl/math/approxEqual.hpp>


namespace gcufl::geometry {
	struct Segment final
	: gcufl::geometry::Line {
		constexpr Segment(const gcufl::geometry::Point start, const gcufl::geometry::Point end) noexcept
		: gcufl::geometry::Line(start, end) {}

		constexpr bool operator==(const gcufl::geometry::Segment& other) const noexcept {
			return start == other.start && end == other.end || start == other.end && end == other.start;
		}

		constexpr bool operator!=(const gcufl::geometry::Segment& other) const noexcept {
			return !(*this == other);
		}

		constexpr bool contains(const gcufl::geometry::Point point) const noexcept {
			const double slope = this->slope();
			return (std::isinf(slope)
				? gcufl::math::approxEqual(other.x, start.x)
					&& (other.y >= start.y && other.y <= end.y || other.y <= start.y && other.y >= end.y)
				: gcufl::math::approxEqual(other.y, other.x * slope - start.x * slope + start.y))
					&& (start.x < end.x
						? other.x >= start.x && other.x <= end.x
						: other.x <= start.x && other.x >= end.x)
					&& (start.y < end.y
						? other.y >= start.y && other.y <= end.y
						: other.y <= start.y && other.y >= end.y);
		}

		constexpr double length() const noexcept {
			return std::hypot(start.x - end.x, start.y - end.y);
		}
	};
};
