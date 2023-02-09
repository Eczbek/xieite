#pragma once
#include <xieite/geometry/Polygon.hpp>
#include <xieite/geometry/Segment.hpp>
#include <xieite/geometry/getLength.hpp>
#include <xieite/geometry/getSides.hpp>

namespace xieite::geometry {
	[[nodiscard]]
	constexpr long double getPerimeter(const xieite::geometry::Polygon& polygon) noexcept {
		long double perimeter = 0;
		for (const xieite::geometry::Segment& side : xieite::geometry::getSides(polygon))
			perimeter += xieite::geometry::getLength(side);
		return perimeter;
	}
}
