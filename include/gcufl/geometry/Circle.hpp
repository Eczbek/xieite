#pragma once
#include <cmath>
#include <gcufl/geometry/Ellipse.hpp>
#include <gcufl/geometry/Point.hpp>
#include <gcufl/geometry/Polygon.hpp>
#include <gcufl/math/approxEqual.hpp>
#include <gcufl/numbers/tau.hpp>
#include <numbers>
#include <vector>

namespace gcufl::geometry {
	struct Circle final
	: gcufl::geometry::Ellipse {
		[[nodiscard]]
		constexpr Circle(const gcufl::geometry::Point center, const double radius) noexcept
		: gcufl::geometry::Ellipse(center, gcufl::geometry::Point(radius, radius)) {}

		[[nodiscard]]
		constexpr bool operator==(const gcufl::geometry::Circle& other) const noexcept {
			return center == other.center && gcufl::math::approxEqual(radius.x, other.radius.x);
		}

		[[nodiscard]]
		constexpr bool operator!=(const gcufl::geometry::Circle& other) const noexcept {
			return !(*this == other);
		}

		[[nodiscard]]
		constexpr double area() const noexcept {
			return std::numbers::pi * radius.x * radius.x;
		}

		[[nodiscard]]
		constexpr gcufl::geometry::Polygon boundingBox() const noexcept {
			return gcufl::geometry::Polygon(std::vector<gcufl::geometry::Point> {
				gcufl::geometry::Point(center.x - radius.x, center.y - radius.y),
				gcufl::geometry::Point(center.x + radius.x, center.y - radius.y),
				gcufl::geometry::Point(center.x + radius.x, center.y + radius.y),
				gcufl::geometry::Point(center.x - radius.x, center.y + radius.y)
			});
		}

		[[nodiscard]]
		constexpr bool contains(const gcufl::geometry::Point point) const noexcept {
			return std::hypot(point.x - center.x, point.y - center.y) <= radius.x;
		}

		[[nodiscard]]
		constexpr double perimeter() const noexcept {
			return gcufl::numbers::tau<double> * radius.x;
		}
	};
}
