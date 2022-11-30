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
	struct Circle: public xieite::geometry::Ellipse {
		constexpr Circle(const xieite::geometry::Point center, const long double radius) noexcept
		: xieite::geometry::Ellipse(center, xieite::geometry::Point(radius, radius)) {}

		[[nodiscard]]
		constexpr bool operator==(const xieite::geometry::Circle& other) const noexcept {
			return center == other.center && xieite::math::approxEqual(radius.x, other.radius.x);
		}

		[[nodiscard]]
		constexpr long double area() const noexcept override {
			return std::numbers::pi * radius.x * radius.x;
		}

		[[nodiscard]]
		constexpr xieite::geometry::Polygon boundingBox() const noexcept override {
			return xieite::geometry::Polygon(std::vector<xieite::geometry::Point> {
				xieite::geometry::Point(center.x - radius.x, center.y - radius.y),
				xieite::geometry::Point(center.x + radius.x, center.y - radius.y),
				xieite::geometry::Point(center.x + radius.x, center.y + radius.y),
				xieite::geometry::Point(center.x - radius.x, center.y + radius.y)
			});
		}

		[[nodiscard]]
		constexpr bool contains(const xieite::geometry::Point point) const noexcept override {
			return std::hypot(point.x - center.x, point.y - center.y) <= radius.x;
		}

		[[nodiscard]]
		constexpr long double perimeter() const noexcept override {
			return xieite::numbers::tau<long double> * radius.x;
		}
	};
}
