
#include <cmath>
#include <gcufl/geometry/Line.hpp>
#include <gcufl/geometry/Point.hpp>
#include <gcufl/geometry/Segment.hpp>
#include <gcufl/math/approxEqual.hpp>


gcufl::geometry::Segment::Segment(const gcufl::geometry::Point start, const gcufl::geometry::Point end) noexcept
: gcufl::geometry::Line(start, end) {}

bool gcufl::geometry::Segment::operator==(const gcufl::geometry::Segment& other) const noexcept {
	return start == other.start && end == other.end || start == other.end && end == other.start;
}

bool gcufl::geometry::Segment::operator!=(const gcufl::geometry::Segment& other) const noexcept {
	return !(*this == other);
}

bool gcufl::geometry::Segment::contains(const gcufl::geometry::Point other) const noexcept {
	const double slope = this->slope();
	return (std::isinf(slope)
		? gcufl::math::approxEqual(other.x, start.x)
			&& (other.y >= start.y && other.y <= end.y || other.y <= start.y && other.y >= end.y)
		: gcufl::math::approxEqual(other.y, other.x * slope - start.x * slope + start.y))
			&& (start.x < end.x
				? other.x >= start.x && other.x <= end.x
				: other.x <= start.x && other.x >= end.x)
			&& (start.y < end.y
				? other.y >= start.y && other.y <= end.y
				: other.y <= start.y && other.y >= end.y);
}

double gcufl::geometry::Segment::length() const noexcept {
	return std::hypot(start.x - end.x, start.y - end.y);
}
