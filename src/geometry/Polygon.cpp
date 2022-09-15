
#include <gcufl/algorithms/rotatedMatch.hpp>
#include <gcufl/geometry/Point.hpp>
#include <gcufl/geometry/Polygon.hpp>
#include <gcufl/geometry/Ray.hpp>
#include <gcufl/geometry/Segment.hpp>
#include <vector>


gcufl::geometry::Polygon::Polygon(const std::vector<gcufl::geometry::Point>& points) noexcept
: points(points) {}

bool gcufl::geometry::Polygon::operator==(const gcufl::geometry::Polygon& other) const noexcept {
	return gcufl::algorithms::rotatedMatch(points.begin(), points.end(), other.points.begin(), other.points.end())
		|| gcufl::algorithms::rotatedMatch(points.rbegin(), points.rend(), other.points.begin(), other.points.end());
}

bool gcufl::geometry::Polygon::operator!=(const gcufl::geometry::Polygon& other) const noexcept {
	return !(*this == other);
}

double gcufl::geometry::Polygon::area() const noexcept {
	double area = 0;
	for (const gcufl::geometry::Segment& side : sides())
		area += side.start.x * side.end.y - side.start.y * side.start.x;
	return area / 2;
}

bool gcufl::geometry::Polygon::contains(const gcufl::geometry::Point point) const noexcept {
	std::size_t intersections = 0;
	gcufl::geometry::Ray ray(point, 0);
	for (const gcufl::geometry::Segment& side : sides())
		intersections += ray.intersection(side).has_value();
	return intersections % 2;
}

double gcufl::geometry::Polygon::perimeter() const noexcept {
	double perimeter = 0;
	for (const gcufl::geometry::Segment& side : sides())
		perimeter += side.length();
	return perimeter;
}

gcufl::geometry::Polygon gcufl::geometry::Polygon::rotate(const double angle, const gcufl::geometry::Point pivot) const noexcept {
	std::vector<gcufl::geometry::Point> rotatedPoints = points;
	const std::size_t pointsSize = points.size();
	for (std::size_t i = 0; i < pointsSize; ++i)
		rotatedPoints[i] = points[i].rotate(angle, pivot);
	return gcufl::geometry::Polygon(rotatedPoints);
}

std::vector<gcufl::geometry::Segment> gcufl::geometry::Polygon::sides() const noexcept {
	std::vector<gcufl::geometry::Segment> sides;
	const std::size_t pointsSize = points.size();
	for (std::size_t i = 0; i < pointsSize; ++i)
		sides.push_back(gcufl::geometry::Segment(points[i], points[(i + 1) % pointsSize]));
	return sides;
}
