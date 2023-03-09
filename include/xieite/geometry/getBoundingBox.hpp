#pragma once
#include <cmath> // std::cos, std::sin
#include <vector> // std::vector
#include <xieite/geometry/Circle.hpp>
#include <xieite/geometry/Ellipse.hpp>
#include <xieite/geometry/Point.hpp>
#include <xieite/geometry/Polygon.hpp>
#include <xieite/math/pi.hpp>
#include <xieite/math/squareRoot.hpp>

namespace xieite::geometry {
	[[nodiscard]]
	constexpr xieite::geometry::Polygon getBoundingBox(const xieite::geometry::Ellipse& ellipse) noexcept {
		const long double a = xieite::math::squareRoot(ellipse.radii.x * ellipse.radii.x * std::cos(ellipse.rotation) * std::cos(ellipse.rotation) + ellipse.radii.y * ellipse.radii.y * std::cos(ellipse.rotation + xieite::math::pi<long double> / 2) * std::cos(ellipse.rotation + xieite::math::pi<long double> / 2));
		const long double b = xieite::math::squareRoot(ellipse.radii.x * ellipse.radii.x * std::sin(ellipse.rotation) * std::sin(ellipse.rotation) + ellipse.radii.y * ellipse.radii.y * std::sin(ellipse.rotation + xieite::math::pi<long double> / 2) * std::sin(ellipse.rotation + xieite::math::pi<long double> / 2));
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
