
#include <cmath>
#include <gcufl/geometry/Line.hpp>
#include <gcufl/geometry/Point.hpp>
#include <gcufl/geometry/Ray.hpp>
#include <gcufl/math/approxEqual.hpp>
#include <limits>


gcufl::geometry::Ray::Ray(const gcufl::geometry::Point start, const gcufl::geometry::Point end) noexcept
: gcufl::geometry::Line(start, end) {}

gcufl::geometry::Ray::Ray(const gcufl::geometry::Point start, const double angle) noexcept
: gcufl::geometry::Line(start, angle) {}

bool gcufl::geometry::Ray::operator==(const gcufl::geometry::Ray& other) const noexcept {
	return start == other.start && contains(other.end);
}

bool gcufl::geometry::Ray::operator!=(const gcufl::geometry::Ray& other) const noexcept {
	return !(*this == other);
}

bool gcufl::geometry::Ray::contains(const gcufl::geometry::Point other) const noexcept {
	const double slope = this->slope();
	return (std::isinf(slope)
		? gcufl::math::approxEqual(other.x, start.x)
			&& slope < std::numeric_limits<double>::lowest()
				? other.y >= start.y
				: other.y <= start.y
		: gcufl::math::approxEqual(other.y, other.x * slope - start.x * slope + start.y))
			&& (start.x <= end.x
				? other.x >= start.x
				: other.x <= start.x)
			&& (start.y <= end.y
				? other.y >= start.y
				: other.y <= start.y);
}
