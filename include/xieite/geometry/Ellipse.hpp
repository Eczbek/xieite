#pragma once

#include <xieite/geometry/Circle.hpp>
#include <xieite/geometry/Point.hpp>
#include <xieite/math/approximatelyEqual.hpp>

namespace xieite::geometry {
	struct Ellipse {
		xieite::geometry::Point center;
		xieite::geometry::Point radii;
		double rotation;

		constexpr Ellipse(const xieite::geometry::Point center, const xieite::geometry::Point radii, const double rotation = 0.0) noexcept
		: center(center), radii(radii), rotation(rotation) {}

		[[nodiscard]]
		constexpr bool operator==(const xieite::geometry::Ellipse& ellipse) const noexcept {
			return (this->center == ellipse.center) && (this->radii == ellipse.radii) && xieite::math::approximatelyEqual(this->rotation, ellipse.rotation);
		}

		[[nodisacrd]]
		constexpr bool operator==(const xieite::geometry::Circle& circle) const noexcept {
			return circle == *this;
		}
	};
}
