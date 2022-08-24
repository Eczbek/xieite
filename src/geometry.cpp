#include <limits>
#include <gcufl/algorithm.hpp>
#include <gcufl/geometry.hpp>
#include <gcufl/math.hpp>
#include <gcufl/number.hpp>


gcufl::geometry::Point::Point(const double x, const double y) noexcept
	: x(x), y(y)
{}

bool gcufl::geometry::Point::operator==(const gcufl::geometry::Point other) const noexcept {
	return gcufl::math::approxEqual(x, other.x) && gcufl::math::approxEqual(y, other.y);
}

bool gcufl::geometry::Point::operator!=(const gcufl::geometry::Point other) const noexcept {
	return !operator==(other);
}

gcufl::geometry::Point gcufl::geometry::Point::rotate(const double angle, const gcufl::geometry::Point pivot) const noexcept {
	return gcufl::geometry::Point(pivot.x + std::cos(angle) * (x - pivot.x) - std::sin(angle) * (y - pivot.y), pivot.y + std::cos(angle) * (y - pivot.y) + std::sin(angle) * (x - pivot.x));
}

gcufl::geometry::Line::Line(const gcufl::geometry::Point start, const gcufl::geometry::Point end) noexcept
	: start(start), end(end)
{}

gcufl::geometry::Line::Line(const gcufl::geometry::Point start, const double angle) noexcept
	: start(start)
{
	end = gcufl::math::approxEqual(std::fmod(angle + std::numbers::pi / 2, std::numbers::pi), 0.0)
		? gcufl::geometry::Point(start.x, start.y - 1)
		: gcufl::geometry::Point(start.x + 1, start.y + std::tan(angle));
}

bool gcufl::geometry::Line::operator==(const gcufl::geometry::Line& other) const noexcept {
	return slope() == other.slope() && contains(other.start);
}

bool gcufl::geometry::Line::operator!=(const gcufl::geometry::Line& other) const noexcept {
	return !operator==(other);
}

double gcufl::geometry::Line::slope() const noexcept {
	return std::fabs(start.y - end.y) / std::fabs(start.x - end.x);
}

double gcufl::geometry::Line::interceptX() const noexcept {
	return start.x - slope() * start.y;
}

double gcufl::geometry::Line::interceptY() const noexcept {
	return start.y - slope() * start.x;
}

double gcufl::geometry::Line::angle() const noexcept {
	return std::fmod(std::atan2(start.y - end.y, start.x - end.x) + gcufl::number::tau, std::numbers::pi);
}

std::optional<gcufl::geometry::Point> gcufl::geometry::Line::intersection(const gcufl::geometry::Line& other) const noexcept {
	const double a = (start.x - end.x) * (other.start.y - other.end.y) - (start.y - end.y) * (other.start.x - other.end.x);
	if (!gcufl::math::approxEqual(a, 0.0)) {
		const gcufl::geometry::Point intersection(((other.start.x - other.end.x) * (start.x * end.y - start.y * end.x) - (start.x - end.x) * (other.start.x * other.end.y - other.start.y * other.end.x)) / a, ((other.start.y - other.end.y) * (start.x * end.y - start.y * end.x) - (start.y - end.y) * (other.start.x * other.end.y - other.start.y * other.end.x)) / a);
		if (contains(intersection) && other.contains(intersection))
			return intersection;
	}
	return std::nullopt;
}

double gcufl::geometry::Line::length() const noexcept {
	return std::numeric_limits<double>::infinity();
}

bool gcufl::geometry::Line::contains(const gcufl::geometry::Point other) const noexcept {
	const double slope = this->slope();
	return std::isinf(slope)
		? gcufl::math::approxEqual(other.x, start.x)
		: gcufl::math::approxEqual(other.y, other.x * slope - start.x * slope + start.y);
}

gcufl::geometry::Line gcufl::geometry::Line::rotate(const double angle, const gcufl::geometry::Point pivot) {
	return gcufl::geometry::Line(start.rotate(angle, pivot), end.rotate(angle, pivot));
}

gcufl::geometry::Ray::Ray(const gcufl::geometry::Point start, const gcufl::geometry::Point end) noexcept
	: gcufl::geometry::Line(start, end)
{}

gcufl::geometry::Ray::Ray(const gcufl::geometry::Point start, const double angle) noexcept
	: gcufl::geometry::Line(start, angle)
{}

bool gcufl::geometry::Ray::operator==(const gcufl::geometry::Ray& other) const noexcept {
	return start == other.start && contains(other.end);
}

bool gcufl::geometry::Ray::operator!=(const gcufl::geometry::Ray& other) const noexcept {
	return !operator==(other);
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

gcufl::geometry::Segment::Segment(const gcufl::geometry::Point start, const gcufl::geometry::Point end) noexcept
	: gcufl::geometry::Line(start, end)
{}

bool gcufl::geometry::Segment::operator==(const gcufl::geometry::Segment& other) const noexcept {
	return start == other.start && end == other.end || start == other.end && end == other.start;
}

bool gcufl::geometry::Segment::operator!=(const gcufl::geometry::Segment& other) const noexcept {
	return !operator==(other);
}

double gcufl::geometry::Segment::length() const noexcept {
	return std::hypot(start.x - end.x, start.y - end.y);
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

gcufl::geometry::Polygon::Polygon(const std::vector<gcufl::geometry::Point>& points) noexcept
	: points(points)
{}

bool gcufl::geometry::Polygon::operator==(const gcufl::geometry::Polygon& other) const noexcept {
	return gcufl::algorithm::rotatedMatch(points.begin(), points.end(), other.points.begin(), other.points.end())
		|| gcufl::algorithm::rotatedMatch(points.rbegin(), points.rend(), other.points.begin(), other.points.end());
}

bool gcufl::geometry::Polygon::operator!=(const gcufl::geometry::Polygon& other) const noexcept {
	return !operator==(other);
}

double gcufl::geometry::Polygon::area() const noexcept {
	double area = 0;
	for (const gcufl::geometry::Segment& side: sides())
		area += side.start.x * side.end.y - side.start.y * side.start.x;
	return area / 2;
}

double gcufl::geometry::Polygon::perimeter() const noexcept {
	double perimeter = 0;
	for (const gcufl::geometry::Segment& side: sides())
		perimeter += side.length();
	return perimeter;
}

std::vector<gcufl::geometry::Segment> gcufl::geometry::Polygon::sides() const noexcept {
	std::vector<gcufl::geometry::Segment> sides;
	for (std::size_t i = 0; i < points.size(); ++i)
		sides.push_back(gcufl::geometry::Segment(points[i], points[(i + 1) % points.size()]));
	return sides;
}

bool gcufl::geometry::Polygon::contains(const gcufl::geometry::Point point) const noexcept {
	std::size_t intersections = 0;
	gcufl::geometry::Ray ray(point, 0);
	for (const gcufl::geometry::Segment& side: sides())
		intersections += ray.intersection(side).has_value();
	return intersections % 2;
}

gcufl::geometry::Polygon gcufl::geometry::Polygon::rotate(const double angle, const gcufl::geometry::Point pivot) const noexcept {
	std::vector<gcufl::geometry::Point> rotatedPoints = points;
	for (std::size_t i = 0; i < points.size(); ++i)
		rotatedPoints[i] = points[i].rotate(angle, pivot);
	return gcufl::geometry::Polygon(rotatedPoints);
}

gcufl::geometry::Ellipse::Ellipse(const gcufl::geometry::Point center, const gcufl::geometry::Point radius, const double rotation) noexcept
	: center(center), radius(radius), rotation(rotation)
{}

bool gcufl::geometry::Ellipse::operator==(const gcufl::geometry::Ellipse& other) const noexcept {
	return center == other.center && radius == other.radius && gcufl::math::approxEqual(std::fmod(rotation, std::numbers::pi), std::fmod(other.rotation, std::numbers::pi));
}

bool gcufl::geometry::Ellipse::operator!=(const gcufl::geometry::Ellipse& other) const noexcept {
	return !operator==(other);
}

double gcufl::geometry::Ellipse::area() const noexcept {
	return std::numbers::pi * radius.x * radius.y;
}

double gcufl::geometry::Ellipse::perimeter() const noexcept {
	return std::numbers::pi * std::sqrt(2 * (radius.x * radius.x + radius.y * radius.y));
}

bool gcufl::geometry::Ellipse::contains(const gcufl::geometry::Point point) const noexcept {
	const double a = std::cos(rotation) * (point.x - center.x) + std::sin(rotation) * (point.y - center.y);
	const double b = std::sin(rotation) * (point.x - center.x) - std::cos(rotation) * (point.y - center.y);
	return a * a / radius.x / radius.x + b * b / radius.y / radius.y <= 1;
}

std::vector<gcufl::geometry::Point> gcufl::geometry::Ellipse::intersections(const gcufl::geometry::Line& line) const noexcept {
	std::vector<gcufl::geometry::Point> intersections;
	const double a = radius.y * radius.y * line.end.x * line.end.x + radius.x * radius.x * line.end.y * line.end.y;
	const double b = radius.y * radius.y * line.start.x * line.end.x * 2 + radius.x * radius.x * line.start.y * line.end.y * 2;
	const double c = radius.y * radius.y * line.start.x * line.start.x + radius.x * radius.x * line.start.y * line.start.y - radius.x * radius.x * radius.y * radius.y;
	const double d = std::sqrt(b * b - 4 * a * c) / 2 / a;
	const double e = b * b - 4 * a * c;
	const bool f = gcufl::math::approxEqual(e, 0.0);
	if (e > 0 || f) {
		const gcufl::geometry::Point g(center.x + line.start.x + (d - b) * (line.end.x - line.start.x), center.y + line.start.y + (d + b) * (line.end.y - line.start.y));
		if (line.contains(g))
			intersections.push_back(g);
		if (e > 0 && !f) {
			const gcufl::geometry::Point h(center.x - line.start.x - (d - b) * (line.end.x - line.start.x), center.y - line.start.y - (d + b) * (line.end.y - line.start.y));
			if (line.contains(h))
				intersections.push_back(h);
		}
	}
	return intersections;
}

std::vector<gcufl::geometry::Point> gcufl::geometry::Ellipse::intersections(const gcufl::geometry::Ellipse& other) const noexcept {
	return {}; // TODO
}

gcufl::geometry::Ellipse gcufl::geometry::Ellipse::rotate(const double angle, const gcufl::geometry::Point pivot) const noexcept {
	return gcufl::geometry::Ellipse(center.rotate(angle, pivot), radius, std::fmod(rotation + angle, gcufl::number::tau));
}

gcufl::geometry::Polygon gcufl::geometry::Ellipse::boundingBox() const noexcept {
	const double a = std::sqrt(radius.x * radius.x * std::cos(rotation) * std::cos(rotation) + radius.y * radius.y * std::cos(rotation + std::numbers::pi / 2) * std::cos(rotation + std::numbers::pi / 2));
	const double b = std::sqrt(radius.x * radius.x * std::sin(rotation) * std::sin(rotation) + radius.y * radius.y * std::sin(rotation + std::numbers::pi / 2) * std::sin(rotation + std::numbers::pi / 2));
	return gcufl::geometry::Polygon(std::vector<gcufl::geometry::Point> {
		gcufl::geometry::Point(center.x - a, center.y - b),
		gcufl::geometry::Point(center.x + a, center.y - b),
		gcufl::geometry::Point(center.x + a, center.y + b),
		gcufl::geometry::Point(center.x - a, center.y + b)
	});
}

gcufl::geometry::Circle::Circle(const gcufl::geometry::Point center, const double radius) noexcept
	: gcufl::geometry::Ellipse(center, gcufl::geometry::Point(radius, radius))
{}

bool gcufl::geometry::Circle::operator==(const gcufl::geometry::Circle& other) const noexcept {
	return center == other.center && gcufl::math::approxEqual(radius.x, other.radius.x);
}

bool gcufl::geometry::Circle::operator!=(const gcufl::geometry::Circle& other) const noexcept {
	return !operator==(other);
}

double gcufl::geometry::Circle::area() const noexcept {
	return std::numbers::pi * radius.x * radius.x;
}

double gcufl::geometry::Circle::perimeter() const noexcept {
	return 2 * std::numbers::pi * radius.x;
}

bool gcufl::geometry::Circle::contains(const gcufl::geometry::Point point) const noexcept {
	return std::hypot(point.x - center.x, point.y - center.y) <= radius.x;
}

gcufl::geometry::Circle gcufl::geometry::Circle::rotate(const double angle, const gcufl::geometry::Point pivot) const noexcept {
	return gcufl::geometry::Circle(center.rotate(angle, pivot), radius.x);
}
