#pragma once
#include <cmath> // std::hypot
#include <vector> // std::vector
#include <xieite/geometry/Ellipse.hpp> // xieite::geometry::Ellipse
#include <xieite/geometry/Point.hpp> // xieite::geometry::Point
#include <xieite/geometry/Polygon.hpp> // xieite::geometry::Polygon
#include <xieite/math/approxEqual.hpp> // xieite::math::approxEqual
#include <xieite/math/pi.hpp> // xieite::math::pi
#include <xieite/math/tau.hpp> // xieite::math::tau

namespace xieite::geometry {
	class Circle: public xieite::geometry::Ellipse {
	public:
		constexpr Circle(const xieite::geometry::Point center, const long double radius) noexcept
		: xieite::geometry::Ellipse(center, xieite::geometry::Point(radius, radius)) {}

		[[nodiscard]]
		constexpr bool operator==(const xieite::geometry::Circle& other) const noexcept {
			return center == other.center && xieite::math::approxEqual(radius.x, other.radius.x);
		}

		[[nodiscard]]
		constexpr long double area() const noexcept override {
			return xieite::math::pi<long double> * radius.x * radius.x;
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
			return xieite::math::tau<long double> * radius.x;
		}
	};
}
