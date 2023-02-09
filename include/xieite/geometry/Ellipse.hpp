#pragma once
#include <xieite/geometry/Point.hpp>
#include <xieite/math/approximatelyEqual.hpp>

namespace xieite::geometry {
	struct Ellipse {
		xieite::geometry::Point center;
		xieite::geometry::Point radii;
		long double rotation;

		constexpr Ellipse(const xieite::geometry::Point center, const xieite::geometry::Point radii, const long double rotation = 0) noexcept
		: center(center), radii(radii), rotation(rotation) {}

		[[nodiscard]]
		constexpr bool operator==(const xieite::geometry::Ellipse& other) const noexcept {
			return (center == other.center) && (radii == other.radii) && xieite::math::approximatelyEqual(rotation, other.rotation);
		}
	};
}
