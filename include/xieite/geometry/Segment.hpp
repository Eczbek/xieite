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
		constexpr bool contains(const xieite::geometry::Point point) const noexcept override {
			const long double slope = this->slope();
			return (std::isinf(slope)
				? xieite::math::approxEqual(point.x, start.x)
					&& (point.y >= start.y && point.y <= end.y || point.y <= start.y && point.y >= end.y)
				: xieite::math::approxEqual(point.y, point.x * slope - start.x * slope + start.y))
					&& (start.x < end.x
						? point.x >= start.x && point.x <= end.x
						: point.x <= start.x && point.x >= end.x)
					&& (start.y < end.y
						? point.y >= start.y && point.y <= end.y
						: point.y <= start.y && point.y >= end.y);
		}

		[[nodiscard]]
		constexpr long double length() const noexcept override {
			return std::hypot(start.x - end.x, start.y - end.y);
		}
	};
};
