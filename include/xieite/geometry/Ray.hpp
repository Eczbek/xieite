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
		constexpr bool contains(const xieite::geometry::Point point) const noexcept override {
			const double slope = this->slope();
			return (std::isinf(slope)
				? xieite::math::approxEqual(point.x, start.x)
					&& slope < std::numeric_limits<double>::lowest()
						? point.y >= start.y
						: point.y <= start.y
				: xieite::math::approxEqual(point.y, point.x * slope - start.x * slope + start.y))
					&& (start.x <= end.x
						? point.x >= start.x
						: point.x <= start.x)
					&& (start.y <= end.y
						? point.y >= start.y
						: point.y <= start.y);
		}
	};
}
