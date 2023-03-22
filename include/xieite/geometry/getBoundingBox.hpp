#pragma once

#include <cmath>
#include <vector>
#include <xieite/geometry/Circle.hpp>
#include <xieite/geometry/Ellipse.hpp>
#include <xieite/geometry/Point.hpp>
#include <xieite/geometry/Polygon.hpp>
#include <xieite/math/pi.hpp>

namespace xieite::geometry {
	[[nodiscard]]
	constexpr xieite::geometry::Polygon getBoundingBox(const xieite::geometry::Ellipse& ellipse) noexcept {
		const double a = std::sqrt(ellipse.radii.x * ellipse.radii.x * std::cos(ellipse.rotation) * std::cos(ellipse.rotation) + ellipse.radii.y * ellipse.radii.y * std::cos(ellipse.rotation + xieite::math::pi<double> / 2.0) * std::cos(ellipse.rotation + xieite::math::pi<double> / 2.0));
		const double b = std::sqrt(ellipse.radii.x * ellipse.radii.x * std::sin(ellipse.rotation) * std::sin(ellipse.rotation) + ellipse.radii.y * ellipse.radii.y * std::sin(ellipse.rotation + xieite::math::pi<double> / 2.0) * std::sin(ellipse.rotation + xieite::math::pi<double> / 2.0));
		return xieite::geometry::Polygon(std::vector<xieite::geometry::Point> {
			xieite::geometry::Point(ellipse.center.x - a, ellipse.center.y - b),
			xieite::geometry::Point(ellipse.center.x + a, ellipse.center.y - b),
			xieite::geometry::Point(ellipse.center.x + a, ellipse.center.y + b),
			xieite::geometry::Point(ellipse.center.x - a, ellipse.center.y + b)
		});
	}

	[[nodiscard]]
	constexpr xieite::geometry::Polygon getBoundingBox(const xieite::geometry::Circle& circle) noexcept {
		return xieite::geometry::Polygon(std::vector<xieite::geometry::Point> {
			xieite::geometry::Point(circle.center.x - circle.radius, circle.center.y - circle.radius),
			xieite::geometry::Point(circle.center.x + circle.radius, circle.center.y - circle.radius),
			xieite::geometry::Point(circle.center.x + circle.radius, circle.center.y + circle.radius),
			xieite::geometry::Point(circle.center.x - circle.radius, circle.center.y + circle.radius)
		});
	}
}
