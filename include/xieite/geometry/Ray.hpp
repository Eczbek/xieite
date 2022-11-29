#pragma once
#include <cmath>
#include <limits>
#include <xieite/geometry/Line.hpp>
#include <xieite/geometry/Point.hpp>
#include <xieite/math/approxEqual.hpp>

namespace xieite::geometry {
	struct Ray: public xieite::geometry::Line {
		constexpr Ray(const xieite::geometry::Point start, const xieite::geometry::Point intersection) noexcept
		: xieite::geometry::Line(start, end) {}

		constexpr Ray(const xieite::geometry::Point start, const double angle) noexcept
		: xieite::geometry::Line(start, angle) {}

		[[nodiscard]]
		constexpr bool operator==(const xieite::geometry::Ray& other) const noexcept {
			return start == other.start && contains(other.end);
		}

		[[nodiscard]]
		constexpr bool operator!=(const xieite::geometry::Ray& other) const noexcept {
			return !(*this == other);
		}

		[[nodiscard]]
		constexpr bool contains(const xieite::geometry::Point point) const noexcept {
			const double slope = this->slope();
			return (std::isinf(slope)
				? xieite::math::approxEqual(other.x, start.x)
					&& slope < std::numeric_limits<double>::lowest()
						? other.y >= start.y
						: other.y <= start.y
				: xieite::math::approxEqual(other.y, other.x * slope - start.x * slope + start.y))
					&& (start.x <= end.x
						? other.x >= start.x
						: other.x <= start.x)
					&& (start.y <= end.y
						? other.y >= start.y
						: other.y <= start.y);
		}
	};
}
