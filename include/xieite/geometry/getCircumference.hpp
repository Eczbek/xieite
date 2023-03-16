#pragma once
#include <cmath> // std::sqrt
#include <xieite/geometry/Circle.hpp>
#include <xieite/geometry/Ellipse.hpp>
#include <xieite/math/pi.hpp>
#include <xieite/math/tau.hpp>

namespace xieite::geometry {
	[[nodiscard]]
	constexpr double getCircumference(const xieite::geometry::Ellipse& ellipse) noexcept {
		return xieite::math::pi<double> * std::sqrt((ellipse.radii.x * ellipse.radii.x + ellipse.radii.y * ellipse.radii.y) * 2.0);
	}

	[[nodiscard]]
	constexpr double getCircumference(const xieite::geometry::Circle& circle) noexcept {
		return xieite::math::tau<double> * circle.radius;
	}
}
