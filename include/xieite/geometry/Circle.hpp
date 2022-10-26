#pragma once
#include <cmath>
#include <numbers>
#include <vector>
#include <xieite/geometry/Ellipse.hpp>
#include <xieite/geometry/Point.hpp>
#include <xieite/geometry/Polygon.hpp>
#include <xieite/math/approxEqual.hpp>
#include <xieite/numbers/tau.hpp>

namespace xieite::geometry {
	struct Circle final
	: xieite::geometry::Ellipse {
		constexpr Circle(const xieite::geometry::Point center, const double radius) noexcept
		: xieite::geometry::Ellipse(center, xieite::geometry::Point(radius, radius)) {}

		[[nodiscard]]
		constexpr bool operator==(const xieite::geometry::Circle& other) const noexcept {
			return center == other.center && xieite::math::approxEqual(radius.x, other.radius.x);
		}

		[[nodiscard]]
		constexpr bool operator!=(const xieite::geometry::Circle& other) const noexcept {
			return !(*this == other);
		}

		[[nodiscard]]
		constexpr double area() const noexcept {
			return std::numbers::pi * radius.x * radius.x;
		}

		[[nodiscard]]
		constexpr xieite::geometry::Polygon boundingBox() const noexcept {
			return xieite::geometry::Polygon(std::vector<xieite::geometry::Point> {
				xieite::geometry::Point(center.x - radius.x, center.y - radius.y),
				xieite::geometry::Point(center.x + radius.x, center.y - radius.y),
				xieite::geometry::Point(center.x + radius.x, center.y + radius.y),
				xieite::geometry::Point(center.x - radius.x, center.y + radius.y)
			});
		}

		[[nodiscard]]
		constexpr bool contains(const xieite::geometry::Point point) const noexcept {
			return std::hypot(point.x - center.x, point.y - center.y) <= radius.x;
		}

		[[nodiscard]]
		constexpr double perimeter() const noexcept {
			return xieite::numbers::tau<double> * radius.x;
		}
	};
}
