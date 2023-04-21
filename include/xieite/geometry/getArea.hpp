#pragma once

#include <cmath>
#include <xieite/geometry/Circle.hpp>
#include <xieite/geometry/Ellipse.hpp>
#include <xieite/geometry/Polygon.hpp>
#include <xieite/geometry/Segment.hpp>
#include <xieite/geometry/getSides.hpp>
#include <xieite/math/pi.hpp>

namespace xieite::geometry {
	[[nodiscard]]
	constexpr double getArea(const xieite::geometry::Polygon& polygon) noexcept {
		double area = 0.0;
		for (const xieite::geometry::Segment& side : xieite::geometry::getSides(polygon)) {
			area += side.start.x * side.start.y - side.start.x * side.end.y;
		}
		return std::abs(area) / 2.0;
	}

	[[nodiscard]]
	constexpr double getArea(const xieite::geometry::Ellipse& ellipse) noexcept {
		return xieite::math::pi<double> * ellipse.radii.x * ellipse.radii.y;
	}

	[[nodiscard]]
	constexpr double getArea(const xieite::geometry::Circle& circle) noexcept {
		return xieite::math::pi<double> * circle.radius * circle.radius;
	}
}
