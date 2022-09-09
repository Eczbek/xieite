
#include <cmath>
#include <gcufl/geometry/Point.hpp>
#include <gcufl/math/approxEqual.hpp>


gcufl::geometry::Point::Point(const double x, const double y) noexcept
: x(x), y(y) {}

bool gcufl::geometry::Point::operator==(const gcufl::geometry::Point other) const noexcept {
	return gcufl::math::approxEqual(x, other.x) && gcufl::math::approxEqual(y, other.y);
}

bool gcufl::geometry::Point::operator!=(const gcufl::geometry::Point other) const noexcept {
	return !operator==(other);
}

gcufl::geometry::Point gcufl::geometry::Point::rotate(const double angle, const gcufl::geometry::Point pivot) const noexcept {
	return gcufl::geometry::Point(pivot.x + std::cos(angle) * (x - pivot.x) - std::sin(angle) * (y - pivot.y), pivot.y + std::cos(angle) * (y - pivot.y) + std::sin(angle) * (x - pivot.x));
}
