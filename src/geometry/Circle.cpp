
#include <cmath>
#include <gcufl/geometry/Ellipse.hpp>
#include <gcufl/geometry/Circle.hpp>
#include <gcufl/geometry/Point.hpp>
#include <gcufl/geometry/Polygon.hpp>
#include <gcufl/math/approxEqual.hpp>
#include <numbers>
#include <vector>


gcufl::geometry::Circle::Circle(const gcufl::geometry::Point center, const double radius) noexcept
: gcufl::geometry::Ellipse(center, gcufl::geometry::Point(radius, radius)) {}

bool gcufl::geometry::Circle::operator==(const gcufl::geometry::Circle& other) const noexcept {
	return center == other.center && gcufl::math::approxEqual(radius.x, other.radius.x);
}

bool gcufl::geometry::Circle::operator!=(const gcufl::geometry::Circle& other) const noexcept {
	return !(*this == other);
}

double gcufl::geometry::Circle::area() const noexcept {
	return std::numbers::pi_v<double> * radius.x * radius.x;
}

gcufl::geometry::Polygon gcufl::geometry::Circle::boundingBox() const noexcept {
	return gcufl::geometry::Polygon(std::vector<gcufl::geometry::Point> {
		gcufl::geometry::Point(center.x - radius.x, center.y - radius.y),
		gcufl::geometry::Point(center.x + radius.x, center.y - radius.y),
		gcufl::geometry::Point(center.x + radius.x, center.y + radius.y),
		gcufl::geometry::Point(center.x - radius.x, center.y + radius.y)
	});
}

bool gcufl::geometry::Circle::contains(const gcufl::geometry::Point point) const noexcept {
	return std::hypot(point.x - center.x, point.y - center.y) <= radius.x;
}

double gcufl::geometry::Circle::perimeter() const noexcept {
	return 2 * std::numbers::pi_v<double> * radius.x;
}
